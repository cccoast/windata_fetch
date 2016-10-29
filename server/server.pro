#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T10:42:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp

HEADERS  += mainwindow.h \
    logindlg.h

FORMS    += mainwindow.ui \
    logindlg.ui

INCLUDEPATH += "C:/Program Files/zmq/include/" \
               "C:/Program Files/czmq/include/" \

LIBS += -L"C:/Program Files/zmq/lib/"  -llibzmq \
        -L"C:/Program Files/czmq/lib/"  -llibczmq \

