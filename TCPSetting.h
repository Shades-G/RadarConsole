#ifndef TCPSETTING_H
#define TCPSETTING_H

#include <QFrame>
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

private:
    Ui::TCPSetting *ui;
    QTcpSocket *tcpSocket;

signals:
    void dataReceived(const QString &sentence);
};

#endif // TCPSETTING_H
