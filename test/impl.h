#ifndef IMPL_H
#define IMPL_H

#include <string>
#include <vector>
#include <unordered_map>

#include "src/CTPConnector/CTPConnector.hpp"
using namespace std;

typedef struct config config;
struct config{
    string ip;
    int port;
    int broker_id;
    long long investor_id;
};

typedef struct indInsStruct indInsStruct;
struct indInsStruct {
    std::vector<long> ins_list;
    std::unordered_map<std::string, long> ins_pair;
    std::vector<long> ind_list;
    std::unordered_map<std::string, long> ind_pair;
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
    CTPConnector* newConnector;

    void Init();
    int initConfig();
    int saveConfig();
    void ctpLogIn(bool);

    bool is_connected;
    indInsStruct ins_inds;
    vector<string> ins_list;
};

#endif // IMPL_H
