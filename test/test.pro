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
    subdialog.cpp \
    src/FillFunction/fillFunction.cpp \
    src/CTPConnector/CTPConnector.cpp \
    src/CTPConnector/DataPublisher.cpp \
    src/StreamManager/FutureStreamDump.cpp \
    src/CTPConnector/StreamProcessor.cpp \
    src/ShareMemory/ShmPool.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    impl.h \
    src/ini_parser.hpp \
    src/misc.h \
    subdialog.h \
    src/ctpapi/ThostFtdcMdApi.h \
    src/ctpapi/ThostFtdcUserApiDataType.h \
    src/ctpapi/ThostFtdcUserApiStruct.h \
    src/CTPConnector/CTPConnector.hpp \
    src/CTPConnector/StreamProcessor.hpp \
    src/FillFunction/fillFunction.h \
    src/StreamManager/DataType.hpp \
    src/StreamManager/FutureStreamDump.hpp \
    src/StreamManager/StreamDump.hpp \
    src/ShareMemory/ShmPool.hpp

FORMS    += mainwindow.ui \
    logindialog.ui \
    subdialog.ui

DISTFILES += \
    myapp.rc \
    config.ini \

TRANSLATIONS += cn.ts

RC_FILE = myapp.rc

RESOURCES += \
    res.qrc

INCLUDEPATH += E:\library\boost_1_59_0 \
               E:\winDataServer\MemroyDataServer\DataServer \
DEPENDPATH += E:\library\boost_1_59_0 \
                E:\winDataServer\MemroyDataServer\DataServer \

DEFINES += XDD_VERSION \
            ISLIB \

LIBS += -L"E:\QtWorkSpace\test\src\ctpapi\"  -lthostmduserapi \

