#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>
#include "connection.h"
#include "logindialog.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 必须在创建数据库之前使用，不然无法在数据库中使用中文
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    // 这里使用代码来运行MySQL数据库
    QProcess process;
    process.start("C:/MySQL/bin/mysqld.exe");

    if(!createConnection()) return 0;

    Widget w;
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    } else {
        return 0;
    }
}

