#include "CECHO.h"
#include "ui_CECHO.h"



CECHO::CECHO(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CECHO)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&CECHO::sendLOG);
}

CECHO::~CECHO()
{
    delete ui;
}

void CECHO::sendLOG()
{
    if(!ui->ECHO_on->isChecked()){
        return;
    }

    double depth = ui->Depth_spin->value();
    QString depthUnit = ui->Depth_combo->currentText();

    double depthMeters = 0.0;

    if(depthUnit == "Feet"){
        depthMeters = depth / 3.28084;
    }
    else if(depthUnit == "Fathoms"){
        depthMeters = depth / 0.546807;
    }
    else{
        depthMeters = depth;
    }

    double depthFeet = depthMeters * 3.28084;
    double depthFathoms = depthMeters * 0.546807;

    QString answer = QString("$SDDBT,%1,f,%2,M,%3,F")
                         .arg(depthFeet,0,'f',1)
                         .arg(depthMeters,0,'f',1)
                         .arg(depthFathoms,0,'f',1);

    QString checksum = MainWindow::calculateChecksum(answer);

    QString finalNMEA = answer +"*"+ checksum + "\n";

    qDebug()<< "ECHO Sentence:" << finalNMEA;
    emit nmeaSentenceReady(finalNMEA);
}

void CECHO::on_LOG_confirmn_clicked()
{
    if(!timer->isActive()){
        timer->start(1000);;
    }
}


void CECHO::on_LOG_cancel_clicked()
{
    timer->stop();
    this->hide();
}

