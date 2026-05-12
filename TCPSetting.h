#ifndef TCPSETTING_H
#define TCPSETTING_H

#include <QFrame>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class TCPSetting;
}

class TCPSetting : public QFrame
{
    Q_OBJECT

public:
    explicit TCPSetting(QWidget *parent = nullptr);
    ~TCPSetting();

public slots:
    void sendData(const QString &nmeaSentence);

private slots:
    void on_TCP_start_clicked();
    void on_TCP_stop_clicked();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

    // NEW: We need a slot to answer the door when the Transmitter knocks
    void onNewConnection();

private:
    Ui::TCPSetting *ui;

    // NEW: Add the Server object
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

signals:
    void dataReceived(const QString &sentence);
};

#endif // TCPSETTING_H
