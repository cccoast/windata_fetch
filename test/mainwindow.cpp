#include "mainwindow.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QT_END_NAMESPACE
