#include "subdialog.h"
#include "ui_subdialog.h"
#include "src/misc.h"

#include <iostream>
using namespace std;

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

bool subDialog::loadFile(QString sub_path)
{
    cout << sub_path << endl;
}

void subDialog::on_pushButton_clicked()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}
