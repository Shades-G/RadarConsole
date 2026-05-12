/********************************************************************************
** Form generated from reading UI file 'TCPSetting.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSETTING_H
#define UI_TCPSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TCPSetting
{
public:
    QLabel *label;
    QLineEdit *Server_line;
    QLabel *label_2;
    QLineEdit *Client_line;
    QPushButton *TCP_start;
    QPushButton *TCP_stop;

    void setupUi(QFrame *TCPSetting)
    {
        if (TCPSetting->objectName().isEmpty())
            TCPSetting->setObjectName("TCPSetting");
        TCPSetting->resize(600, 600);
        TCPSetting->setStyleSheet(QString::fromUtf8("    background-color: #2b2b2b;\n"
"    border-radius: 5px;\n"
""));
        label = new QLabel(TCPSetting);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 80, 66, 18));
        Server_line = new QLineEdit(TCPSetting);
        Server_line->setObjectName("Server_line");
        Server_line->setGeometry(QRect(280, 80, 170, 26));
        label_2 = new QLabel(TCPSetting);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 200, 66, 18));
        Client_line = new QLineEdit(TCPSetting);
        Client_line->setObjectName("Client_line");
        Client_line->setGeometry(QRect(288, 190, 160, 26));
        TCP_start = new QPushButton(TCPSetting);
        TCP_start->setObjectName("TCP_start");
        TCP_start->setGeometry(QRect(140, 310, 94, 26));
        TCP_stop = new QPushButton(TCPSetting);
        TCP_stop->setObjectName("TCP_stop");
        TCP_stop->setGeometry(QRect(320, 310, 94, 26));

        retranslateUi(TCPSetting);

        QMetaObject::connectSlotsByName(TCPSetting);
    } // setupUi

    void retranslateUi(QFrame *TCPSetting)
    {
        TCPSetting->setWindowTitle(QCoreApplication::translate("TCPSetting", "Frame", nullptr));
        label->setText(QCoreApplication::translate("TCPSetting", "Server", nullptr));
        label_2->setText(QCoreApplication::translate("TCPSetting", "Port", nullptr));
        TCP_start->setText(QCoreApplication::translate("TCPSetting", "Connect", nullptr));
        TCP_stop->setText(QCoreApplication::translate("TCPSetting", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPSetting: public Ui_TCPSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSETTING_H
