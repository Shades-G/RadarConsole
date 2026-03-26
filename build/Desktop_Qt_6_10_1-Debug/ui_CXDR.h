/********************************************************************************
** Form generated from reading UI file 'CXDR.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXDR_H
#define UI_CXDR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CXDR
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *sp_TranMeasurement;
    QComboBox *cb_TranType;
    QComboBox *cb_Unit;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *XDR_confirm;
    QPushButton *XDR_cancel;
    QComboBox *cb_Tid;
    QRadioButton *XDR_on;
    QRadioButton *XDR_off;
    QButtonGroup *buttonGroup;

    void setupUi(QFrame *CXDR)
    {
        if (CXDR->objectName().isEmpty())
            CXDR->setObjectName("CXDR");
        CXDR->resize(600, 600);
        label = new QLabel(CXDR);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 70, 161, 20));
        label_2 = new QLabel(CXDR);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 118, 161, 20));
        label_3 = new QLabel(CXDR);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 166, 161, 20));
        label_4 = new QLabel(CXDR);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 214, 161, 20));
        sp_TranMeasurement = new QDoubleSpinBox(CXDR);
        sp_TranMeasurement->setObjectName("sp_TranMeasurement");
        sp_TranMeasurement->setGeometry(QRect(274, 111, 191, 31));
        sp_TranMeasurement->setAlignment(Qt::AlignmentFlag::AlignCenter);
        sp_TranMeasurement->setDecimals(1);
        sp_TranMeasurement->setMaximum(1000.000000000000000);
        cb_TranType = new QComboBox(CXDR);
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->addItem(QString());
        cb_TranType->setObjectName("cb_TranType");
        cb_TranType->setGeometry(QRect(270, 60, 191, 30));
        cb_Unit = new QComboBox(CXDR);
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->addItem(QString());
        cb_Unit->setObjectName("cb_Unit");
        cb_Unit->setGeometry(QRect(270, 164, 191, 30));
        label_5 = new QLabel(CXDR);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(490, 117, 81, 20));
        pushButton_2 = new QPushButton(CXDR);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(239, 360, 100, 26));
        XDR_confirm = new QPushButton(CXDR);
        XDR_confirm->setObjectName("XDR_confirm");
        XDR_confirm->setGeometry(QRect(69, 360, 100, 26));
        XDR_cancel = new QPushButton(CXDR);
        XDR_cancel->setObjectName("XDR_cancel");
        XDR_cancel->setGeometry(QRect(409, 360, 100, 26));
        cb_Tid = new QComboBox(CXDR);
        cb_Tid->addItem(QString());
        cb_Tid->addItem(QString());
        cb_Tid->addItem(QString());
        cb_Tid->addItem(QString());
        cb_Tid->addItem(QString());
        cb_Tid->setObjectName("cb_Tid");
        cb_Tid->setGeometry(QRect(270, 210, 190, 30));
        XDR_on = new QRadioButton(CXDR);
        buttonGroup = new QButtonGroup(CXDR);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(XDR_on);
        XDR_on->setObjectName("XDR_on");
        XDR_on->setGeometry(QRect(130, 300, 110, 23));
        XDR_off = new QRadioButton(CXDR);
        buttonGroup->addButton(XDR_off);
        XDR_off->setObjectName("XDR_off");
        XDR_off->setGeometry(QRect(330, 300, 110, 23));

        retranslateUi(CXDR);

        QMetaObject::connectSlotsByName(CXDR);
    } // setupUi

    void retranslateUi(QFrame *CXDR)
    {
        CXDR->setWindowTitle(QCoreApplication::translate("CXDR", "Frame", nullptr));
        label->setText(QCoreApplication::translate("CXDR", "Transducer Type ", nullptr));
        label_2->setText(QCoreApplication::translate("CXDR", "Measurement Data", nullptr));
        label_3->setText(QCoreApplication::translate("CXDR", "Unit of Measure", nullptr));
        label_4->setText(QCoreApplication::translate("CXDR", "Transducer ID", nullptr));
        cb_TranType->setItemText(0, QCoreApplication::translate("CXDR", "C", nullptr));
        cb_TranType->setItemText(1, QCoreApplication::translate("CXDR", "A", nullptr));
        cb_TranType->setItemText(2, QCoreApplication::translate("CXDR", "D", nullptr));
        cb_TranType->setItemText(3, QCoreApplication::translate("CXDR", "F", nullptr));
        cb_TranType->setItemText(4, QCoreApplication::translate("CXDR", "N", nullptr));
        cb_TranType->setItemText(5, QCoreApplication::translate("CXDR", "P", nullptr));
        cb_TranType->setItemText(6, QCoreApplication::translate("CXDR", "R", nullptr));
        cb_TranType->setItemText(7, QCoreApplication::translate("CXDR", "T", nullptr));
        cb_TranType->setItemText(8, QCoreApplication::translate("CXDR", "H", nullptr));
        cb_TranType->setItemText(9, QCoreApplication::translate("CXDR", "V", nullptr));
        cb_TranType->setItemText(10, QCoreApplication::translate("CXDR", "G", nullptr));
        cb_TranType->setItemText(11, QCoreApplication::translate("CXDR", "I", nullptr));
        cb_TranType->setItemText(12, QCoreApplication::translate("CXDR", "U", nullptr));
        cb_TranType->setItemText(13, QCoreApplication::translate("CXDR", "S", nullptr));
        cb_TranType->setItemText(14, QCoreApplication::translate("CXDR", "L", nullptr));

        cb_Unit->setItemText(0, QCoreApplication::translate("CXDR", "Air Temp", nullptr));
        cb_Unit->setItemText(1, QCoreApplication::translate("CXDR", "Dew Point ", nullptr));
        cb_Unit->setItemText(2, QCoreApplication::translate("CXDR", "Angular Displacement", nullptr));
        cb_Unit->setItemText(3, QCoreApplication::translate("CXDR", "Linear Displacement ", nullptr));
        cb_Unit->setItemText(4, QCoreApplication::translate("CXDR", "Frequency", nullptr));
        cb_Unit->setItemText(5, QCoreApplication::translate("CXDR", "Flow Rate", nullptr));
        cb_Unit->setItemText(6, QCoreApplication::translate("CXDR", "Air Pressure", nullptr));
        cb_Unit->setItemText(7, QCoreApplication::translate("CXDR", "Tachometer", nullptr));
        cb_Unit->setItemText(8, QCoreApplication::translate("CXDR", "Relative Humidity", nullptr));
        cb_Unit->setItemText(9, QCoreApplication::translate("CXDR", "Volume", nullptr));
        cb_Unit->setItemText(10, QCoreApplication::translate("CXDR", "Generic", nullptr));
        cb_Unit->setItemText(11, QCoreApplication::translate("CXDR", "Current ", nullptr));
        cb_Unit->setItemText(12, QCoreApplication::translate("CXDR", "Voltage", nullptr));
        cb_Unit->setItemText(13, QCoreApplication::translate("CXDR", "Force", nullptr));
        cb_Unit->setItemText(14, QCoreApplication::translate("CXDR", "Switch / Valve", nullptr));
        cb_Unit->setItemText(15, QCoreApplication::translate("CXDR", "Salinity", nullptr));
        cb_Unit->setItemText(16, QCoreApplication::translate("CXDR", "Visibility", nullptr));

        label_5->setText(QCoreApplication::translate("CXDR", "0.0 - 1000.0", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CXDR", "Restore", nullptr));
        XDR_confirm->setText(QCoreApplication::translate("CXDR", "Confirm", nullptr));
        XDR_cancel->setText(QCoreApplication::translate("CXDR", "Cancel", nullptr));
        cb_Tid->setItemText(0, QCoreApplication::translate("CXDR", "1", nullptr));
        cb_Tid->setItemText(1, QCoreApplication::translate("CXDR", "2", nullptr));
        cb_Tid->setItemText(2, QCoreApplication::translate("CXDR", "3", nullptr));
        cb_Tid->setItemText(3, QCoreApplication::translate("CXDR", "4", nullptr));
        cb_Tid->setItemText(4, QCoreApplication::translate("CXDR", "5", nullptr));

        XDR_on->setText(QCoreApplication::translate("CXDR", "ON", nullptr));
        XDR_off->setText(QCoreApplication::translate("CXDR", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CXDR: public Ui_CXDR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXDR_H
