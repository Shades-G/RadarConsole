/********************************************************************************
** Form generated from reading UI file 'GGA.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGA_H
#define UI_GGA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GGA
{
public:
    QGroupBox *groupBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QComboBox *comboBox;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QFrame *GGA)
    {
        if (GGA->objectName().isEmpty())
            GGA->setObjectName("GGA");
        GGA->setEnabled(true);
        GGA->resize(722, 600);
        GGA->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 138, 133);"));
        groupBox = new QGroupBox(GGA);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(20, 0, 671, 171));
        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(160, 130, 91, 29));
        doubleSpinBox_2->setAlignment(Qt::AlignCenter);
        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(330, 130, 101, 29));
        doubleSpinBox_4->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 70, 63, 20));
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(330, 60, 101, 29));
        doubleSpinBox_3->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(500, 110, 63, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 40, 63, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 110, 91, 20));
        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(160, 60, 91, 29));
        doubleSpinBox->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(500, 60, 63, 20));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(500, 130, 63, 20));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(330, 40, 111, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(500, 40, 63, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(330, 110, 111, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 130, 71, 20));
        label = new QLabel(GGA);
        label->setObjectName("label");
        label->setGeometry(QRect(23, 193, 106, 20));
        label_12 = new QLabel(GGA);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(23, 244, 207, 20));
        label_13 = new QLabel(GGA);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(23, 294, 304, 20));
        label_14 = new QLabel(GGA);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(23, 345, 125, 20));
        label_15 = new QLabel(GGA);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(23, 396, 141, 20));
        label_16 = new QLabel(GGA);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(23, 446, 190, 20));
        label_17 = new QLabel(GGA);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(23, 497, 135, 20));
        label_18 = new QLabel(GGA);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(23, 547, 205, 20));
        spinBox = new QSpinBox(GGA);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(380, 190, 91, 29));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox_2 = new QSpinBox(GGA);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(500, 190, 81, 29));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_3 = new QSpinBox(GGA);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(610, 260, 81, 29));
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_4 = new QSpinBox(GGA);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(380, 240, 201, 29));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_5 = new QSpinBox(GGA);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setGeometry(QRect(380, 290, 201, 29));
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_6 = new QSpinBox(GGA);
        spinBox_6->setObjectName("spinBox_6");
        spinBox_6->setGeometry(QRect(380, 340, 201, 29));
        spinBox_6->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(GGA);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(380, 390, 201, 28));
        spinBox_7 = new QSpinBox(GGA);
        spinBox_7->setObjectName("spinBox_7");
        spinBox_7->setGeometry(QRect(380, 440, 201, 29));
        spinBox_7->setAlignment(Qt::AlignCenter);
        spinBox_8 = new QSpinBox(GGA);
        spinBox_8->setObjectName("spinBox_8");
        spinBox_8->setGeometry(QRect(380, 500, 201, 29));
        spinBox_8->setAlignment(Qt::AlignCenter);
        spinBox_9 = new QSpinBox(GGA);
        spinBox_9->setObjectName("spinBox_9");
        spinBox_9->setGeometry(QRect(380, 550, 201, 29));
        spinBox_9->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(GGA);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(380, 170, 63, 20));
        label_20 = new QLabel(GGA);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(500, 170, 71, 20));
        label_21 = new QLabel(GGA);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(610, 240, 63, 20));
        label_22 = new QLabel(GGA);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(600, 310, 63, 20));
        label_23 = new QLabel(GGA);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(600, 360, 63, 20));
        label_24 = new QLabel(GGA);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(600, 420, 91, 20));
        label_25 = new QLabel(GGA);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(600, 520, 91, 20));
        label_26 = new QLabel(GGA);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(600, 580, 63, 20));
        label_27 = new QLabel(GGA);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(600, 630, 63, 20));
        layoutWidget = new QWidget(GGA);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(197, 690, 261, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(GGA);

        QMetaObject::connectSlotsByName(GGA);
    } // setupUi

    void retranslateUi(QFrame *GGA)
    {
        GGA->setWindowTitle(QCoreApplication::translate("GGA", "Frame", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GGA", "Position", nullptr));
        label_2->setText(QCoreApplication::translate("GGA", "Latitude", nullptr));
        label_9->setText(QCoreApplication::translate("GGA", "     Dir", nullptr));
        label_4->setText(QCoreApplication::translate("GGA", "DD(0-90)", nullptr));
        label_5->setText(QCoreApplication::translate("GGA", "DDD(0-90)", nullptr));
        label_11->setText(QCoreApplication::translate("GGA", "     N", nullptr));
        label_10->setText(QCoreApplication::translate("GGA", "      E", nullptr));
        label_6->setText(QCoreApplication::translate("GGA", "MM.MM(59.99)", nullptr));
        label_8->setText(QCoreApplication::translate("GGA", "     Dir", nullptr));
        label_7->setText(QCoreApplication::translate("GGA", "MM.MM(59.99)", nullptr));
        label_3->setText(QCoreApplication::translate("GGA", "Longitude", nullptr));
        label->setText(QCoreApplication::translate("GGA", "UTC Of Position", nullptr));
        label_12->setText(QCoreApplication::translate("GGA", "Horizontal Dilution Of Precision", nullptr));
        label_13->setText(QCoreApplication::translate("GGA", "Antenna Altitude Above/below Mean Sea Level", nullptr));
        label_14->setText(QCoreApplication::translate("GGA", "Geoldal Seperation", nullptr));
        label_15->setText(QCoreApplication::translate("GGA", "GPS Quality Indicator", nullptr));
        label_16->setText(QCoreApplication::translate("GGA", "Age of Differentiak GPS Data", nullptr));
        label_17->setText(QCoreApplication::translate("GGA", "Number of Satellites", nullptr));
        label_18->setText(QCoreApplication::translate("GGA", "Diffrential Reference Station ID", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("GGA", "Select", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("GGA", "Fix not availabel or invalid", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("GGA", "Fix availabel or valid", nullptr));

        label_19->setText(QCoreApplication::translate("GGA", "HH(0-23)", nullptr));
        label_20->setText(QCoreApplication::translate("GGA", "MM(0-59)", nullptr));
        label_21->setText(QCoreApplication::translate("GGA", "SS(0-59)", nullptr));
        label_22->setText(QCoreApplication::translate("GGA", "(0-1)", nullptr));
        label_23->setText(QCoreApplication::translate("GGA", "M(0-100)", nullptr));
        label_24->setText(QCoreApplication::translate("GGA", "M(-100-100)", nullptr));
        label_25->setText(QCoreApplication::translate("GGA", "Sec(0-1000)", nullptr));
        label_26->setText(QCoreApplication::translate("GGA", "(0-12)", nullptr));
        label_27->setText(QCoreApplication::translate("GGA", "(0-12)", nullptr));
        pushButton->setText(QCoreApplication::translate("GGA", "Confirm", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GGA", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GGA: public Ui_GGA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGA_H
