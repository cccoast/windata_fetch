#include <string.h>
#include <vector>
#include <iostream>
#include <thread>
#include <boost/format.hpp>

#include "CTPConnector.hpp"
#include "StreamProcessor.hpp"
#include "../StreamManager/FutureStreamDump.hpp"
#include "../StreamManager/DataType.hpp"
#include "../ShareMemory/ShmPool.hpp"

#include "../../impl.h"

using namespace std;

CTPConnector::CTPConnector(string ip,
            int port,
            int broker_id,
            long long investor_id)
{
    //REAL ADDRESS
    sprintf(_frontAddr,"%s:%d",ip.c_str(),port);
    sprintf(_brokerID,"%d",broker_id);
    sprintf(_investorID,"%lld",investor_id);
    sprintf(_password,"%lld",investor_id );

    _pUserApi = CThostFtdcMdApi::CreateFtdcMdApi( "", true );
    _pUserApi->RegisterSpi(this);
};

struct callable {
    CThostFtdcMdApi* _pUserApi;
    callable(CThostFtdcMdApi* pUserApi) {
        _pUserApi = pUserApi;
    }
    void operator()() {
        _pUserApi->Init();
        _pUserApi->Join();
    }
};

int CTPConnector::connectToServer()
{
	_pUserApi->RegisterFront(_frontAddr);
    callable newProcess(_pUserApi);
    std::thread newThread(newProcess);
    newThread.detach();
    return 0;
};

int CTPConnector::subscribeInstruments(std::vector<std::string>& instrumentsList)
{
    vector<string>::iterator it = instrumentsList.begin();
    vector<string>::iterator lastIter = instrumentsList.end();
    char* charInstrumentList[1000];
    int i=0;
    while ( it != lastIter ) {
        charInstrumentList[i] = new InstrumentIDType;
        strcpy(charInstrumentList[i],it->c_str());
        ++it;
        ++i;
    };
    int iResult = _pUserApi->SubscribeMarketData(charInstrumentList, i);
    return iResult;
};
//int CTPConnector::startFetching(){};

int CTPConnector::stopFetching()
{
    _pUserApi->RegisterSpi(NULL);
    _pUserApi->Release();
    return 0;
};

void CTPConnector::OnRspError(CThostFtdcRspInfoField *pRspInfo,
                              int nRequestID, bool bIsLast)
{
    IsErrorRspInfo(pRspInfo);
}

void CTPConnector::OnFrontDisconnected(int nReason)
{
    impl::getInstance()->is_connected = false;
}

void CTPConnector::OnHeartBeatWarning(int nTimeLapse)
{
}

void CTPConnector::OnFrontConnected()
{
    printf("CTP Front Connection Established");
    ReqUserLogin();
}

void CTPConnector::ReqUserLogin()
{
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));

    strcpy(req.BrokerID, _brokerID);
    strcpy(req.UserID, _investorID);
    strcpy(req.Password, _password);

    _iRequestID = 0;

    int iResult = _pUserApi->ReqUserLogin(&req, ++_iRequestID);
    //Information Report
    if ( iResult == 0 ) {
        printf("[Successed] %s Send User log in request", getCurrentTime().c_str());
    } else {

    }

}

void CTPConnector::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	long date = atoi(_pUserApi->GetTradingDay());
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
        impl::getInstance()->is_connected = true;
    }
}

void CTPConnector::reqSubInstrumentsList(std::vector<std::string>& ins_lists)
{
    if(impl::getInstance()->is_connected){
        subscribeInstruments(ins_lists);
    }
}


void CTPConnector::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, 
									  CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    boost::format fmt("Subscribed %1%");
    fmt % pSpecificInstrument->InstrumentID;
    printf("%s", fmt.str().c_str());
}

void CTPConnector::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, 
	                                    CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    boost::format fmt("Unsubscribed %1%");
    fmt % pSpecificInstrument->InstrumentID;
    printf("%s",fmt.str().c_str());
}

void CTPConnector::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
    FutureStreamDump* newStream = new FutureStreamDump(pDepthMarketData);
    StreamProcessor newProcess(newStream, ShmPool::getMainShm(),ShmPool::getMainNoStructShm());
    newProcess();
    delete newStream;
}

bool CTPConnector::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    return bResult;
}
