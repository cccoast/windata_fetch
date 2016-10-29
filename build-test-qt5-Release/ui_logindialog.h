/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *frontIpLabel;
    QLineEdit *frontIpLineEdit;
    QLabel *frontPortLabel;
    QLineEdit *frontPortLineEdit;
    QLabel *brokerIdLabel;
    QLineEdit *brokerIdLineEdit;
    QLabel *investorLabel;
    QLineEdit *investorLineEdit;
    QRadioButton *radioButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(519, 252);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(340, 210, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 30, 471, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        frontIpLabel = new QLabel(formLayoutWidget);
        frontIpLabel->setObjectName(QStringLiteral("frontIpLabel"));
        QFont font;
        font.setPointSize(15);
        frontIpLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, frontIpLabel);

        frontIpLineEdit = new QLineEdit(formLayoutWidget);
        frontIpLineEdit->setObjectName(QStringLiteral("frontIpLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, frontIpLineEdit);

        frontPortLabel = new QLabel(formLayoutWidget);
        frontPortLabel->setObjectName(QStringLiteral("frontPortLabel"));
        frontPortLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, frontPortLabel);

        frontPortLineEdit = new QLineEdit(formLayoutWidget);
        frontPortLineEdit->setObjectName(QStringLiteral("frontPortLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, frontPortLineEdit);

        brokerIdLabel = new QLabel(formLayoutWidget);
        brokerIdLabel->setObjectName(QStringLiteral("brokerIdLabel"));
        brokerIdLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, brokerIdLabel);

        brokerIdLineEdit = new QLineEdit(formLayoutWidget);
        brokerIdLineEdit->setObjectName(QStringLiteral("brokerIdLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, brokerIdLineEdit);

        investorLabel = new QLabel(formLayoutWidget);
        investorLabel->setObjectName(QStringLiteral("investorLabel"));
        investorLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, investorLabel);

        investorLineEdit = new QLineEdit(formLayoutWidget);
        investorLineEdit->setObjectName(QStringLiteral("investorLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, investorLineEdit);

        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(350, 170, 141, 20));
        QFont font1;
        font1.setPointSize(16);
        radioButton->setFont(font1);
        radioButton->setChecked(true);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Account", 0));
        frontIpLabel->setText(QApplication::translate("Dialog", "front ip", 0));
        frontPortLabel->setText(QApplication::translate("Dialog", "front port", 0));
        brokerIdLabel->setText(QApplication::translate("Dialog", "broker id", 0));
        investorLabel->setText(QApplication::translate("Dialog", "investor id", 0));
        radioButton->setText(QApplication::translate("Dialog", "save option", 0));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
