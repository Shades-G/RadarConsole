/********************************************************************************
** Form generated from reading UI file 'ZDA.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZDA_H
#define UI_ZDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ZDA
{
public:
    QGroupBox *groupBox;
    QSpinBox *spinBox;
    QLabel *label_17;
    QSpinBox *spinBox_2;
    QLabel *label_16;
    QSpinBox *spinBox_3;
    QLabel *label_15;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_18;
    QLabel *label_19;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QFrame *ZDA)
    {
        if (ZDA->objectName().isEmpty())
            ZDA->setObjectName("ZDA");
        ZDA->resize(600, 600);
        ZDA->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        groupBox = new QGroupBox(ZDA);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 20, 601, 351));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(220, 70, 71, 29));
        spinBox->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(groupBox);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(520, 40, 63, 20));
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(370, 70, 71, 29));
        spinBox_2->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(groupBox);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(370, 40, 63, 20));
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(520, 70, 71, 29));
        spinBox_3->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(220, 40, 63, 20));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 80, 121, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 170, 63, 20));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(370, 140, 63, 20));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(220, 140, 63, 20));
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(370, 170, 71, 29));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setGeometry(QRect(220, 170, 71, 29));
        spinBox_5->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 240, 91, 20));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(220, 230, 121, 29));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 310, 84, 28));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(280, 310, 84, 28));

        retranslateUi(ZDA);

        QMetaObject::connectSlotsByName(ZDA);
    } // setupUi

    void retranslateUi(QFrame *ZDA)
    {
        ZDA->setWindowTitle(QCoreApplication::translate("ZDA", "Frame", nullptr));
        groupBox->setTitle(QString());
        label_17->setText(QCoreApplication::translate("ZDA", "SS(0-59)", nullptr));
        label_16->setText(QCoreApplication::translate("ZDA", "MM(0-59)", nullptr));
        label_15->setText(QCoreApplication::translate("ZDA", "HH(0-23)", nullptr));
        label->setText(QCoreApplication::translate("ZDA", "Observation Team", nullptr));
        label_2->setText(QCoreApplication::translate("ZDA", "Zone set", nullptr));
        label_18->setText(QCoreApplication::translate("ZDA", "MM(0-59)", nullptr));
        label_19->setText(QCoreApplication::translate("ZDA", "HH(0-23)", nullptr));
        label_3->setText(QCoreApplication::translate("ZDA", "Present Date", nullptr));
        pushButton->setText(QCoreApplication::translate("ZDA", "Confirm", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ZDA", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZDA: public Ui_ZDA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZDA_H
