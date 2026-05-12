QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    AISDecoder/AISDecoder.cpp \
    CPACalc/CPACalculator.cpp \
    SimulatedTarget/SimulatedTarget.cpp \
    TCPSetting.cpp \
    UDPSetting.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AISDecoder/AISDecoder.h \
    CPACalc/CPACalculator.h \
    SimulatedTarget/SimulatedTarget.h \
    TCPSetting.h \
    UDPSetting.h \
    mainwindow.h

FORMS += \
    TCPSetting.ui \
    UDPSetting.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
