#include "StreamProcessor.hpp"
#include "WinShmInclude/Util/utils.h"
#include "WinShmInclude/SharedMemory/indIndex.h"
#include "../FillFunction/fillFunction.h"
#include "../../impl.h"

extern int fetcher_first_time;
extern int fetcher_last_time;

long StreamProcessor::getInstrumentOrder()
{
    auto pairs = impl::getInstance()->ins_inds.ins_pair;
    auto iter = pairs.find(_stream->getInstrumentID());
    if ( iter == pairs.end() ) {
        _streamInstrumentID = -1;
        return -1;
    } else {
        _streamInstrumentID = iter->second;
        return _shm->id2index_ins(_streamInstrumentID);
    }
}

#ifndef XDD_VERSION
long StreamProcessor::getTimeLinePosition(long time_point) {
	return _shm->getCurDateIndex() * _shm_header->spotsCountPerDay +
		(time_point - this->new_begin_millsec) / _shm_header->spotsInterval
		 + this->new_fill_spot;
}
#else
long StreamProcessor::getTimeLinePosition(long time_point) {
	return _shm->getCurDateIndex() * _shm_header->spotsCountPerDay + milliSec2spot->millisec2spot(time_point);
}
#endif

long StreamProcessor::getTimeLinePosition2(long time_point) {
	return _shm->getCurDateIndex() * _shm_header->spotsCountPerDay + milliSec2spot->millisec2spot(time_point);
}

void StreamProcessor::operator()()
{
    //Put the stream to the share memory
    //Only if we can put the data into share memory successfully can we publish it
    long serverTime = _stream->getServerTime();
	long timelinePosition = getTimeLinePosition(serverTime);
	//long timelinePosition2 = getTimeLinePosition2(serverTime);
	cout << "serverTime = " << serverTime << " timelinePosition = " << timelinePosition
	//	 << "timelinePosition2 = " << timelinePosition2 
		 << endl;
	long local_time = _stream->getLocalTime();

	//if (abs(serverTime - local_time) > 300000) {
	//	zlog_notice(LogManager::getSysLogHandler(), "ServerTime - LocalTime > 300000 MilliSec");
	//	return;
	//}
    long first_time =  fetcher_first_time;
    long last_time = fetcher_last_time;
	
    if ( (first_time > 0 && last_time > 0) )
    {
        if( (first_time < last_time) && (serverTime < first_time || serverTime > last_time) ) {
            cout << first_time << ' ' << last_time << endl;
            printf("ServerTime out of boundry");
            return;
        }
        else if( (first_time > last_time) && (serverTime < first_time && serverTime > last_time) )
        {
            cout << first_time << ' ' << last_time << endl;
            printf("ServerTime out of boundry");
            return;
        }
	}

    if ( dumpDataToShm(timelinePosition) )
    {
        long publishData[4];
        publishData[0] = _streamInstrumentID;
        publishData[1] = serverTime + 500 * streamPosOffset;
        publishData[2] = timelinePosition + streamPosOffset;
		publishData[3] = local_time;
        
        backfill(timelinePosition);

		parameters _para(_insIndex, publishData[2]);
		for (Fill_Base* _fill_function : FillFunction::get_instance()->fill_function_list) {
			(*_fill_function)(&_para);
		}

		///fill ClosePrice to Calculate PNL
		double *lastDayClosePrice = (double *)(_shm->fetch(8, g_lastPriceIndex, _insIndex, g_spotsCount - 1));
		double *CurPrice = (double *)(_shm->fetch(8, g_lastPriceIndex, _insIndex, timelinePosition));
		*lastDayClosePrice = *CurPrice;

        DataPublisher::getPubServer()->pubInfo(publishData,16);

		cout << publishData[0] << ' ' << publishData[1] << ' ' << publishData[2] << ' ' << publishData[3] << ' ' << endl;
    }
    else
    {
        //cout << "Dump Error" << endl;
    }
   
}

//dump data from stream to the right address in the share memory
bool StreamProcessor::dumpDataToShm(long timelinePosition)
{
    streamPosOffset = 0;
    long instrumentOrder = getInstrumentOrder();
    //Instrument are not arranged memory in share memory or ServerTime out of range
    if ( instrumentOrder<0 || 
		timelinePosition < _shm_header->spotsCount - _shm_header->spotsCountPerDay ||
		timelinePosition > _shm_header->spotsCount) {
        cout << "Shm does not have this data"<< instrumentOrder << " " << timelinePosition << endl;
        return false;
    }

	_insIndex = instrumentOrder;
    const ShmHeader* header = _shm->getHeader();
    long indicatorsCount = header->indicatorsCount;

    for ( int i=0; i<indicatorsCount; i++ ) {
        long newIndicators = header->indicatorsIDList[i];
        int size_indicator = header->indicatorsUnitSize[i];
		//cout << newIndicators << ' ' << size_indicator << endl;
        void* source = _stream->getValue(newIndicators,size_indicator);
        if ( source != NULL )
        {
            void* oldValue = _shm->fetch(size_indicator, i, instrumentOrder, timelinePosition);
            if ( isFF(oldValue, size_indicator)==0 )
            {
                _shm->dump(source,size_indicator, i, instrumentOrder, timelinePosition);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool StreamProcessor::backfill(long timelinePosition)
{
	long volumeIndex = g_volumeIndex;
	long basicOffset = _shm_header->spotsCount - _shm_header->spotsCountPerDay;
	long start = timelinePosition - 1;
	long* pvolume = (long*)_shm->fetch(4, volumeIndex, _insIndex, timelinePosition - 1);
	while ((start > basicOffset) && !notFF(pvolume, sizeof(long))) {
		start--;
		pvolume--;
	}
	if (start == timelinePosition - 1) {
		return true;
	}
	else {
		for (int indIndex = 0; indIndex < _shm_header->indicatorsCount; indIndex++) {
			long _size = _shm_header->indicatorsUnitSize[indIndex];
			void* src = _shm->fetch(_size, indIndex,_insIndex, start);
			//cout << "fill " << start << ' ' << timelinePosition << endl;
			if (notFF(src, _size)) {
				for (int ispot = start + 1; ispot < timelinePosition; ispot++) {
					_shm->dump(src, _size, indIndex, _insIndex, ispot);
				}
			}
		}
	}
	return true;
}
