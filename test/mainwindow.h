#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "subdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotLoginDlg();
    void slotReqLogin();

private:
    Ui::MainWindow *ui;
    loginDialog* login;
    subDialog* subber;
};

#endif // MAINWINDOW_H
