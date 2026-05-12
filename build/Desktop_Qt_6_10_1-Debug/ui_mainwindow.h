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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *gv_Radar;
    QPushButton *DGPS;
    QPushButton *LOG;
    QPushButton *ECHO;
    QPushButton *AWOS;
    QPushButton *COMMS;
    QLineEdit *cursorRange_le;
    QLineEdit *cursorBearing_le;
    QLabel *label;
    QLabel *label_2;
    QComboBox *scale_selector_cb;
    QFrame *Config_Frame;
    QPushButton *TCP_config;
    QPushButton *UDP_config;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(815, 632);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gv_Radar = new QGraphicsView(centralWidget);
        gv_Radar->setObjectName("gv_Radar");
        gv_Radar->setGeometry(QRect(10, 0, 821, 591));
        DGPS = new QPushButton(centralWidget);
        DGPS->setObjectName("DGPS");
        DGPS->setGeometry(QRect(10, 600, 60, 26));
        LOG = new QPushButton(centralWidget);
        LOG->setObjectName("LOG");
        LOG->setGeometry(QRect(79, 601, 60, 26));
        ECHO = new QPushButton(centralWidget);
        ECHO->setObjectName("ECHO");
        ECHO->setGeometry(QRect(147, 602, 60, 26));
        AWOS = new QPushButton(centralWidget);
        AWOS->setObjectName("AWOS");
        AWOS->setGeometry(QRect(214, 602, 60, 26));
        COMMS = new QPushButton(centralWidget);
        COMMS->setObjectName("COMMS");
        COMMS->setGeometry(QRect(750, 600, 60, 26));
        cursorRange_le = new QLineEdit(centralWidget);
        cursorRange_le->setObjectName("cursorRange_le");
        cursorRange_le->setGeometry(QRect(130, 13, 80, 22));
        cursorBearing_le = new QLineEdit(centralWidget);
        cursorBearing_le->setObjectName("cursorBearing_le");
        cursorBearing_le->setGeometry(QRect(340, 12, 90, 26));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 16, 100, 18));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 17, 110, 18));
        scale_selector_cb = new QComboBox(centralWidget);
        scale_selector_cb->addItem(QString());
        scale_selector_cb->addItem(QString());
        scale_selector_cb->addItem(QString());
        scale_selector_cb->addItem(QString());
        scale_selector_cb->addItem(QString());
        scale_selector_cb->setObjectName("scale_selector_cb");
        scale_selector_cb->setGeometry(QRect(716, 14, 86, 26));
        Config_Frame = new QFrame(centralWidget);
        Config_Frame->setObjectName("Config_Frame");
        Config_Frame->setGeometry(QRect(690, 510, 120, 80));
        Config_Frame->setFrameShape(QFrame::Shape::StyledPanel);
        Config_Frame->setFrameShadow(QFrame::Shadow::Raised);
        TCP_config = new QPushButton(Config_Frame);
        TCP_config->setObjectName("TCP_config");
        TCP_config->setGeometry(QRect(10, 10, 94, 26));
        UDP_config = new QPushButton(Config_Frame);
        UDP_config->setObjectName("UDP_config");
        UDP_config->setGeometry(QRect(10, 48, 94, 26));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(622, 18, 90, 18));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        DGPS->setText(QCoreApplication::translate("MainWindow", "GPS", nullptr));
        LOG->setText(QCoreApplication::translate("MainWindow", "LOG", nullptr));
        ECHO->setText(QCoreApplication::translate("MainWindow", "ECHO", nullptr));
        AWOS->setText(QCoreApplication::translate("MainWindow", "AWOS", nullptr));
        COMMS->setText(QCoreApplication::translate("MainWindow", "COMMS", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mouse Range :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mouse Bearing :", nullptr));
        scale_selector_cb->setItemText(0, QCoreApplication::translate("MainWindow", "3", nullptr));
        scale_selector_cb->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        scale_selector_cb->setItemText(2, QCoreApplication::translate("MainWindow", "12", nullptr));
        scale_selector_cb->setItemText(3, QCoreApplication::translate("MainWindow", "24", nullptr));
        scale_selector_cb->setItemText(4, QCoreApplication::translate("MainWindow", "48", nullptr));

        TCP_config->setText(QCoreApplication::translate("MainWindow", "TCP Config", nullptr));
        UDP_config->setText(QCoreApplication::translate("MainWindow", "UDP Config", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Radar Scale:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
