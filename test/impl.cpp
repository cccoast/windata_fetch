#include "impl.h"
#include <string>
#include <iostream>

#include "src/ini_parser.hpp"
#include "src/misc.h"

#include <QString>
#include <QDir>

using namespace std;

static string config_path("config.ini");

impl* impl::_instance = new impl;

int impl::initConfig(){
    config_path = directoryOf(".").absoluteFilePath("config.ini").toStdString();
    ini_parser reader(config_path);
    if(reader.parse_error()){
        return -1;
    }
    else{
        _instance->account_config.ip = reader.get_string("ctp_front_address","account");
        _instance->account_config.port = reader.get_int("ctp_front_port","account");
        _instance->account_config.broker_id = reader.get_int("ctp_broker_id","account");
        _instance->account_config.investor_id = reader.get_long("ctp_investor_id","account");
    }
    return 0;
}

int impl::saveConfig()
{
    config_path = directoryOf(".").absoluteFilePath("config.ini").toStdString();
    ini_parser reader(config_path);
    if(reader.parse_error()){
        return -1;
    }
    else{
        reader.set_value("ctp_front_address",_instance->account_config.ip,"account");
        reader.set_value("ctp_front_port",_instance->account_config.port,"account");
        reader.set_value("ctp_broker_id",_instance->account_config.broker_id,"account");
        reader.set_value("ctp_investor_id",_instance->account_config.investor_id,"account");
    }
    return 0;
}
