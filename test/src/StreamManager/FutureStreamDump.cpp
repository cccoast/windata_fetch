#include "FutureStreamDump.hpp"
#include <string.h>
#include <time.h>
#include <chrono>

#include <boost/format.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "DataType.hpp"
#include "WinShmInclude/Util/timeUtil.h"
#include "WinShmInclude/Util/utils.h"
#include "WinShmInclude/misc.h"
#include "WinShmInclude/SharedMemory/IndicatorNameDef.hpp"

FutureStreamDump::FutureStreamDump(CThostFtdcDepthMarketDataField* field)
    :StreamDump(STREAMTYPE_FUTURE)
{ 
    _innerInfo.LastPrice = field->LastPrice;
    _indicatorsPointerMap[0] = PureBytes(sizeof(PriceType), &_innerInfo.LastPrice);

    _innerInfo.Volume    = field->Volume;
    _indicatorsPointerMap[1] = PureBytes(sizeof(VolumeType), &_innerInfo.Volume);

    _innerInfo.PreClosePrice = field->PreClosePrice;
    _indicatorsPointerMap[2] = PureBytes(sizeof(PriceType), &_innerInfo.PreClosePrice);

    _innerInfo.OpenPrice = field->OpenPrice;
    _indicatorsPointerMap[3] = PureBytes(sizeof(PriceType), &_innerInfo.OpenPrice);

    _innerInfo.AskPrice1 = field->AskPrice1;
    _indicatorsPointerMap[4] = PureBytes(sizeof(PriceType), &_innerInfo.AskPrice1);

    _innerInfo.AskVolume1 = field->AskVolume1;
    _indicatorsPointerMap[5] = PureBytes(sizeof(VolumeType), &_innerInfo.AskVolume1);

    _innerInfo.BidPrice1 = field->BidPrice1;
    _indicatorsPointerMap[6] = PureBytes(sizeof(PriceType), &_innerInfo.BidPrice1);

    _innerInfo.BidVolume1 = field->BidVolume1;
    _indicatorsPointerMap[7] = PureBytes(sizeof(VolumeType), &_innerInfo.BidVolume1);

    _innerInfo.HighestPrice = field->HighestPrice;
    _indicatorsPointerMap[8] = PureBytes(sizeof(PriceType), &_innerInfo.HighestPrice);

    _innerInfo.LowestPrice = field->LowestPrice;
    _indicatorsPointerMap[9] = PureBytes(sizeof(PriceType), &_innerInfo.LowestPrice);

    _innerInfo.LowerLimitPrice = field->LowerLimitPrice;
    _indicatorsPointerMap[10] = PureBytes(sizeof(PriceType), &_innerInfo.LowerLimitPrice);

    _innerInfo.UpperLimitPrice = field->UpperLimitPrice;
    _indicatorsPointerMap[11] = PureBytes(sizeof(PriceType), &_innerInfo.UpperLimitPrice);

    _innerInfo.ClosePrice = field->ClosePrice;
    _indicatorsPointerMap[12] = PureBytes(sizeof(PriceType), &_innerInfo.ClosePrice);

    _innerInfo.OpenInterest = field->OpenInterest;
    _indicatorsPointerMap[13] = PureBytes(sizeof(VolumeType), &_innerInfo.OpenInterest);

    _innerInfo.PreOpenInterest = field->PreOpenInterest;
    _indicatorsPointerMap[14] = PureBytes(sizeof(VolumeType), &_innerInfo.PreOpenInterest);

    _innerInfo.PreDelta = field->PreDelta;
    _indicatorsPointerMap[15] = PureBytes(sizeof(RatioType), &_innerInfo.PreDelta);

    _innerInfo.Turnover = field->Turnover;
    _indicatorsPointerMap[16] = PureBytes(sizeof(MoneyType), &_innerInfo.Turnover);

    _innerInfo.InstrumentID = field->InstrumentID;
    //_indicatorsPointerMap[17] = PureBytes(sizeof(InstrumentIDType), &_innerInfo.InstrumentID);

    //Extral Indicator
    _innerInfo.MidPrice = (_innerInfo.AskPrice1 + _innerInfo.BidPrice1)/2;
    _indicatorsPointerMap[40] = PureBytes(sizeof(PriceType), &_innerInfo.MidPrice);

    _innerInfo.WeightedPrice = ( _innerInfo.AskPrice1*_innerInfo.BidVolume1 + _innerInfo.BidPrice1*_innerInfo.AskVolume1 )
                            / (_innerInfo.AskVolume1 + _innerInfo.BidVolume1);
    _indicatorsPointerMap[41] = PureBytes(sizeof(PriceType), &_innerInfo.WeightedPrice);

	//add Trend/TradeType
	_indicatorsPointerMap[22] = PureBytes(sizeof(VolumeType), NULL);
	_indicatorsPointerMap[21] = PureBytes(sizeof(VolumeType), NULL);

    _instrumentID = field->InstrumentID;

	//cout << "Exchange Time = " << field->UpdateTime << ' ' << field->UpdateMillisec << endl;
    _serverTime = convertToServerTime(field->UpdateTime,field->UpdateMillisec);
    //boost::posix_time::ptime nowTime(boost::posix_time::microsec_clock::local_time());
    //boost::posix_time::time_duration duration = nowTime.time_of_day();
    _localTime = get_timespan_of_day<std::chrono::milliseconds>();
	//cout << "_serverTime = " <<_serverTime << "  _localTime = "<<' ' << _localTime << endl;
}

#ifndef XDD_VERSION
WholeTimeType FutureStreamDump::convertToServerTime(TimeType time, MillisecType millisec)
{
    boost::posix_time::time_duration duration( boost::posix_time::duration_from_string(time));
	int64_t total_milliseconds = duration.total_milliseconds();
	if (total_milliseconds > 3600 * 6 * 1000)
		return total_milliseconds + millisec;
	else
		return total_milliseconds + 3600 * 24 * 1000 + millisec;
}

WholeTimeType FutureStreamDump::getLocalTime()
{
    //cout << duration.hours() << duration.minutes() << duration.seconds() << duration.total_milliseconds()%1000 ;
	if (_localTime > 3600 * 6 * 1000)
		return _localTime;
	else {
		return _localTime + 3600 * 24 * 1000;
	}
}
#else
WholeTimeType FutureStreamDump::convertToServerTime(TimeType time, MillisecType millisec)
{
	long ts[5];
	int i = 0;
	char *tokenPtr = strtok(time, ":");
	while (tokenPtr != NULL) {
		ts[i++] = myatoi(tokenPtr);
		tokenPtr = strtok(NULL, ":");
	}
	//cout << ts[0] << ts[1] << ts[2] << endl;
	return (ts[0] * 3600 + ts[1] * 60 + ts[2]) * 1000 + millisec;
}

WholeTimeType FutureStreamDump::getLocalTime()
{
	while (_localTime > 3600 * 24 * 1000) {
		_localTime -= 3600 * 24 * 1000;
	}
	return _localTime;
}
#endif

std::string FutureStreamDump::getString()
{
    boost::format fmt("%1%,%2%,%3%,%4%,%5%,%6%,%7%,%8%,%9%,%10%,%11%,%12%,%13%,%14%,%15%,%16%,%17%,%18%,%19%,%20%,%21%");
    fmt % _innerInfo.InstrumentID;
    fmt % _serverTime;
    fmt % _localTime;
    fmt % _innerInfo.LastPrice;
    fmt % _innerInfo.Volume;
    fmt % _innerInfo.PreClosePrice;
    fmt % _innerInfo.OpenPrice;
    fmt % _innerInfo.AskPrice1;
    fmt % _innerInfo.AskVolume1;
    fmt % _innerInfo.BidPrice1;
    fmt % _innerInfo.BidVolume1;
    fmt % _innerInfo.HighestPrice;
    fmt % _innerInfo.LowestPrice;
    fmt % _innerInfo.LowerLimitPrice;
    fmt % _innerInfo.UpperLimitPrice;
    fmt % _innerInfo.ClosePrice;
    fmt % _innerInfo.OpenInterest;
    fmt % _innerInfo.PreOpenInterest;
    fmt % _innerInfo.PreDelta;
    fmt % _innerInfo.Turnover;
    fmt % _innerInfo.MidPrice;
    return fmt.str();
}
StreamDump::PureBytes FutureStreamDump::getBytes()
{
    PureBytes tempBytes(sizeof(InnerInfoField), (void*)&_innerInfo);
    //tempBytes.size = sizeof(InnerInfoField);
    //tempBytes.buffer = (void*)&_innerInfo;
    return tempBytes;
}
void* FutureStreamDump::getValue(long tag, size_t reqSize)
{
    //PureBytes newByte = _indicatorsPointerMap[tag];
    //TODO:  Fix  only for debug
    void* ref = _indicatorsPointerMap[tag].buffer;
	//cout << tag << endl;
    assert(reqSize == _indicatorsPointerMap[tag].size);
    return ref;
}
FutureStreamDump::~FutureStreamDump()
{
    //TODO: Delete this Debug Info
    //std::cout << "On Des" << std::endl;
}
