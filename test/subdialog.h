#ifndef SUBDIALOG_H
#define SUBDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class subDialog;
}

class subDialog : public QDialog
{
    Q_OBJECT

public:
    explicit subDialog(QWidget *parent = 0);
    ~subDialog();
    bool loadFile(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::subDialog *ui;
};

#endif // SUBDIALOG_H
