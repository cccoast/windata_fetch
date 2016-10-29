#ifndef SUBDIALOG_H
#define SUBDIALOG_H

#include <QDialog>

namespace Ui {
class subDialog;
}

class subDialog : public QDialog
{
    Q_OBJECT

public:
    explicit subDialog(QWidget *parent = 0);
    ~subDialog();

private:
    Ui::subDialog *ui;
};

#endif // SUBDIALOG_H
