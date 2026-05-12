#include "TCPSetting.h"
#include "ui_TCPSetting.h"
#include <QDebug>

TCPSetting::TCPSetting(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TCPSetting)
{
    ui->setupUi(this);

    // 1. Initialize the Server and set socket to null until someone connects
    tcpServer = new QTcpServer(this);
    tcpSocket = nullptr;

    ui->Server_line->setText("127.0.0.1"); // Localhost by default
    ui->Client_line->setText("9999");      // Changed to 9999 to match our tests
    ui->TCP_stop->setEnabled(false);

    // 2. Wire the server to answer the door when a connection arrives
    connect(tcpServer, &QTcpServer::newConnection, this, &TCPSetting::onNewConnection);
}

TCPSetting::~TCPSetting()
{
    delete ui;
}

void TCPSetting::on_TCP_start_clicked()
{
    quint16 listenPort = ui->Client_line->text().toUShort();

    // Tell the Server to open the doors and listen
    if (!tcpServer->listen(QHostAddress::Any, listenPort)) {
        qDebug() << "CRITICAL: TCP Server failed to start! Port" << listenPort << "might be blocked.";
    } else {
        qDebug() << "SUCCESS: Radar TCP Server Listening on port:" << listenPort;

        ui->TCP_start->setEnabled(false);
        ui->TCP_stop->setEnabled(true);
        ui->Server_line->setEnabled(false); // Lock inputs while listening
        ui->Client_line->setEnabled(false);
    }
}

// NEW FUNCTION: This answers the door
void TCPSetting::onNewConnection()
{
    // Accept the incoming connection from the Transmitter and assign it to the socket
    tcpSocket = tcpServer->nextPendingConnection();

    qDebug() << "TCP: Transmitter successfully connected to Radar!";

    // Now wire up the socket to listen for incoming strings and state changes
    connect(tcpSocket, &QTcpSocket::stateChanged, this, &TCPSetting::onSocketStateChanged);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &TCPSetting::onReadyRead);
}

void TCPSetting::on_TCP_stop_clicked()
{
    // Disconnect the client if they are connected
    if (tcpSocket && tcpSocket->isOpen()) {
        tcpSocket->disconnectFromHost();
    }

    // Close the server doors
    tcpServer->close();
    qDebug() << "TCP Server Stopped.";

    ui->TCP_start->setEnabled(true);
    ui->TCP_stop->setEnabled(false);
    ui->Server_line->setEnabled(true);
    ui->Client_line->setEnabled(true);
}

void TCPSetting::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState) {
        qDebug() << "TCP: Transmitter Disconnected.";
        // Note: We don't unlock the UI here because the Server is technically still listening!
    }
}

void TCPSetting::sendData(const QString &nmeaSentence)
{
    // Make sure we have a socket and it's connected before sending
    if (tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState) {
        tcpSocket->write(nmeaSentence.toUtf8());
        tcpSocket->flush();
    }
}

void TCPSetting::onReadyRead()
{
    // Ensure the socket exists
    if (!tcpSocket) return;

    QByteArray rawData = tcpSocket->readAll();
    QString incomingText = QString::fromUtf8(rawData).trimmed();

    QStringList sentences = incomingText.split("\r\n", Qt::SkipEmptyParts);
    for (const QString &sentence : sentences) {
        emit dataReceived(sentence); // Shout it to the Main Window!
    }
}
