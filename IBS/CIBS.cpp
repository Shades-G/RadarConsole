#include "ui_CIBS.h"
#include <QDebug>
#include <QString>
#include <QtMath>
#include "IBS/CIBS.h"
#include "mainwindow.h"
#include "SimulatedTarget/SimulatedTarget.h"

CIBS::CIBS(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CIBS)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&CIBS::sendTTM);
}

CIBS::~CIBS()
{
    delete ui;
}

void CIBS::on_TTM_confirm_clicked()
{
    sendTTM();
    qDebug() <<"TTM transmission started: " ;
    timer->start(1000);
}


void CIBS::on_TTM_cancel_clicked()
{   qDebug()<<"TTM transmission stopped" ;
    timer->stop();
}

void CIBS::sendTTM()
{
    QString tgtNum = QString("%1").arg(ui->tgt_num_sb->value(), 2, 10, QChar('0'));
    QString tgtRange = QString::number(ui->tgt_range->value(), 'f', 2);
    QString trueBearing = QString::number(ui->true_bearing->value(), 'f', 1);
    QString tgtSpeed = QString::number(ui->tgt_speed->value(), 'f', 1);
    QString tgtCourse = QString::number(ui->tgt_course->value(), 'f', 1);
    QString cpaDistance = QString::number(ui->cpa_distance->value(), 'f', 1);
    QString cpaTime = QString::number(ui->cpa_time->value(), 'f', 1);

    QString speedUnits = "N";
    if(ui->Kmph_rb->isChecked()) speedUnits = "K";
    else if (ui->statute_rb->isChecked()) speedUnits = "S";

    QString tgtName = ui->tgt_name_cb->currentText().left(8);
    QString tgtStatus = ui->tgt_status_cb->currentText().left(1);
    QString tgtReference = ui->referenceTgt->isChecked() ? "R" : "T";

    QString hrs = QString("%1").arg(ui->hrs_sb->value(), 2, 10, QChar('0'));
    QString min = QString("%1").arg(ui->min_sb->value(), 2, 10, QChar('0'));
    QString sec = QString("%1").arg(ui->sec_sb->value(), 2, 10, QChar('0'));
    QString utc = hrs + min + sec;

    QString acq = ui->type_of_acq->currentText().left(1);

    // 2. Build the core RATTM String
    QString answer = "RATTM," + tgtNum + "," + tgtRange + "," + trueBearing + ",T," +
                     tgtSpeed + "," + tgtCourse + ",T," + cpaDistance + "," +
                     cpaTime + "," + speedUnits + "," + tgtName + "," + tgtStatus + "," +
                     tgtReference + "," + utc + "," + acq;

    // 3. Calculate Checksum (Inline for safety)
    int checksumVal = 0;
    for (int i = 0; i < answer.length(); ++i) {
        checksumVal ^= answer.at(i).toLatin1();
    }
    QString checksum = QString("%1").arg(checksumVal, 2, 16, QChar('0')).toUpper();

    // 4. Final Format and Broadcast
    QString finalNMEA = "$" + answer + "*" + checksum + "\r\n";

    qDebug() << "--- IBS MODULE --- Generated:" << finalNMEA.trimmed();
    emit nmeaSentenceReady(finalNMEA);

}

void CIBS::updateUIFromNetwork(const QStringList &parts)
{
    if (parts.size() < 12) return;

    ui->tgt_num_sb->setValue(parts[1].toInt());
    ui->tgt_range->setValue(parts[2].toDouble());
    ui->true_bearing->setValue(parts[3].toDouble());
    ui->tgt_speed->setValue(parts[5].toDouble());
    ui->tgt_course->setValue(parts[6].toDouble());
    ui->cpa_distance->setValue(parts[8].toDouble());
    ui->cpa_time->setValue(parts[9].toDouble());
    ui->tgt_name_cb->setCurrentText(parts[11]);
}
