/********************************************************************************
** Form generated from reading UI file 'CECHO.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CECHO_H
#define UI_CECHO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CECHO
{
public:
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *Depth_combo;
    QPushButton *LOG_confirmn;
    QPushButton *LOG_cancel;
    QPushButton *LOG_restore;
    QDoubleSpinBox *Depth_spin;
    QRadioButton *ECHO_on;
    QRadioButton *ECHO_off;

    void setupUi(QFrame *CECHO)
    {
        if (CECHO->objectName().isEmpty())
            CECHO->setObjectName("CECHO");
        CECHO->resize(600, 600);
        label_3 = new QLabel(CECHO);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 117, 80, 18));
        label_4 = new QLabel(CECHO);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 117, 80, 18));
        Depth_combo = new QComboBox(CECHO);
        Depth_combo->addItem(QString());
        Depth_combo->addItem(QString());
        Depth_combo->addItem(QString());
        Depth_combo->setObjectName("Depth_combo");
        Depth_combo->setGeometry(QRect(366, 112, 140, 26));
        LOG_confirmn = new QPushButton(CECHO);
        LOG_confirmn->setObjectName("LOG_confirmn");
        LOG_confirmn->setGeometry(QRect(80, 217, 94, 26));
        LOG_cancel = new QPushButton(CECHO);
        LOG_cancel->setObjectName("LOG_cancel");
        LOG_cancel->setGeometry(QRect(420, 217, 94, 26));
        LOG_restore = new QPushButton(CECHO);
        LOG_restore->setObjectName("LOG_restore");
        LOG_restore->setGeometry(QRect(250, 217, 94, 26));
        Depth_spin = new QDoubleSpinBox(CECHO);
        Depth_spin->setObjectName("Depth_spin");
        Depth_spin->setGeometry(QRect(131, 110, 120, 30));
        Depth_spin->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ECHO_on = new QRadioButton(CECHO);
        ECHO_on->setObjectName("ECHO_on");
        ECHO_on->setGeometry(QRect(110, 40, 110, 23));
        ECHO_off = new QRadioButton(CECHO);
        ECHO_off->setObjectName("ECHO_off");
        ECHO_off->setGeometry(QRect(310, 40, 110, 23));

        retranslateUi(CECHO);

        QMetaObject::connectSlotsByName(CECHO);
    } // setupUi

    void retranslateUi(QFrame *CECHO)
    {
        CECHO->setWindowTitle(QCoreApplication::translate("CECHO", "Frame", nullptr));
        label_3->setText(QCoreApplication::translate("CECHO", "Depth", nullptr));
        label_4->setText(QCoreApplication::translate("CECHO", "(0-100)", nullptr));
        Depth_combo->setItemText(0, QCoreApplication::translate("CECHO", "Meters", nullptr));
        Depth_combo->setItemText(1, QCoreApplication::translate("CECHO", "Feet", nullptr));
        Depth_combo->setItemText(2, QCoreApplication::translate("CECHO", "Fathoms", nullptr));

        LOG_confirmn->setText(QCoreApplication::translate("CECHO", "Confirm", nullptr));
        LOG_cancel->setText(QCoreApplication::translate("CECHO", "Cancel", nullptr));
        LOG_restore->setText(QCoreApplication::translate("CECHO", "Restore", nullptr));
        ECHO_on->setText(QCoreApplication::translate("CECHO", "ON", nullptr));
        ECHO_off->setText(QCoreApplication::translate("CECHO", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CECHO: public Ui_CECHO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CECHO_H
