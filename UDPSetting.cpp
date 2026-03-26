#include "UDPSetting.h"
#include "ui_UDPSetting.h"
#include <QHostAddress>

UDPSetting::UDPSetting(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::UDPSetting)
{
    ui->setupUi(this);

    //  this->setWindowFlags(Qt::Window);

    udpSocket = new QUdpSocket(this);
    isTransmitting = false;
    connect(udpSocket,&QUdpSocket::readyRead,this,&UDPSetting::onReadyRead);

    ui->udp_ip->setText("127.0.0.1");//default
    ui->Sender_line->setText("5000");
    ui->Receiver_line->setText("6000");
    ui->UDP_stop->setEnabled(false);
    ui->broadcast->setChecked(true);
    ui->udp_ip->setEnabled(false);//disable ip box
}

UDPSetting::~UDPSetting()
{
    delete ui;
}

void UDPSetting::on_UDP_start_clicked()
{
    quint16 senderPort = ui->Sender_line->text().toUShort();
    udpSocket->abort();

    if(udpSocket->bind(senderPort, QUdpSocket::ShareAddress))
    {
        qDebug() << "UDP sending from Port: "<<senderPort;
        isTransmitting = true;

        //fix ui values
        ui->UDP_start->setEnabled(false);
        ui->UDP_stop->setEnabled(true);
        ui->Sender_line->setEnabled(false);
        ui->Receiver_line->setEnabled(false);
    }
     else
    {
        qDebug()<< "UDP Error" << senderPort;
    }
}


void UDPSetting::on_UDP_stop_clicked()
{
    isTransmitting = false;
    udpSocket->abort();

    qDebug() << "UDP Stopped";

    // Unlock the UI
    ui->UDP_start->setEnabled(true);
    ui->UDP_stop->setEnabled(false);
    ui->Sender_line->setEnabled(true);
    ui->Receiver_line->setEnabled(true);

}

void UDPSetting::sendData(const QString &nmeaSentence)
{
    if(!isTransmitting) return;
    quint16 receiverPort = ui->Receiver_line->text().toUShort();
    QHostAddress tgtAddress;

    if(ui->broadcast->isChecked()){
        tgtAddress = QHostAddress::Broadcast;
    }else{
        QString udpIP =ui->udp_ip->text();
        tgtAddress.setAddress(udpIP);

        if(tgtAddress.isNull()){
            qDebug()<< "Invalid IP. DEFAULTING TO LOCALHOST" ;
            tgtAddress = QHostAddress::LocalHost;
        }
    }

    udpSocket->writeDatagram(nmeaSentence.toUtf8(), tgtAddress, receiverPort);
}

void UDPSetting::on_broadcast_toggled(bool checked)
{
    if(checked){
        ui->udp_ip->setEnabled(false);
    }
    else{
        ui->udp_ip->setEnabled(true);
    }
}

void UDPSetting::onReadyRead()
{
    while(udpSocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(),datagram.size());

        QString incomingText = QString::fromUtf8(datagram).trimmed();

        QStringList sentences = incomingText.split("\r\n", Qt::SkipEmptyParts);

        for(const QString &sentence : std::as_const(sentences)){
            qDebug() << "UDP Received" << sentence;
            emit dataReceived(sentence);
        }
    }
}
