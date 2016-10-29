#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

    void setIP(std::string);
    void setPort(int);
    void setBroker(int);
    void setInvestor(long long);

    std::string getIP();
    int getPort();
    int getBroker();
    long long getInvestor();

    void saveConfig();

signals:
    void reqLogin();

///overload
public slots:
    void accept();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
