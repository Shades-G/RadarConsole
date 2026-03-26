/********************************************************************************
** Form generated from reading UI file 'CLOG.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOG_H
#define UI_CLOG_H

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

class Ui_CLOG
{
public:
    QGroupBox *waterBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *Water_Longitude;
    QDoubleSpinBox *Water_Transverse;
    QLabel *label_6;
    QLabel *label_7;
    QRadioButton *rb_Water_Valid;
    QRadioButton *rb_Water_Invalid;
    QGroupBox *groundBox;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QDoubleSpinBox *Ground_Longitude;
    QDoubleSpinBox *Ground_Transverse;
    QLabel *label_46;
    QLabel *label_47;
    QRadioButton *rb_Ground_Valid;
    QRadioButton *rb_Ground_Invalid;
    QPushButton *LOG_confirmn;
    QPushButton *LOG_restore;
    QPushButton *LOG_cancel;
    QRadioButton *LOG_on;
    QRadioButton *LOG_off;
    QButtonGroup *buttonGroup;

    void setupUi(QFrame *CLOG)
    {
        if (CLOG->objectName().isEmpty())
            CLOG->setObjectName("CLOG");
        CLOG->resize(600, 600);
        waterBox = new QGroupBox(CLOG);
        waterBox->setObjectName("waterBox");
        waterBox->setGeometry(QRect(20, 40, 550, 160));
        label_3 = new QLabel(waterBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(25, 44, 91, 20));
        label_4 = new QLabel(waterBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(25, 80, 91, 20));
        label_5 = new QLabel(waterBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 120, 66, 18));
        Water_Longitude = new QDoubleSpinBox(waterBox);
        Water_Longitude->setObjectName("Water_Longitude");
        Water_Longitude->setGeometry(QRect(190, 40, 191, 27));
        Water_Longitude->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Water_Transverse = new QDoubleSpinBox(waterBox);
        Water_Transverse->setObjectName("Water_Transverse");
        Water_Transverse->setGeometry(QRect(190, 80, 191, 27));
        Water_Transverse->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(waterBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 40, 66, 18));
        label_7 = new QLabel(waterBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 80, 66, 18));
        rb_Water_Valid = new QRadioButton(waterBox);
        rb_Water_Valid->setObjectName("rb_Water_Valid");
        rb_Water_Valid->setGeometry(QRect(190, 120, 110, 23));
        rb_Water_Invalid = new QRadioButton(waterBox);
        rb_Water_Invalid->setObjectName("rb_Water_Invalid");
        rb_Water_Invalid->setGeometry(QRect(350, 120, 110, 23));
        groundBox = new QGroupBox(CLOG);
        groundBox->setObjectName("groundBox");
        groundBox->setGeometry(QRect(20, 240, 550, 160));
        label_43 = new QLabel(groundBox);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(25, 44, 91, 20));
        label_44 = new QLabel(groundBox);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(25, 80, 91, 20));
        label_45 = new QLabel(groundBox);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(30, 120, 66, 18));
        Ground_Longitude = new QDoubleSpinBox(groundBox);
        Ground_Longitude->setObjectName("Ground_Longitude");
        Ground_Longitude->setGeometry(QRect(190, 40, 191, 27));
        Ground_Longitude->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Ground_Longitude->setDecimals(1);
        Ground_Longitude->setMaximum(99.000000000000000);
        Ground_Transverse = new QDoubleSpinBox(groundBox);
        Ground_Transverse->setObjectName("Ground_Transverse");
        Ground_Transverse->setGeometry(QRect(190, 80, 191, 27));
        Ground_Transverse->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Ground_Transverse->setDecimals(1);
        Ground_Transverse->setMaximum(99.000000000000000);
        label_46 = new QLabel(groundBox);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(420, 40, 66, 18));
        label_47 = new QLabel(groundBox);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(420, 80, 66, 18));
        rb_Ground_Valid = new QRadioButton(groundBox);
        rb_Ground_Valid->setObjectName("rb_Ground_Valid");
        rb_Ground_Valid->setGeometry(QRect(190, 120, 110, 23));
        rb_Ground_Invalid = new QRadioButton(groundBox);
        rb_Ground_Invalid->setObjectName("rb_Ground_Invalid");
        rb_Ground_Invalid->setGeometry(QRect(350, 120, 110, 23));
        LOG_confirmn = new QPushButton(CLOG);
        LOG_confirmn->setObjectName("LOG_confirmn");
        LOG_confirmn->setGeometry(QRect(80, 480, 94, 26));
        LOG_restore = new QPushButton(CLOG);
        LOG_restore->setObjectName("LOG_restore");
        LOG_restore->setGeometry(QRect(250, 480, 94, 26));
        LOG_cancel = new QPushButton(CLOG);
        LOG_cancel->setObjectName("LOG_cancel");
        LOG_cancel->setGeometry(QRect(420, 480, 94, 26));
        LOG_on = new QRadioButton(CLOG);
        buttonGroup = new QButtonGroup(CLOG);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(LOG_on);
        LOG_on->setObjectName("LOG_on");
        LOG_on->setGeometry(QRect(140, 420, 110, 23));
        LOG_off = new QRadioButton(CLOG);
        buttonGroup->addButton(LOG_off);
        LOG_off->setObjectName("LOG_off");
        LOG_off->setGeometry(QRect(340, 420, 110, 23));

        retranslateUi(CLOG);

        QMetaObject::connectSlotsByName(CLOG);
    } // setupUi

    void retranslateUi(QFrame *CLOG)
    {
        CLOG->setWindowTitle(QCoreApplication::translate("CLOG", "Frame", nullptr));
        waterBox->setTitle(QCoreApplication::translate("CLOG", "WATER SPEED", nullptr));
        label_3->setText(QCoreApplication::translate("CLOG", "Longitudinal", nullptr));
        label_4->setText(QCoreApplication::translate("CLOG", "Transverse", nullptr));
        label_5->setText(QCoreApplication::translate("CLOG", "Status", nullptr));
        label_6->setText(QCoreApplication::translate("CLOG", "Kn(0-99)", nullptr));
        label_7->setText(QCoreApplication::translate("CLOG", "Kn(0-99)", nullptr));
        rb_Water_Valid->setText(QCoreApplication::translate("CLOG", "Valid", nullptr));
        rb_Water_Invalid->setText(QCoreApplication::translate("CLOG", "Invalid", nullptr));
        groundBox->setTitle(QCoreApplication::translate("CLOG", "GROUND SPEED", nullptr));
        label_43->setText(QCoreApplication::translate("CLOG", "Longitudinal", nullptr));
        label_44->setText(QCoreApplication::translate("CLOG", "Transverse", nullptr));
        label_45->setText(QCoreApplication::translate("CLOG", "Status", nullptr));
        label_46->setText(QCoreApplication::translate("CLOG", "Kn(0-99)", nullptr));
        label_47->setText(QCoreApplication::translate("CLOG", "Kn(0-99)", nullptr));
        rb_Ground_Valid->setText(QCoreApplication::translate("CLOG", "Valid", nullptr));
        rb_Ground_Invalid->setText(QCoreApplication::translate("CLOG", "Invalid", nullptr));
        LOG_confirmn->setText(QCoreApplication::translate("CLOG", "Confirm", nullptr));
        LOG_restore->setText(QCoreApplication::translate("CLOG", "Restore", nullptr));
        LOG_cancel->setText(QCoreApplication::translate("CLOG", "Cancel", nullptr));
        LOG_on->setText(QCoreApplication::translate("CLOG", "ON", nullptr));
        LOG_off->setText(QCoreApplication::translate("CLOG", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLOG: public Ui_CLOG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOG_H
