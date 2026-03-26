/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QPushButton *GPS_PB;
    QPushButton *LOG_PB;
    QPushButton *AWOS_PB;
    QPushButton *ECHO_PB;
    QPushButton *COMMS_PB;
    QPushButton *AIS_PB;
    QPushButton *IBS_PB;
    QFrame *GPS_Frame;
    QPushButton *RMC_PB;
    QPushButton *ZDA_PB;
    QPushButton *GLL_PB;
    QPushButton *GGA_PB;
    QFrame *AWOS_Frame;
    QPushButton *MWV_PB;
    QPushButton *XDR_PB;
    QFrame *COMMS_Frame;
    QPushButton *TCP_PB;
    QPushButton *UDP_PB;
    QGraphicsView *gv_Radar;
    QComboBox *scale_selector;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 100, 600));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        GPS_PB = new QPushButton(frame);
        GPS_PB->setObjectName("GPS_PB");
        GPS_PB->setGeometry(QRect(20, 10, 60, 40));
        LOG_PB = new QPushButton(frame);
        LOG_PB->setObjectName("LOG_PB");
        LOG_PB->setGeometry(QRect(20, 60, 60, 40));
        AWOS_PB = new QPushButton(frame);
        AWOS_PB->setObjectName("AWOS_PB");
        AWOS_PB->setGeometry(QRect(20, 110, 60, 40));
        ECHO_PB = new QPushButton(frame);
        ECHO_PB->setObjectName("ECHO_PB");
        ECHO_PB->setGeometry(QRect(20, 160, 60, 40));
        COMMS_PB = new QPushButton(frame);
        COMMS_PB->setObjectName("COMMS_PB");
        COMMS_PB->setGeometry(QRect(20, 530, 60, 40));
        AIS_PB = new QPushButton(frame);
        AIS_PB->setObjectName("AIS_PB");
        AIS_PB->setGeometry(QRect(22, 210, 60, 40));
        IBS_PB = new QPushButton(frame);
        IBS_PB->setObjectName("IBS_PB");
        IBS_PB->setGeometry(QRect(24, 260, 60, 40));
        GPS_Frame = new QFrame(centralWidget);
        GPS_Frame->setObjectName("GPS_Frame");
        GPS_Frame->setGeometry(QRect(100, 0, 101, 601));
        GPS_Frame->setFrameShape(QFrame::Shape::StyledPanel);
        GPS_Frame->setFrameShadow(QFrame::Shadow::Raised);
        RMC_PB = new QPushButton(GPS_Frame);
        RMC_PB->setObjectName("RMC_PB");
        RMC_PB->setGeometry(QRect(20, 10, 61, 41));
        ZDA_PB = new QPushButton(GPS_Frame);
        ZDA_PB->setObjectName("ZDA_PB");
        ZDA_PB->setGeometry(QRect(20, 160, 61, 41));
        GLL_PB = new QPushButton(GPS_Frame);
        GLL_PB->setObjectName("GLL_PB");
        GLL_PB->setGeometry(QRect(20, 110, 61, 41));
        GGA_PB = new QPushButton(GPS_Frame);
        GGA_PB->setObjectName("GGA_PB");
        GGA_PB->setGeometry(QRect(20, 60, 61, 41));
        AWOS_Frame = new QFrame(centralWidget);
        AWOS_Frame->setObjectName("AWOS_Frame");
        AWOS_Frame->setGeometry(QRect(100, 0, 100, 600));
        AWOS_Frame->setFrameShape(QFrame::Shape::StyledPanel);
        AWOS_Frame->setFrameShadow(QFrame::Shadow::Raised);
        MWV_PB = new QPushButton(AWOS_Frame);
        MWV_PB->setObjectName("MWV_PB");
        MWV_PB->setGeometry(QRect(20, 10, 61, 41));
        XDR_PB = new QPushButton(AWOS_Frame);
        XDR_PB->setObjectName("XDR_PB");
        XDR_PB->setGeometry(QRect(20, 60, 61, 41));
        COMMS_Frame = new QFrame(centralWidget);
        COMMS_Frame->setObjectName("COMMS_Frame");
        COMMS_Frame->setGeometry(QRect(100, 0, 100, 600));
        COMMS_Frame->setFrameShape(QFrame::Shape::StyledPanel);
        COMMS_Frame->setFrameShadow(QFrame::Shadow::Raised);
        TCP_PB = new QPushButton(COMMS_Frame);
        TCP_PB->setObjectName("TCP_PB");
        TCP_PB->setGeometry(QRect(20, 10, 61, 41));
        UDP_PB = new QPushButton(COMMS_Frame);
        UDP_PB->setObjectName("UDP_PB");
        UDP_PB->setGeometry(QRect(20, 60, 61, 41));
        gv_Radar = new QGraphicsView(centralWidget);
        gv_Radar->setObjectName("gv_Radar");
        gv_Radar->setGeometry(QRect(190, 10, 600, 600));
        scale_selector = new QComboBox(centralWidget);
        scale_selector->addItem(QString());
        scale_selector->addItem(QString());
        scale_selector->addItem(QString());
        scale_selector->addItem(QString());
        scale_selector->addItem(QString());
        scale_selector->addItem(QString());
        scale_selector->setObjectName("scale_selector");
        scale_selector->setGeometry(QRect(660, 10, 120, 26));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        GPS_PB->setText(QCoreApplication::translate("MainWindow", "GPS", nullptr));
        LOG_PB->setText(QCoreApplication::translate("MainWindow", "LOG", nullptr));
        AWOS_PB->setText(QCoreApplication::translate("MainWindow", "AWOS", nullptr));
        ECHO_PB->setText(QCoreApplication::translate("MainWindow", "ECHO", nullptr));
        COMMS_PB->setText(QCoreApplication::translate("MainWindow", "COMMS", nullptr));
        AIS_PB->setText(QCoreApplication::translate("MainWindow", "AIS", nullptr));
        IBS_PB->setText(QCoreApplication::translate("MainWindow", "IBS", nullptr));
        RMC_PB->setText(QCoreApplication::translate("MainWindow", "RMC", nullptr));
        ZDA_PB->setText(QCoreApplication::translate("MainWindow", "ZDA", nullptr));
        GLL_PB->setText(QCoreApplication::translate("MainWindow", "GLL", nullptr));
        GGA_PB->setText(QCoreApplication::translate("MainWindow", "GGA", nullptr));
        MWV_PB->setText(QCoreApplication::translate("MainWindow", "MWV", nullptr));
        XDR_PB->setText(QCoreApplication::translate("MainWindow", "XDR", nullptr));
        TCP_PB->setText(QCoreApplication::translate("MainWindow", "TCP", nullptr));
        UDP_PB->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        scale_selector->setItemText(0, QCoreApplication::translate("MainWindow", "3", nullptr));
        scale_selector->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        scale_selector->setItemText(2, QCoreApplication::translate("MainWindow", "12", nullptr));
        scale_selector->setItemText(3, QCoreApplication::translate("MainWindow", "24", nullptr));
        scale_selector->setItemText(4, QCoreApplication::translate("MainWindow", "48", nullptr));
        scale_selector->setItemText(5, QCoreApplication::translate("MainWindow", "New Item", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
