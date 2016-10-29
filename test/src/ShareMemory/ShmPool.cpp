#include "ShmPool.hpp"

#include "WinShmInclude/SharedMemory/IndicatorNameDef.hpp"
#include "WinShmInclude/SharedMemory/Shm.hpp"

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

ShmPool* ShmPool::_sPoolInstance = new ShmPool();
Shm * ShmPool::_mainShm = NULL;
NoStructShm* ShmPool::_mainNoStructShm = NULL;

ShmPool::ShmPool()
{}

void ShmPool::Init()
{
    vector<string> shms;
    shms.push_back(string("0x0000001"));
    for (auto &id: shms) {
        Shm* newShm = new Shm(id);
        ShmPointer testPointer( newShm );
        _sPoolInstance->_shmList.push_back(testPointer);
		if (_mainShm == NULL)
		{
			_mainShm = newShm;
		}
    }

    vector<string> no_struct_id_list;
    no_struct_id_list.push_back("0x00000002");
    for (auto &id : no_struct_id_list) {
        NoStructShm* newNoSturctShm = new NoStructShm(id, STREAM_TYPE_CONFIG);
        NoStructShmPointer testPointer(newNoSturctShm);
        _sPoolInstance->_noStructShmList.push_back(testPointer);
        if (_mainNoStructShm== NULL)
        {
            _mainNoStructShm = newNoSturctShm;
        }
    }

}

ShmPool::ShmPointer ShmPool::getShm(size_t infoType)
{
    return _sPoolInstance->_shmList[0];
}


