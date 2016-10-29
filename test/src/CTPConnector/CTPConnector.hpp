
#ifndef CTPCONNECT_H
#define CTPCONNECT_H 

#include "../ctpapi/ThostFtdcMdApi.h"
#include <vector>
#include <string>

class CTPConnector : public CThostFtdcMdSpi
{
private:
    char _frontAddr[100];
    TThostFtdcBrokerIDType   _brokerID;
    TThostFtdcInvestorIDType _investorID;
    TThostFtdcPasswordType   _password;
    CThostFtdcMdApi* _pUserApi;
    int _iRequestID;

private:
    CTPConnector();
public:
    static CTPConnector* CreateCTPConnector() {
        static CTPConnector* staticConnector = new CTPConnector();
        return staticConnector;
    };
    int connectToServer();
    int subscribeInstruments(std::vector<std::string>& instrumentsList);
    int stopFetching();
    void reqSubInstrumentsList(std::vector<std::string>& ins_list);
public:
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo,
                            int nRequestID, bool bIsLast);
	virtual void OnFrontDisconnected(int nReason);
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void OnFrontConnected();
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast);
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                                    CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast);
    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast);
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

private:
    void ReqUserLogin();
    bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);

};

#endif
