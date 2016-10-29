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
        mainwindow.cpp \
    logindialog.cpp \
    impl.cpp \
    subdialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    impl.h \
    src/ini_parser.hpp \
    src/misc.h \
    subdialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    subdialog.ui

DISTFILES += \
    myapp.rc \
    config.ini

TRANSLATIONS += cn.ts

RC_FILE = myapp.rc

RESOURCES += \
    res.qrc
