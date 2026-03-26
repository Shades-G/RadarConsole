#include "CAIS.h"
#include "ui_CAIS.h"
#include "AIS/CAIS.h"
#include "mainwindow.h"
#include <QDebug>

CAIS::CAIS(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CAIS)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&CAIS::sendAIS);
}

CAIS::~CAIS()
{
    delete ui;
}


void CAIS::on_Confirm_AIS_clicked()
{
    timer->start(1000);
}


void CAIS::on_Cancel_AIS_clicked()
{
    timer->stop();
}

void CAIS::sendAIS()
{
    QString totalMsg = QString::number(ui->Message_SB->value());
    QString msgNum = QString::number(ui->Number_SB->value());
    QString msgId = QString::number(ui->Identifier_SB->value());

    QString channel = "A";
    if(ui->channel_B->isChecked()){
        channel = "B";
    }

    QString Message = "13el0?P000H@2Vq";
    QString fillBits = QString::number(ui->Bits_SB->value());

    QString answer = "AIVDM,"+ totalMsg + "," +
                    msgNum   + "," +
                    msgId    + "," +
                    channel  + "," +
                    Message  + "," +
                    fillBits;



    QString checksum = MainWindow::calculateChecksum(answer);

    QString finalNMEA = "!" + answer + "*" + checksum + "\r\n";

    qDebug() << "VDM:" << finalNMEA.trimmed();

    emit nmeaSentenceReady(finalNMEA);

}

// void CAIS::updateUIFromNetwork(long mmsi, double lat, double lon, double speed)
// {
//     ui->
// }
