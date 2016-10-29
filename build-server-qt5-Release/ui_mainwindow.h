/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDelete;
    QAction *actionDialog;
    QAction *actionText;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *cinLineEdit;
    QPushButton *pushButton_5;
    QLineEdit *getlineLineEdit;
    QLabel *coutLabel;
    QLabel *getlineLabel;
    QLineEdit *coutLineEdit;
    QLabel *cinLabel;
    QWidget *horizontalLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *sexLabel;
    QLineEdit *sexLineEdit;
    QLabel *ageLabel;
    QLineEdit *ageLineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuMain;
    QMenu *menuNew;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1092, 638);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionDialog = new QAction(MainWindow);
        actionDialog->setObjectName(QStringLiteral("actionDialog"));
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QStringLiteral("actionText"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 1081, 541));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        groupBox->setCheckable(false);
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 10, 200, 200));
        scrollArea->setMinimumSize(QSize(100, 100));
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 500, 500));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMinimumSize(QSize(500, 500));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 251, 161));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 160, 75, 23));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 160, 75, 23));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(160, 160, 75, 23));
        scrollArea->setWidget(scrollAreaWidgetContents);
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(200, 10, 321, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cinLineEdit = new QLineEdit(gridLayoutWidget);
        cinLineEdit->setObjectName(QStringLiteral("cinLineEdit"));

        gridLayout->addWidget(cinLineEdit, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 1, 1, 1);

        getlineLineEdit = new QLineEdit(gridLayoutWidget);
        getlineLineEdit->setObjectName(QStringLiteral("getlineLineEdit"));

        gridLayout->addWidget(getlineLineEdit, 3, 1, 1, 1);

        coutLabel = new QLabel(gridLayoutWidget);
        coutLabel->setObjectName(QStringLiteral("coutLabel"));

        gridLayout->addWidget(coutLabel, 2, 0, 1, 1);

        getlineLabel = new QLabel(gridLayoutWidget);
        getlineLabel->setObjectName(QStringLiteral("getlineLabel"));

        gridLayout->addWidget(getlineLabel, 3, 0, 1, 1);

        coutLineEdit = new QLineEdit(gridLayoutWidget);
        coutLineEdit->setObjectName(QStringLiteral("coutLineEdit"));

        gridLayout->addWidget(coutLineEdit, 2, 1, 1, 1);

        cinLabel = new QLabel(gridLayoutWidget);
        cinLabel->setObjectName(QStringLiteral("cinLabel"));

        gridLayout->addWidget(cinLabel, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(200, 210, 320, 54));
        gridLayout_3 = new QGridLayout(horizontalLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_19 = new QPushButton(horizontalLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout_3->addWidget(pushButton_19, 0, 0, 1, 1);

        pushButton_20 = new QPushButton(horizontalLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        gridLayout_3->addWidget(pushButton_20, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_3->addWidget(pushButton_7, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(horizontalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_3->addWidget(pushButton_8, 0, 3, 1, 1);

        pushButton_9 = new QPushButton(horizontalLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_3->addWidget(pushButton_9, 1, 1, 1, 1);

        scrollArea_2 = new QScrollArea(groupBox);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 210, 201, 161));
        scrollArea_2->setMinimumSize(QSize(100, 100));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 500, 500));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(500, 500));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(200, 260, 321, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(formLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        sexLabel = new QLabel(formLayoutWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, sexLabel);

        sexLineEdit = new QLineEdit(formLayoutWidget);
        sexLineEdit->setObjectName(QStringLiteral("sexLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sexLineEdit);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ageLabel);

        ageLineEdit = new QLineEdit(formLayoutWidget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ageLineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 540, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1092, 23));
        menuMain = new QMenu(menuBar);
        menuMain->setObjectName(QStringLiteral("menuMain"));
        menuNew = new QMenu(menuMain);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMain->menuAction());
        menuMain->addAction(menuNew->menuAction());
        menuMain->addAction(actionDelete);
        menuNew->addAction(actionDialog);
        menuNew->addAction(actionText);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "delete", 0));
        actionDialog->setText(QApplication::translate("MainWindow", "dialog", 0));
        actionText->setText(QApplication::translate("MainWindow", "text", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0));
        coutLabel->setText(QApplication::translate("MainWindow", "cout", 0));
        getlineLabel->setText(QApplication::translate("MainWindow", "getline", 0));
        cinLabel->setText(QApplication::translate("MainWindow", "cin", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "PushButton", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "name", 0));
        sexLabel->setText(QApplication::translate("MainWindow", "sex", 0));
        ageLabel->setText(QApplication::translate("MainWindow", "age", 0));
        pushButton->setText(QApplication::translate("MainWindow", "status", 0));
        menuMain->setTitle(QApplication::translate("MainWindow", "main(&f)", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "new", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
