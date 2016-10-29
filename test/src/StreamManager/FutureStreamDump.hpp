
#ifndef STREAM_FUTURE_STREAM_DUMP_H
#define STREAM_FUTURE_STREAM_DUMP_H

#include "../ctpapi/ThostFtdcUserApiDataType.h"
#include "../ctpapi/ThostFtdcUserApiStruct.h"
#include "DataType.hpp"
#include "StreamDump.hpp"
#include "WinShmInclude/Util/timeUtil.h"

#include <iostream>

///CTP Adaptor
///Note:
///  This class is inherited from StreamDump to adapt the CTP.
///  Refer to StreamDump
///Sample usage:
///1.FutureStreamDump* newStream = new FutureStreamDump(ctpDepthInfo);
///2.newStream->getString(); (Save to file)
///3.newStream->getBytes(); (Save to binary file or memory)
class FutureStreamDump: public StreamDump
{
public:

    //The information we saved
    struct InnerInfoField {
        PriceType LastPrice;
        VolumeType Volume; 
        std::string InstrumentID;
        //TThostFtdcDateType	TradingDay;
        //TThostFtdcInstrumentIDType	InstrumentID;
        //TThostFtdcExchangeIDType	ExchangeID;
        //TThostFtdcExchangeInstIDType	ExchangeInstID;
        //TThostFtdcPriceType	LastPrice;
        PriceType	PreSettlementPrice;
        PriceType	PreClosePrice;
        VolumeType	PreOpenInterest;
        PriceType	OpenPrice;
        PriceType	HighestPrice;
        PriceType	LowestPrice;
        MoneyType	Turnover;
        VolumeType	OpenInterest;
        PriceType	ClosePrice;
        PriceType	SettlementPrice;
        PriceType	UpperLimitPrice;
        PriceType	LowerLimitPrice;
        RatioType	PreDelta;
        RatioType	CurrDelta;
        TimeType	UpdateTime;
        MillisecType UpdateMillisec;
        PriceType	BidPrice1;
        VolumeType	BidVolume1;
        PriceType	AskPrice1;
        VolumeType	AskVolume1;
        PriceType	BidPrice2;
        VolumeType	BidVolume2;
        PriceType	AskPrice2;
        VolumeType	AskVolume2;
        PriceType	BidPrice3;
        VolumeType	BidVolume3;
        PriceType	AskPrice3;
        VolumeType	AskVolume3;
        PriceType	BidPrice4;
        VolumeType	BidVolume4;
        PriceType	AskPrice4;
        VolumeType	AskVolume4;
        PriceType	BidPrice5;
        VolumeType	BidVolume5;
        PriceType	AskPrice5;
        VolumeType	AskVolume5;
        PriceType	AveragePrice;
        PriceType   MidPrice;
        PriceType   WeightedPrice;
    };

private:
    InnerInfoField _innerInfo;

private:
    //The WholeTimeType is total milliseconds since 00:00:00.000 to now
    //TimeType is char[] and MillisecType is int between 0~999
    WholeTimeType convertToServerTime(TimeType time, MillisecType millisec);

public:
    FutureStreamDump(CThostFtdcDepthMarketDataField* field);
    ~FutureStreamDump();
public:
    WholeTimeType getLocalTime();
    virtual void* getValue(long tag, size_t reqSize);
    virtual std::string getString();
    virtual PureBytes getBytes();
};
#endif
