/********************************************************************************
** Form generated from reading UI file 'CAIS.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAIS_H
#define UI_CAIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CAIS
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QSpinBox *Message_SB;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *Number_SB;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *Identifier_SB;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *Bits_SB;
    QLabel *label_9;
    QPushButton *Confirm_AIS;
    QPushButton *Cancel_AIS;
    QGroupBox *groupBox_2;
    QRadioButton *channel_A;
    QRadioButton *channel_B;

    void setupUi(QFrame *CAIS)
    {
        if (CAIS->objectName().isEmpty())
            CAIS->setObjectName("CAIS");
        CAIS->resize(600, 600);
        groupBox = new QGroupBox(CAIS);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 10, 471, 371));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 191, 31));
        Message_SB = new QSpinBox(groupBox);
        Message_SB->setObjectName("Message_SB");
        Message_SB->setGeometry(QRect(220, 50, 91, 29));
        Message_SB->setMinimum(0);
        Message_SB->setMaximum(9);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 100, 141, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 49, 63, 31));
        Number_SB = new QSpinBox(groupBox);
        Number_SB->setObjectName("Number_SB");
        Number_SB->setGeometry(QRect(220, 90, 91, 31));
        Number_SB->setMaximum(9);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 90, 63, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 201, 20));
        Identifier_SB = new QSpinBox(groupBox);
        Identifier_SB->setObjectName("Identifier_SB");
        Identifier_SB->setGeometry(QRect(220, 130, 91, 31));
        Identifier_SB->setMaximum(9);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(320, 130, 63, 31));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 190, 91, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 270, 111, 20));
        Bits_SB = new QSpinBox(groupBox);
        Bits_SB->setObjectName("Bits_SB");
        Bits_SB->setGeometry(QRect(220, 270, 91, 31));
        Bits_SB->setMaximum(5);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(320, 269, 63, 31));
        Confirm_AIS = new QPushButton(groupBox);
        Confirm_AIS->setObjectName("Confirm_AIS");
        Confirm_AIS->setGeometry(QRect(120, 330, 84, 28));
        Cancel_AIS = new QPushButton(groupBox);
        Cancel_AIS->setObjectName("Cancel_AIS");
        Cancel_AIS->setGeometry(QRect(230, 330, 84, 28));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(120, 160, 111, 51));
        channel_A = new QRadioButton(groupBox_2);
        channel_A->setObjectName("channel_A");
        channel_A->setGeometry(QRect(10, 20, 41, 31));
        channel_B = new QRadioButton(groupBox_2);
        channel_B->setObjectName("channel_B");
        channel_B->setGeometry(QRect(60, 20, 51, 31));

        retranslateUi(CAIS);

        QMetaObject::connectSlotsByName(CAIS);
    } // setupUi

    void retranslateUi(QFrame *CAIS)
    {
        CAIS->setWindowTitle(QCoreApplication::translate("CAIS", "Frame", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CAIS", "AIS", nullptr));
        label->setText(QCoreApplication::translate("CAIS", "Sentences transfer Message:", nullptr));
        label_2->setText(QCoreApplication::translate("CAIS", "Sentence Number:", nullptr));
        label_3->setText(QCoreApplication::translate("CAIS", "(1 - 9)", nullptr));
        label_4->setText(QCoreApplication::translate("CAIS", "(1 - 9)", nullptr));
        label_5->setText(QCoreApplication::translate("CAIS", "Sequential message identifier:", nullptr));
        label_6->setText(QCoreApplication::translate("CAIS", "(1 - 9)", nullptr));
        label_7->setText(QCoreApplication::translate("CAIS", "AIS Channel:", nullptr));
        label_8->setText(QCoreApplication::translate("CAIS", "No. of Fill-Bits :", nullptr));
        label_9->setText(QCoreApplication::translate("CAIS", "(0-5)", nullptr));
        Confirm_AIS->setText(QCoreApplication::translate("CAIS", "Confirm", nullptr));
        Cancel_AIS->setText(QCoreApplication::translate("CAIS", "Cancel", nullptr));
        groupBox_2->setTitle(QString());
        channel_A->setText(QCoreApplication::translate("CAIS", "A", nullptr));
        channel_B->setText(QCoreApplication::translate("CAIS", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAIS: public Ui_CAIS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAIS_H
