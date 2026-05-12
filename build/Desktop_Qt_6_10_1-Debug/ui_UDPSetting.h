/********************************************************************************
** Form generated from reading UI file 'UDPSetting.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPSETTING_H
#define UI_UDPSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_UDPSetting
{
public:
    QLineEdit *Sender_line;
    QLineEdit *Receiver_line;
    QLabel *label;
    QLabel *label_2;
    QPushButton *UDP_start;
    QPushButton *UDP_stop;
    QRadioButton *unicast;
    QRadioButton *broadcast;
    QLabel *label_3;
    QLineEdit *udp_ip;

    void setupUi(QFrame *UDPSetting)
    {
        if (UDPSetting->objectName().isEmpty())
            UDPSetting->setObjectName("UDPSetting");
        UDPSetting->resize(600, 600);
        UDPSetting->setStyleSheet(QString::fromUtf8("    background-color: #2b2b2b;\n"
"    border-radius: 5px;\n"
""));
        Sender_line = new QLineEdit(UDPSetting);
        Sender_line->setObjectName("Sender_line");
        Sender_line->setGeometry(QRect(292, 140, 140, 26));
        Receiver_line = new QLineEdit(UDPSetting);
        Receiver_line->setObjectName("Receiver_line");
        Receiver_line->setGeometry(QRect(290, 210, 140, 26));
        label = new QLabel(UDPSetting);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 150, 100, 18));
        label_2 = new QLabel(UDPSetting);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 210, 110, 18));
        UDP_start = new QPushButton(UDPSetting);
        UDP_start->setObjectName("UDP_start");
        UDP_start->setGeometry(QRect(150, 330, 94, 26));
        UDP_stop = new QPushButton(UDPSetting);
        UDP_stop->setObjectName("UDP_stop");
        UDP_stop->setGeometry(QRect(330, 330, 94, 26));
        unicast = new QRadioButton(UDPSetting);
        unicast->setObjectName("unicast");
        unicast->setGeometry(QRect(120, 30, 110, 23));
        broadcast = new QRadioButton(UDPSetting);
        broadcast->setObjectName("broadcast");
        broadcast->setGeometry(QRect(330, 30, 110, 23));
        label_3 = new QLabel(UDPSetting);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(81, 90, 100, 18));
        udp_ip = new QLineEdit(UDPSetting);
        udp_ip->setObjectName("udp_ip");
        udp_ip->setGeometry(QRect(293, 80, 140, 26));

        retranslateUi(UDPSetting);

        QMetaObject::connectSlotsByName(UDPSetting);
    } // setupUi

    void retranslateUi(QFrame *UDPSetting)
    {
        UDPSetting->setWindowTitle(QCoreApplication::translate("UDPSetting", "Frame", nullptr));
        label->setText(QCoreApplication::translate("UDPSetting", "Sender Port", nullptr));
        label_2->setText(QCoreApplication::translate("UDPSetting", "Receiver Port", nullptr));
        UDP_start->setText(QCoreApplication::translate("UDPSetting", "Connect", nullptr));
        UDP_stop->setText(QCoreApplication::translate("UDPSetting", "Disconnect", nullptr));
        unicast->setText(QCoreApplication::translate("UDPSetting", "Uni-Cast", nullptr));
        broadcast->setText(QCoreApplication::translate("UDPSetting", "BroadCast", nullptr));
        label_3->setText(QCoreApplication::translate("UDPSetting", "Destination IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UDPSetting: public Ui_UDPSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPSETTING_H
