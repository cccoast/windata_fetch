#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindlg.h"

#include <QObject>

#include <iostream>

#include <zmq.h>
#include <czmq.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isRunning(false),
    instance(NULL)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->isRunning = !this->isRunning;
    if(this->isRunning){
        cout << instance << endl;
        if(!instance){
            instance = new LoginDlg(this);
        }
        instance->show();
        this->ui->pushButton->setText(QObject::tr("isRunning"));
    }
    else{
        cout << instance << endl;
        if(instance){
            instance->hide();
        }
        this->ui->pushButton->setText(QObject::tr("waiting"));
    }
}

void MainWindow::on_actionDelete_triggered()
{
    cout << "hello world" << endl;
}
