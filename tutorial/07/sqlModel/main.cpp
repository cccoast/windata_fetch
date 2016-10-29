#include <QtGui/QApplication>
#include "mainwindow.h"
#include "connection.h"
#include <QTextCodec>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 这行代码要写在创建连接之前
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    // 这里使用代码来运行MySQL数据库
    QProcess process;
    process.start("C:/MySQL/bin/mysqld.exe");

    if (!createConnection()) return 1;
    MainWindow w;
    w.show();

    return a.exec();
}
