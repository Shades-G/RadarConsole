#ifndef UDPSETTING_H
#define UDPSETTING_H

#include <QFrame>
#include <QDialog>
#include <QUdpSocket>


namespace Ui {
class UDPSetting;
}

class UDPSetting : public QFrame
{
    Q_OBJECT

public:
    explicit UDPSetting(QWidget *parent = nullptr);
    ~UDPSetting();
public slots:
    void sendData(const QString &nmeaSentence);
signals:
    void dataReceived(const QString &sentence);
private slots:
    void on_UDP_start_clicked();

    void on_UDP_stop_clicked();

    void on_broadcast_toggled(bool checked);

    void onReadyRead();

private:
    Ui::UDPSetting *ui;
    QUdpSocket *udpSocket;
    bool isTransmitting;// a flag
};

#endif // UDPSETTING_H
