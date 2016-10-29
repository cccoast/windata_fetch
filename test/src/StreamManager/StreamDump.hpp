
#ifndef STREAM_DUMP_H
#define STREAM_DUMP_H
#include <string>
#include <string.h>
#include <stdio.h>
//#include <map>
#include <boost/unordered_map.hpp>
#include "DataType.hpp"

class StreamDump
{
public:
    struct PureBytes {
        PureBytes(size_t sz, void* bf) {
            size = sz;
            buffer = bf;
        };
        PureBytes() {
            size = 8;
            buffer = NULL;
        };
        PureBytes(const StreamDump::PureBytes& ref) {
            size = ref.size;
            buffer = ref.buffer;
        };
        size_t size;
        void* buffer;
    };
    //enum StreamType{FUTURE=0,STOCK=1};
protected:
    //Identification of Stream Type
    StreamInfoType _infoType;
    std::string _instrumentID;
    long _serverTime;
    long _localTime;
    PureBytes _indicatorsPointerMap[256];
public:
    StreamDump(StreamInfoType infoType)
        :_infoType(infoType) {};
    virtual int getInfoType() {
        return _infoType;
    };
    virtual std::string getInstrumentID() {
        return _instrumentID;
    };
    virtual WholeTimeType getServerTime() {
        return _serverTime;
    };
    virtual WholeTimeType getLocalTime() {
        return _localTime;
    };
    virtual std::string getString() = 0;
    virtual PureBytes getBytes() = 0;
    virtual void* getValue(long tag, size_t reqSize) = 0;
    virtual ~StreamDump()
    {
        //delete[] _instrumentID;
    };
};

#endif
