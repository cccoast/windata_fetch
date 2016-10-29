
#ifndef STREAM_PROCESSOR_H
#define STREAM_PROCESSOR_H

#include "../StreamManager/StreamDump.hpp"
#include <iostream>
#include <memory>
#include "WinShmInclude/SharedMemory/Shm.hpp"
#include "WinShmInclude/SharedMemory/ShmHeader.hpp"
#include "WinShmInclude/SharedMemory/NoStructShm/NoStructShm.hpp"
#include "WinShmInclude/SharedMemory/NoStructShm/StructDef.hpp"
#include "WinShmInclude/SharedMemory/indIndex.h"

class StreamProcessor
{
private:
    StreamDump* _stream;
    Shm* _shm;
	NoStructShm* _nstruct_shm;
	const ShmHeader* _shm_header;
	MilliSec2Spot* milliSec2spot;
    int streamPosOffset;
    long _streamInstrumentID;
	long _insIndex;
	long new_fill_spot;
	long new_begin_millsec;
    //Get the arrangement of the coming instrument in the share memory
    long getInstrumentOrder();

    //Convert the real time into spot position in the share memory
    long getTimeLinePosition(long);
	long getTimeLinePosition2(long);

    //dump data from stream to the right address in the share memory
    bool dumpDataToShm(long timelinePosition);
	bool backfill(long timelinePosition);
public:

    //Constructor: Holding two pointer to StreamDump and Shm
    StreamProcessor(StreamDump* streamItem, Shm* shm, NoStructShm * nstruct_shm) {
        _stream = streamItem;
        _shm = shm;
		_nstruct_shm = nstruct_shm;
		milliSec2spot = (MilliSec2Spot *)nstruct_shm->getStruct(INFO_ID_MILLI2SPOT);

		_shm_header = shm->getHeader();
		if (new_begin_millsec < 0)
			new_begin_millsec = _shm_header->beginMillisecInDay;
		if (new_fill_spot < 0)
			new_fill_spot = 0;	
    };

    //Thread Function: called by boost::thread
    void operator()();
};
#endif
