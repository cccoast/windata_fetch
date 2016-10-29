#include "subdialog.h"
#include "ui_subdialog.h"

subDialog::subDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::subDialog)
{
    ui->setupUi(this);
}

subDialog::~subDialog()
{
    delete ui;
}
