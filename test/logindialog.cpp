#include "logindialog.h"
#include "ui_logindialog.h"
#include <QString>
#include <string>

#include "src/ini_parser.hpp"
#include "impl.h"

#include <iostream>

using namespace std;

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::setIP(string ip){
    ui->frontIpLineEdit->setText(QString::fromStdString(ip));
}

void loginDialog::setPort(int port){
    ui->frontPortLineEdit->setText(QString::fromStdString(std::to_string(port)));
}

void loginDialog::setBroker(int broker){
    ui->brokerIdLineEdit->setText(QString::fromStdString(std::to_string(broker)));
}

void loginDialog::setInvestor(long long investor){
    ui->investorLineEdit->setText(QString::fromStdString(std::to_string(investor)));
}

string loginDialog::getIP()
{
    return ui->frontIpLineEdit->text().toStdString();
}

int loginDialog::getPort()
{
    return std::stoi(ui->frontPortLineEdit->text().toStdString());
}

int loginDialog::getBroker()
{
    return std::stoi(ui->brokerIdLineEdit->text().toStdString());
}

long long loginDialog::getInvestor()
{
    return std::stoll(ui->investorLineEdit->text().toStdString());
}

void loginDialog::saveConfig(){
    if(ui->radioButton->isChecked()){
        impl::getInstance()->account_config.ip =  getIP();
        impl::getInstance()->account_config.port = getPort();
        impl::getInstance()->account_config.broker_id = getBroker();
        impl::getInstance()->account_config.investor_id = getInvestor();
        impl::getInstance()->saveConfig();
    }
    else{

    }
}

void loginDialog::accept(){
    this->saveConfig();
    emit this->reqLogin();
}
