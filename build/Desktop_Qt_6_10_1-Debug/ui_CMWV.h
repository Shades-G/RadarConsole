/********************************************************************************
** Form generated from reading UI file 'CMWV.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMWV_H
#define UI_CMWV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CMWV
{
public:
    QPushButton *pushButton_2;
    QPushButton *MWV_confirm;
    QPushButton *MWV_cancel;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *rb_Kn;
    QRadioButton *rb_kmph;
    QRadioButton *rb_mps;
    QGroupBox *groupBox_3;
    QRadioButton *wind_RefTrue;
    QRadioButton *wind_RefRelative;
    QGroupBox *groupBox_4;
    QRadioButton *status_Valid;
    QRadioButton *status_Invalid;
    QDoubleSpinBox *waterAngle;
    QDoubleSpinBox *waterSpeed;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *MWV_on;
    QRadioButton *MWV_off;
    QButtonGroup *buttonGroup;

    void setupUi(QFrame *CMWV)
    {
        if (CMWV->objectName().isEmpty())
            CMWV->setObjectName("CMWV");
        CMWV->resize(600, 600);
        pushButton_2 = new QPushButton(CMWV);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 550, 94, 26));
        MWV_confirm = new QPushButton(CMWV);
        MWV_confirm->setObjectName("MWV_confirm");
        MWV_confirm->setGeometry(QRect(80, 550, 94, 26));
        MWV_cancel = new QPushButton(CMWV);
        MWV_cancel->setObjectName("MWV_cancel");
        MWV_cancel->setGeometry(QRect(420, 550, 94, 26));
        label = new QLabel(CMWV);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 32, 90, 18));
        label_2 = new QLabel(CMWV);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 73, 90, 20));
        groupBox = new QGroupBox(CMWV);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 114, 561, 81));
        rb_Kn = new QRadioButton(groupBox);
        rb_Kn->setObjectName("rb_Kn");
        rb_Kn->setGeometry(QRect(30, 50, 110, 23));
        rb_kmph = new QRadioButton(groupBox);
        rb_kmph->setObjectName("rb_kmph");
        rb_kmph->setGeometry(QRect(399, 51, 110, 23));
        rb_mps = new QRadioButton(groupBox);
        rb_mps->setObjectName("rb_mps");
        rb_mps->setGeometry(QRect(210, 50, 110, 23));
        groupBox_3 = new QGroupBox(CMWV);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(21, 210, 561, 90));
        wind_RefTrue = new QRadioButton(groupBox_3);
        wind_RefTrue->setObjectName("wind_RefTrue");
        wind_RefTrue->setGeometry(QRect(30, 50, 110, 23));
        wind_RefRelative = new QRadioButton(groupBox_3);
        wind_RefRelative->setObjectName("wind_RefRelative");
        wind_RefRelative->setGeometry(QRect(399, 51, 110, 23));
        groupBox_4 = new QGroupBox(CMWV);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(24, 312, 561, 90));
        status_Valid = new QRadioButton(groupBox_4);
        status_Valid->setObjectName("status_Valid");
        status_Valid->setGeometry(QRect(30, 50, 110, 23));
        status_Invalid = new QRadioButton(groupBox_4);
        status_Invalid->setObjectName("status_Invalid");
        status_Invalid->setGeometry(QRect(399, 51, 110, 23));
        waterAngle = new QDoubleSpinBox(CMWV);
        waterAngle->setObjectName("waterAngle");
        waterAngle->setGeometry(QRect(190, 30, 130, 27));
        waterAngle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        waterAngle->setMaximum(360.000000000000000);
        waterSpeed = new QDoubleSpinBox(CMWV);
        waterSpeed->setObjectName("waterSpeed");
        waterSpeed->setGeometry(QRect(190, 70, 130, 27));
        waterSpeed->setAlignment(Qt::AlignmentFlag::AlignCenter);
        waterSpeed->setMaximum(100.000000000000000);
        label_3 = new QLabel(CMWV);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 34, 120, 18));
        label_4 = new QLabel(CMWV);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 74, 110, 18));
        MWV_on = new QRadioButton(CMWV);
        buttonGroup = new QButtonGroup(CMWV);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(MWV_on);
        MWV_on->setObjectName("MWV_on");
        MWV_on->setGeometry(QRect(120, 450, 110, 23));
        MWV_off = new QRadioButton(CMWV);
        buttonGroup->addButton(MWV_off);
        MWV_off->setObjectName("MWV_off");
        MWV_off->setGeometry(QRect(320, 450, 110, 23));

        retranslateUi(CMWV);

        QMetaObject::connectSlotsByName(CMWV);
    } // setupUi

    void retranslateUi(QFrame *CMWV)
    {
        CMWV->setWindowTitle(QCoreApplication::translate("CMWV", "Frame", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CMWV", "Restore", nullptr));
        MWV_confirm->setText(QCoreApplication::translate("CMWV", "Confirm", nullptr));
        MWV_cancel->setText(QCoreApplication::translate("CMWV", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("CMWV", "Water Angle", nullptr));
        label_2->setText(QCoreApplication::translate("CMWV", "Water Speed", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CMWV", "Speed Units", nullptr));
        rb_Kn->setText(QCoreApplication::translate("CMWV", "Kn", nullptr));
        rb_kmph->setText(QCoreApplication::translate("CMWV", "Km", nullptr));
        rb_mps->setText(QCoreApplication::translate("CMWV", "M", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CMWV", "Wind Reference", nullptr));
        wind_RefTrue->setText(QCoreApplication::translate("CMWV", "True", nullptr));
        wind_RefRelative->setText(QCoreApplication::translate("CMWV", "Relative", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("CMWV", "Status", nullptr));
        status_Valid->setText(QCoreApplication::translate("CMWV", "Valid", nullptr));
        status_Invalid->setText(QCoreApplication::translate("CMWV", "Invalid", nullptr));
        label_3->setText(QCoreApplication::translate("CMWV", "Deg (0.0 - 359.9)", nullptr));
        label_4->setText(QCoreApplication::translate("CMWV", "Kn(0.0 - 100.0)", nullptr));
        MWV_on->setText(QCoreApplication::translate("CMWV", "ON", nullptr));
        MWV_off->setText(QCoreApplication::translate("CMWV", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMWV: public Ui_CMWV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMWV_H
