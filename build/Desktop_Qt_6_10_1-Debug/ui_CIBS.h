/********************************************************************************
** Form generated from reading UI file 'CIBS.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIBS_H
#define UI_CIBS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CIBS
{
public:
    QGroupBox *groupBox_8;
    QLabel *label_15;
    QSpinBox *tgt_num_sb;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QSpinBox *cpa_time;
    QLabel *label_30;
    QGroupBox *units;
    QRadioButton *knots_rb;
    QRadioButton *Kmph_rb;
    QRadioButton *statute_rb;
    QLabel *label_31;
    QComboBox *tgt_name_cb;
    QLabel *label_32;
    QLabel *label_33;
    QSpinBox *sec_sb;
    QLabel *label_34;
    QSpinBox *hrs_sb;
    QLabel *label_35;
    QSpinBox *min_sb;
    QLabel *label_36;
    QPushButton *TTM_confirm;
    QPushButton *TTM_cancel;
    QGroupBox *groupBox_10;
    QRadioButton *course_bearing_T;
    QRadioButton *course_bearing_F;
    QGroupBox *groupBox_11;
    QRadioButton *tgt_bearing_T;
    QRadioButton *tgt_bearing_R;
    QComboBox *tgt_status_cb;
    QLabel *label_17;
    QDoubleSpinBox *tgt_range;
    QDoubleSpinBox *true_bearing;
    QDoubleSpinBox *tgt_course;
    QCheckBox *referenceTgt;
    QComboBox *type_of_acq;
    QDoubleSpinBox *tgt_speed;
    QDoubleSpinBox *cpa_distance;

    void setupUi(QFrame *CIBS)
    {
        if (CIBS->objectName().isEmpty())
            CIBS->setObjectName("CIBS");
        CIBS->resize(600, 609);
        groupBox_8 = new QGroupBox(CIBS);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(20, 10, 600, 600));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 30, 101, 31));
        tgt_num_sb = new QSpinBox(groupBox_8);
        tgt_num_sb->setObjectName("tgt_num_sb");
        tgt_num_sb->setGeometry(QRect(10, 60, 71, 31));
        tgt_num_sb->setMaximum(999);
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(90, 60, 61, 31));
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(270, 60, 91, 31));
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 130, 91, 31));
        label_20 = new QLabel(groupBox_8);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(180, 130, 70, 31));
        label_22 = new QLabel(groupBox_8);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 190, 101, 31));
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(90, 220, 71, 31));
        label_24 = new QLabel(groupBox_8);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(210, 190, 101, 31));
        label_25 = new QLabel(groupBox_8);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(280, 220, 71, 31));
        label_27 = new QLabel(groupBox_8);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(30, 280, 101, 20));
        label_28 = new QLabel(groupBox_8);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(90, 300, 71, 31));
        label_29 = new QLabel(groupBox_8);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(200, 280, 101, 20));
        cpa_time = new QSpinBox(groupBox_8);
        cpa_time->setObjectName("cpa_time");
        cpa_time->setGeometry(QRect(190, 300, 71, 31));
        cpa_time->setMaximum(59);
        label_30 = new QLabel(groupBox_8);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(270, 300, 81, 31));
        units = new QGroupBox(groupBox_8);
        units->setObjectName("units");
        units->setGeometry(QRect(380, 280, 181, 61));
        knots_rb = new QRadioButton(units);
        knots_rb->setObjectName("knots_rb");
        knots_rb->setGeometry(QRect(10, 30, 41, 26));
        Kmph_rb = new QRadioButton(units);
        Kmph_rb->setObjectName("Kmph_rb");
        Kmph_rb->setGeometry(QRect(70, 30, 41, 26));
        statute_rb = new QRadioButton(units);
        statute_rb->setObjectName("statute_rb");
        statute_rb->setGeometry(QRect(130, 30, 41, 26));
        label_31 = new QLabel(groupBox_8);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 370, 91, 20));
        tgt_name_cb = new QComboBox(groupBox_8);
        tgt_name_cb->addItem(QString());
        tgt_name_cb->addItem(QString());
        tgt_name_cb->addItem(QString());
        tgt_name_cb->addItem(QString());
        tgt_name_cb->addItem(QString());
        tgt_name_cb->addItem(QString());
        tgt_name_cb->setObjectName("tgt_name_cb");
        tgt_name_cb->setGeometry(QRect(108, 363, 141, 31));
        label_32 = new QLabel(groupBox_8);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(320, 359, 91, 31));
        label_33 = new QLabel(groupBox_8);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(250, 410, 81, 20));
        sec_sb = new QSpinBox(groupBox_8);
        sec_sb->setObjectName("sec_sb");
        sec_sb->setGeometry(QRect(350, 430, 71, 29));
        sec_sb->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        sec_sb->setMaximum(59);
        label_34 = new QLabel(groupBox_8);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(350, 410, 63, 20));
        hrs_sb = new QSpinBox(groupBox_8);
        hrs_sb->setObjectName("hrs_sb");
        hrs_sb->setGeometry(QRect(150, 430, 71, 29));
        hrs_sb->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        hrs_sb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        hrs_sb->setMaximum(23);
        label_35 = new QLabel(groupBox_8);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(150, 410, 71, 20));
        min_sb = new QSpinBox(groupBox_8);
        min_sb->setObjectName("min_sb");
        min_sb->setGeometry(QRect(250, 430, 71, 29));
        min_sb->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);"));
        min_sb->setMaximum(59);
        label_36 = new QLabel(groupBox_8);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(10, 470, 131, 31));
        TTM_confirm = new QPushButton(groupBox_8);
        TTM_confirm->setObjectName("TTM_confirm");
        TTM_confirm->setGeometry(QRect(190, 530, 84, 28));
        TTM_cancel = new QPushButton(groupBox_8);
        TTM_cancel->setObjectName("TTM_cancel");
        TTM_cancel->setGeometry(QRect(290, 530, 84, 28));
        groupBox_10 = new QGroupBox(groupBox_8);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(410, 200, 101, 51));
        course_bearing_T = new QRadioButton(groupBox_10);
        course_bearing_T->setObjectName("course_bearing_T");
        course_bearing_T->setGeometry(QRect(10, 30, 31, 16));
        course_bearing_T->setChecked(true);
        course_bearing_F = new QRadioButton(groupBox_10);
        course_bearing_F->setObjectName("course_bearing_F");
        course_bearing_F->setGeometry(QRect(50, 30, 50, 16));
        course_bearing_F->setCheckable(false);
        groupBox_11 = new QGroupBox(groupBox_8);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(410, 33, 130, 51));
        tgt_bearing_T = new QRadioButton(groupBox_11);
        tgt_bearing_T->setObjectName("tgt_bearing_T");
        tgt_bearing_T->setGeometry(QRect(10, 30, 31, 16));
        tgt_bearing_T->setCheckable(true);
        tgt_bearing_T->setChecked(true);
        tgt_bearing_R = new QRadioButton(groupBox_11);
        tgt_bearing_R->setObjectName("tgt_bearing_R");
        tgt_bearing_R->setGeometry(QRect(50, 30, 50, 16));
        tgt_bearing_R->setCheckable(false);
        tgt_status_cb = new QComboBox(groupBox_8);
        tgt_status_cb->addItem(QString());
        tgt_status_cb->addItem(QString());
        tgt_status_cb->addItem(QString());
        tgt_status_cb->setObjectName("tgt_status_cb");
        tgt_status_cb->setGeometry(QRect(420, 363, 50, 31));
        label_17 = new QLabel(groupBox_8);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(190, 30, 101, 31));
        tgt_range = new QDoubleSpinBox(groupBox_8);
        tgt_range->setObjectName("tgt_range");
        tgt_range->setGeometry(QRect(190, 60, 70, 27));
        tgt_range->setMaximum(1000.000000000000000);
        true_bearing = new QDoubleSpinBox(groupBox_8);
        true_bearing->setObjectName("true_bearing");
        true_bearing->setGeometry(QRect(106, 133, 70, 27));
        true_bearing->setMaximum(359.990000000000009);
        tgt_course = new QDoubleSpinBox(groupBox_8);
        tgt_course->setObjectName("tgt_course");
        tgt_course->setGeometry(QRect(204, 222, 70, 30));
        tgt_course->setMaximum(1000.000000000000000);
        referenceTgt = new QCheckBox(groupBox_8);
        referenceTgt->setObjectName("referenceTgt");
        referenceTgt->setGeometry(QRect(295, 475, 150, 23));
        type_of_acq = new QComboBox(CIBS);
        type_of_acq->addItem(QString());
        type_of_acq->addItem(QString());
        type_of_acq->addItem(QString());
        type_of_acq->addItem(QString());
        type_of_acq->setObjectName("type_of_acq");
        type_of_acq->setGeometry(QRect(170, 480, 50, 31));
        tgt_speed = new QDoubleSpinBox(CIBS);
        tgt_speed->setObjectName("tgt_speed");
        tgt_speed->setGeometry(QRect(37, 232, 70, 27));
        tgt_speed->setMaximum(1000.000000000000000);
        cpa_distance = new QDoubleSpinBox(CIBS);
        cpa_distance->setObjectName("cpa_distance");
        cpa_distance->setGeometry(QRect(34, 313, 70, 27));
        cpa_distance->setMaximum(1000.000000000000000);

        retranslateUi(CIBS);

        QMetaObject::connectSlotsByName(CIBS);
    } // setupUi

    void retranslateUi(QFrame *CIBS)
    {
        CIBS->setWindowTitle(QCoreApplication::translate("CIBS", "Frame", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("CIBS", "TTM", nullptr));
        label_15->setText(QCoreApplication::translate("CIBS", "Target Number", nullptr));
        label_16->setText(QCoreApplication::translate("CIBS", "(0 - 999)", nullptr));
        label_18->setText(QCoreApplication::translate("CIBS", "M(0 - 1000)", nullptr));
        label_19->setText(QCoreApplication::translate("CIBS", "True Bearing", nullptr));
        label_20->setText(QCoreApplication::translate("CIBS", "D(0 - 360)", nullptr));
        label_22->setText(QCoreApplication::translate("CIBS", "Target Speed", nullptr));
        label_23->setText(QCoreApplication::translate("CIBS", "(0 - 1000)", nullptr));
        label_24->setText(QCoreApplication::translate("CIBS", "Target Course", nullptr));
        label_25->setText(QCoreApplication::translate("CIBS", "(0 - 1000)", nullptr));
        label_27->setText(QCoreApplication::translate("CIBS", "CPA Distance", nullptr));
        label_28->setText(QCoreApplication::translate("CIBS", "(0 - 1000)", nullptr));
        label_29->setText(QCoreApplication::translate("CIBS", "CPA Time", nullptr));
        label_30->setText(QCoreApplication::translate("CIBS", "Min(0 - 59)", nullptr));
        units->setTitle(QCoreApplication::translate("CIBS", "Units", nullptr));
        knots_rb->setText(QCoreApplication::translate("CIBS", "N", nullptr));
        Kmph_rb->setText(QCoreApplication::translate("CIBS", "K", nullptr));
        statute_rb->setText(QCoreApplication::translate("CIBS", "S", nullptr));
        label_31->setText(QCoreApplication::translate("CIBS", "Target name:", nullptr));
        tgt_name_cb->setItemText(0, QString());
        tgt_name_cb->setItemText(1, QCoreApplication::translate("CIBS", "Alpha", nullptr));
        tgt_name_cb->setItemText(2, QCoreApplication::translate("CIBS", "Beta", nullptr));
        tgt_name_cb->setItemText(3, QCoreApplication::translate("CIBS", "Gamma", nullptr));
        tgt_name_cb->setItemText(4, QCoreApplication::translate("CIBS", "Sigma", nullptr));
        tgt_name_cb->setItemText(5, QString());

        label_32->setText(QCoreApplication::translate("CIBS", "Target Status:", nullptr));
        label_33->setText(QCoreApplication::translate("CIBS", "MM(0-59)", nullptr));
        label_34->setText(QCoreApplication::translate("CIBS", "SS(0-59)", nullptr));
        label_35->setText(QCoreApplication::translate("CIBS", "HH(0-23)", nullptr));
        label_36->setText(QCoreApplication::translate("CIBS", "Type of Acquisition:", nullptr));
        TTM_confirm->setText(QCoreApplication::translate("CIBS", "Confirm", nullptr));
        TTM_cancel->setText(QCoreApplication::translate("CIBS", "Cancel", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("CIBS", "Course Ref", nullptr));
        course_bearing_T->setText(QCoreApplication::translate("CIBS", "T", nullptr));
        course_bearing_F->setText(QCoreApplication::translate("CIBS", "Rel", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("CIBS", "Target Bearing Ref", nullptr));
        tgt_bearing_T->setText(QCoreApplication::translate("CIBS", "T", nullptr));
        tgt_bearing_R->setText(QCoreApplication::translate("CIBS", "Rel", nullptr));
        tgt_status_cb->setItemText(0, QCoreApplication::translate("CIBS", "L", nullptr));
        tgt_status_cb->setItemText(1, QCoreApplication::translate("CIBS", "Q", nullptr));
        tgt_status_cb->setItemText(2, QCoreApplication::translate("CIBS", "T", nullptr));

        label_17->setText(QCoreApplication::translate("CIBS", "Target Range", nullptr));
        referenceTgt->setText(QCoreApplication::translate("CIBS", "Reference Target", nullptr));
        type_of_acq->setItemText(0, QString());
        type_of_acq->setItemText(1, QCoreApplication::translate("CIBS", "M", nullptr));
        type_of_acq->setItemText(2, QCoreApplication::translate("CIBS", "R", nullptr));
        type_of_acq->setItemText(3, QCoreApplication::translate("CIBS", "A", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CIBS: public Ui_CIBS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIBS_H
