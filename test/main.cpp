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

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;
    translator.load(":/cn.qm");
    app.installTranslator(&translator);
    MainWindow w;
    w.show();

    string config_path = directoryOf(".").absoluteFilePath("config.ini").toStdString();
    cout << config_path << endl;

    return app.exec();
}
