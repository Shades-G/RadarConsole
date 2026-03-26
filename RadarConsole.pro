#-------------------------------------------------
#
# Project created by QtCreator 2026-02-03T16:03:14
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    AIS/CAIS.cpp \
    AWOS/CMWV.cpp \
    AWOS/CXDR.cpp \
    ECHO/CECHO.cpp \
    LOG/CLOG.cpp \
    SimulatedTarget/SimulatedTarget.cpp \
    TCPSetting.cpp \
    UDPSetting.cpp \
        main.cpp \
        mainwindow.cpp \
    GPS/CRMCView.cpp \
    GPS/GLL.cpp \
    GPS/GGA.cpp \
    GPS/ZDA.cpp \
    IBS/CIBS.cpp  \

HEADERS += \
    AIS/CAIS.h \
    AWOS/CMWV.h \
    AWOS/CXDR.h \
    ECHO/CECHO.h \
    LOG/CLOG.h \
    SimulatedTarget/SimulatedTarget.h \
    TCPSetting.h \
    UDPSetting.h \
        mainwindow.h \
    GPS/CRMCView.h \
    GPS/GLL.h \
    GPS/GGA.h \
    GPS/ZDA.h \
    IBS/CIBS.h  \

FORMS += \
    AIS/CAIS.ui \
    AWOS/CMWV.ui \
    AWOS/CXDR.ui \
    ECHO/CECHO.ui \
    LOG/CLOG.ui \
    TCPSetting.ui \
    UDPSetting.ui \
        mainwindow.ui \
    GPS/CRMCView.ui \
    GPS/GLL.ui \
    GPS/GGA.ui \
    GPS/ZDA.ui \
    IBS/CIBS.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
