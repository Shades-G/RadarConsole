#include "AWOS/CMWV.h"
#include "ui_CMWV.h"
#include  <QDebug>
#include "mainwindow.h"
// #include "GlobalLoop.h"

// QTimer* GlobalLoop::timer = nullptr;

CMWV::CMWV(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CMWV)
{
    ui->setupUi(this);
    ui->wind_RefRelative->setChecked(true);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&CMWV::sendNMEA);
}

CMWV::~CMWV()
{
    delete ui;
}

QString CMWV::conditionStr(double water_Angle, QString reference, double water_Speed, QString unit, QString status)
{
    QString answer = QString("WIMWV,%1,%2,%3,%4,%5")
        .arg(water_Angle, 3, 'f', 1)
        .arg(reference)
        .arg(water_Speed, 0, 'f', 1)
        .arg(unit)
        .arg(status);

    QString checksum = MainWindow::calculateChecksum(answer);
    return "$" + answer + "*" +checksum + "\n";


}

void CMWV::sendNMEA()
{
    if(!ui->MWV_on->isChecked()){
        return;
    }

    double water_Angle = ui->waterAngle->value();
    double water_Speed = ui->waterSpeed->value();

    QString unit = "Kn";
    if(ui->rb_kmph->isChecked()) unit = "Km";
    else if(ui->rb_mps->isChecked()) unit = "M";

    QString status = "A";
    if(ui->status_Invalid->isChecked()){
        status = "V";
    }

    if (ui->wind_RefRelative->isChecked())
    {
        QString packet = conditionStr(water_Angle,"R",water_Speed,unit,status);
        qDebug() << "MWV Relative" << packet;
        emit nmeaSentenceReady(packet);
    }
    else
    {
        QString packetTrue = conditionStr(water_Angle,"T",water_Speed,unit,status);
        qDebug()<< "MWV True:" << packetTrue;
        emit nmeaSentenceReady(packetTrue);
        QString packetRel = conditionStr(water_Angle,"R",water_Speed,unit,status);
        qDebug()<<"MWV Relative: "<< packetRel;
        emit nmeaSentenceReady(packetRel);
    }

};

void CMWV::on_MWV_confirm_clicked()
{
    if(!timer->isActive()){
        timer->start(1000);
    }

    sendNMEA();
}


void CMWV::on_MWV_cancel_clicked()
{
    timer->stop();
    this->hide();
}

