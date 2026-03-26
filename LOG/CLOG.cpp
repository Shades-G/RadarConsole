#include "CLOG.h"
#include "ui_CLOG.h"


CLOG::CLOG(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CLOG)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&CLOG::sendNMEA);
}

CLOG::~CLOG()
{
    delete ui;
}

void CLOG::sendNMEA()
{
    if(!ui->LOG_on->isChecked()){
        return;
    }

    double Water_long = ui->Water_Longitude->value();
    double Water_Tran = ui->Water_Transverse->value();
    QString waterStatus = ui->rb_Water_Valid->isChecked() ? "A" :"V";

    double Ground_long = ui->Ground_Longitude->value();
    double Ground_Tran = ui->Ground_Transverse->value();
    QString groundStatus = ui->rb_Ground_Valid->isChecked() ? "A" :"V";

    QString answer = QString("VMVBW,%1,%2,%3,%4,%5,%6")
                         .arg(Water_long, 0 , 'f' , 1)
                         .arg(Water_Tran, 0 , 'f' , 1)
                         .arg(waterStatus)
                         .arg(Ground_long, 0 , 'f' , 1)
                         .arg(Ground_Tran, 0 , 'f' , 1)
                         .arg(groundStatus);

    QString checksum = MainWindow::calculateChecksum(answer);

    QString finalNMEA = "$" + answer + "*" + checksum + "\n"  ;

    qDebug() << "LOG Sentence:" << finalNMEA;

    emit nmeaSentenceReady(finalNMEA);
};
void CLOG::on_LOG_confirmn_clicked()
{
    if(!timer->isActive()){
        timer->start(1000);
    }
    sendNMEA();
}


void CLOG::on_LOG_cancel_clicked()
{
    timer->stop();
    this->hide();
}

