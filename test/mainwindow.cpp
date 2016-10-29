#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "subdialog.h"

#include "impl.h"

#include <iostream>

#include <QString>

using namespace std;

QT_BEGIN_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    login(new loginDialog(this)),
    subber(new subDialog(this))
{
    ui->setupUi(this);
    QObject::connect(ui->actionLogin, SIGNAL(triggered()), this, SLOT(slotLoginDlg()));
    QObject::connect(ui->actionSubscribe_s, SIGNAL(triggered()), this, SLOT(slotLoginDlg()));

    QObject::connect(this->login, SIGNAL(reqLogin()), this, SLOT(slotReqLogin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Qaction Login
void MainWindow::slotLoginDlg(){
    int re = impl::getInstance()->initConfig();
    if(re == 0){
        login->setIP(impl::getInstance()->account_config.ip);
        login->setPort(impl::getInstance()->account_config.port);
        login->setBroker(impl::getInstance()->account_config.broker_id);
        login->setInvestor(impl::getInstance()->account_config.investor_id);
    }
    else{
        cout << "cannot open config file!" << endl;
    }
    login->show();
}


//
void MainWindow::slotReqLogin(){
    ///

    ///
    login->hide();
}

QT_END_NAMESPACE
