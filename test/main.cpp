#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>
#include <QDir>
#include <QString>

#include <iostream>
#include <fstream>
#include <stdio.h>

#include "logindialog.h"

#include "src/misc.h"
#include "impl.h"

using namespace std;

int main(int argc, char *argv[])
{
    impl::getInstance()->Init();
    QApplication app(argc, argv);
    QTranslator translator;
    translator.load(":/cn.qm");
    app.installTranslator(&translator);
    MainWindow w;
    w.show();
    return app.exec();
}
