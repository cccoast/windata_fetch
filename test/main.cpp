#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;
    bool b = translator.load(":/cn.qm");
    app.installTranslator(&translator);
    MainWindow w;
    w.show();

    return app.exec();
}
