#include "TCPSetting.h"
#include "ui_TCPSetting.h"

TCPSetting::TCPSetting(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TCPSetting)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    ui->Server_line->setText("127.0.0.1"); // Localhost by default
    ui->Client_line->setText("20001");
    ui->TCP_stop->setEnabled(false);

    connect(tcpSocket,&QTcpSocket::stateChanged , this , &TCPSetting::onSocketStateChanged);
    connect(tcpSocket,&QTcpSocket::readyRead , this , &TCPSetting::onReadyRead);

}

TCPSetting::~TCPSetting()
{
    delete ui;
}

void TCPSetting::on_TCP_start_clicked()
{
    QString serverIP = ui->Server_line->text();
    quint16 clientPort = ui->Client_line->text().toUShort();

    qDebug()<< "TCP port :" << serverIP;

    tcpSocket->connectToHost(serverIP,clientPort);
}


void TCPSetting::on_TCP_stop_clicked()
{
    tcpSocket->disconnectFromHost();
}

void TCPSetting::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::ConnectedState){
        qDebug()<< "TCP Connected";
        ui->TCP_start->setEnabled(false);
        ui->TCP_stop->setEnabled(true);
        ui->Server_line->setEnabled(false); // Lock inputs while connected
        ui->Client_line->setEnabled(false);
    }
    else if(socketState == QAbstractSocket::UnconnectedState){
        qDebug() << "TCP: Disconnected.";
        ui->TCP_start->setEnabled(true);
        ui->TCP_stop->setEnabled(false);
        ui->Server_line->setEnabled(true);
        ui->Client_line->setEnabled(true);
    }
}

void TCPSetting::sendData(const QString &nmeaSentence)
{
    //to make sure we write on a open/connected socket
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(nmeaSentence.toUtf8());
        tcpSocket->flush(); //push data
    }
}

void TCPSetting::onReadyRead()
{
    //read all
    QByteArray rawData =  tcpSocket->readAll();
    QString incomingText = QString::fromUtf8(rawData).trimmed();

    QStringList sentences = incomingText.split("\r\n", Qt::SkipEmptyParts);
    for(const QString &sentence : sentences) {
        emit dataReceived(sentence); // Shout it to the Main Window!
    }
}
