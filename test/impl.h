#ifndef IMPL_H
#define IMPL_H

#include <string>
using namespace std;

typedef struct config config;
struct config{
    string ip;
    int port;
    int broker_id;
    long long investor_id;
};

class impl{
private:
    static impl* _instance;
    impl(){}
public:
    static impl* getInstance(){
        return _instance;
    }
    config account_config;
    int initConfig();
    int saveConfig();
};

#endif // IMPL_H
