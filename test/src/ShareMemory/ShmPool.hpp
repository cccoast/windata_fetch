
#ifndef _SHM_POOL_H_
#define _SHM_POOL_H_

#include "WinShmInclude/SharedMemory/Shm.hpp"
#include "WinShmInclude/SharedMemory/NoStructShm/NoStructShm.hpp"
#include <vector>
#include <memory>

class ShmPool
{
public:
    typedef std::shared_ptr<Shm> ShmPointer;
    typedef std::shared_ptr<NoStructShm> NoStructShmPointer;
    static void Init();
    static void CleanUp() {
        delete _sPoolInstance;
    };
    static Shm* _mainShm;
    static NoStructShm* _mainNoStructShm;
    static ShmPointer getShm(size_t infoType);
    static inline Shm* getMainShm() { return _mainShm;}
    static inline NoStructShm* getMainNoStructShm() { return _mainNoStructShm; }
private:
    //static int abc;
    std::vector<ShmPointer> _shmList;
    std::vector<NoStructShmPointer> _noStructShmList;
    static ShmPool* _sPoolInstance;
    ShmPool();
    ~ShmPool() {};
};

#endif
