#ifndef __FILL_FUNCTION_H__
#define __FILL_FUNCTION_H__

#include "WinShmInclude/SharedMemory/Shm.hpp"
#include "WinShmInclude/SharedMemory/ShmHeader.hpp"
#include "WinShmInclude/SharedMemory/IndicatorNameDef.hpp"
#include "WinShmInclude/Util/utils.h"
#include "WinShmInclude/misc.h"

#include <vector>
using namespace std;

#define ALMOST_ZERO        1e-5
#define EPSILON            ALMOST_ZERO
#define INFINITE_V         1e10

struct parameters {

	long insIndex;
	long data_position;

    parameters(): insIndex(0), data_position(0) {}
    parameters(long _insIndex, long _data_position) :insIndex(_insIndex), data_position(_data_position) {}
};

class Fill_Base {
protected:
	Shm* _shm;
	bool flag;
public:
	bool getFlag() { return flag; }
    Fill_Base() :_shm(NULL),flag(true){}
    Fill_Base(Shm* shm) : _shm(shm){}
    virtual ~Fill_Base() {}
    virtual bool operator() (parameters* _params) { return false; }
};

class Fill_Trend:public Fill_Base{
	long trend_index;
	long price_index;
public:
	Fill_Trend() :Fill_Base() {}
	Fill_Trend(Shm* shm):Fill_Base(shm) {
		trend_index = _shm->id2index_ind(INDICATORID_TICK_TREND);
		price_index = _shm->id2index_ind(INDICATORID_LAST_PRICE);
		if (trend_index < 0) {
			set_console_red();
			cout << "[warning] Missing Indicator Trend!" << endl;
			set_console_normal();
			flag = false;
		}
		else {
			set_console_red();
			cout << "[Will Fill] Indicator Trend!" << endl;
			set_console_normal();
		}
	}
	bool operator()(parameters* _params) {
		if (_params && _params->data_position > 0) {
			double *price = (double *)_shm->fetch(8, price_index, _params->insIndex, _params->data_position);
			double diff = *price - *(price - 1);
			long trend_type = TREND_TYPE_NAN;
			if ( !notFF(&diff, sizeof(double)) ) {
				trend_type = TREND_TYPE_NAN;
			}
			else if (diff > ALMOST_ZERO) {
				trend_type = TREND_TYPE_BUY;
			}
			else if (diff < ALMOST_ZERO) {
				trend_type = TREND_TYPE_SELL;
			}
			//cout << "trend_type" << trend_type << endl;
			return _shm->dump(&trend_type, sizeof(long), trend_index, _params->insIndex, _params->data_position);
		}
		else return false;
	}
};

class Fill_MidPrice :public Fill_Base {
	long mid_price_index;
	long bid_price_index;
	long ask_price_index;
public:
	Fill_MidPrice():Fill_Base() {}
	Fill_MidPrice(Shm* shm) :Fill_Base(shm) {
		mid_price_index = _shm->id2index_ind(INDICATORID_MID_PRICE);
		ask_price_index = _shm->id2index_ind(INDICATORID_ASK_PRICE_1);
		bid_price_index = _shm->id2index_ind(INDICATORID_BID_PRICE_1);
		if (mid_price_index < 0) {
			set_console_red();
			cout << "[warning] Missing Indicator MidPrice!" << endl;
			set_console_normal();
			flag = false;
		}
		else {
			set_console_red();
			cout << "[Will Fill] Indicator MidPrice!" << endl;
			set_console_normal();
		}
	}
	bool operator()(parameters* _params) {
		if (_params && _params->data_position > 0) {
			double *bid_price = (double *)_shm->fetch(8, bid_price_index, _params->insIndex, _params->data_position);
			double *ask_price = (double *)_shm->fetch(8, ask_price_index, _params->insIndex, _params->data_position);
			double mid_price = (*ask_price + *bid_price)/2;
			if (notFF(&mid_price, sizeof(double))) {
				//cout << "MidPrice = " << mid_price << endl;
				return _shm->dump(&mid_price, sizeof(double), mid_price_index, _params->insIndex, _params->data_position);
			}
			else return false;
		}
		else return false;
	}
};

class Fill_TradeType :public Fill_Base {
	long tradeTypeIndex;
	long openInterestIndex;
	long lastPriceIndex;
public:
	Fill_TradeType() :Fill_Base() {}
	Fill_TradeType(Shm* shm) :Fill_Base(shm) {
		tradeTypeIndex = _shm->id2index_ind(INDICATORID_TRADE_TYPE);
		openInterestIndex = _shm->id2index_ind(INDICATORID_OPEN_INTEREST);
		lastPriceIndex = _shm->id2index_ind(INDICATORID_LAST_PRICE);
		if (tradeTypeIndex < 0 || openInterestIndex < 0) {
			set_console_red();
			cout << "[warning] Missing Indicator TradeType!" << endl;
			set_console_normal();
			flag = false;
		}
		else {
			set_console_red();
			cout << "[Will Fill] Indicator TradeType!" << endl;
			set_console_normal();
		}
	}
	bool operator()(parameters* _params) {

		if (_params && _params->data_position > 0) {
			long tradeType = TRADE_TYPE_NAN;
			
			long* openInterCur = (long *)_shm->fetch(4, openInterestIndex, _params->insIndex, _params->data_position);
			long openInterDiff = *openInterCur - *(openInterCur - 1);
			
			double* priceCurr = (double *)_shm->fetch(8, lastPriceIndex, _params->insIndex, _params->data_position);
			double priceDiff = *priceCurr - *(priceCurr - 1);

			if (openInterDiff > ALMOST_ZERO) {
				if (priceDiff > ALMOST_ZERO) {
					tradeType = TRADE_TYPE_LONG_OPEN;
				}
				else if (priceDiff < -ALMOST_ZERO) {
					tradeType = TRADE_TYPE_SHORT_OPEN;
				}
				else {
					tradeType = TRADE_TYPE_BOTH_OPEN;
				}
			}
			else if (openInterDiff < -ALMOST_ZERO) {
				if (priceDiff > ALMOST_ZERO) {
					tradeType = TRADE_TYPE_LONG_CLOSE;
				}
				else if (priceDiff < -ALMOST_ZERO) {
					tradeType = TRADE_TYPE_SHORT_CLOSE;
				}
				else {
					tradeType = TRADE_TYPE_BOTH_CLOSE;
				}
			}
			else {
				if (priceDiff > ALMOST_ZERO) {
					tradeType = TRADE_TYPE_LONG_SWITCH;
				}
				else if (priceDiff < -ALMOST_ZERO) {
					tradeType = TRADE_TYPE_SHORT_SWITCH;
				}
				else {
					tradeType = TRADE_TYPE_LOCK;
				}
			}
			return _shm->dump(&tradeType, sizeof(long), tradeTypeIndex, _params->insIndex, _params->data_position);
		}
		else return false;
	}
};

class FillFunction {
private:
	static FillFunction* _instance;
public:
	vector<Fill_Base *> fill_function_list;
	inline static FillFunction* get_instance() {
		return _instance;
	}
	void Init(Shm* shm) {
		Fill_TradeType* _fill_trade_type = new Fill_TradeType(shm);

		if (_fill_trade_type->getFlag())
			fill_function_list.push_back(_fill_trade_type);
		else
			delete _fill_trade_type;
	}
	void Release() {
		for (Fill_Base* _fill_func : fill_function_list) {
			delete _fill_func;
		}
	}
};

#endif
