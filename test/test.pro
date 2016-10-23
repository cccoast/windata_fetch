#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T16:37:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    myapp.rc

TRANSLATIONS += cn.ts

RC_FILE = myapp.rc

RESOURCES += \
    res.qrc
