#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UDPSetting.h"
#include "TCPSetting.h"
#include <QPointer>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include "SimulatedTarget/SimulatedTarget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QList>
#include <QLineEdit>
#include <QDialog>
#include <QLabel>
#include <QSet>
#include <QVBoxLayout>
#include <QMap>
#include <QTimer>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMap>
#include <QDateTime>

struct ShipTelemetry {
    QString lat = "---";
    QString lon = "---";
    QString sog = "---";
    QString cog = "---";
    QString depth = "---";
    QString windSpeed = "---";
    QString windDir = "---";
    QString waterSpeed = "---";
    QString trueWind = "---";
    QString relWind = "---";
    QString airTemp = "---"; // Pre-loaded placeholder for demo
    QString pressure = "---";
    QString humidity = "---";
    QString oceanCurrentDir = "---";
    QString oceanCurrentSpeed = "---";
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QString calculateChecksum(QString answer);

protected:
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void onMasterClock();

    void onSweeperTimer();

    void redrawAllTgt();

    void runProximitySweep();

    void on_scale_selector_cb_currentTextChanged(const QString &arg1);

    void processIncomingAIS(const QString &sentence);

    void processIncomingTTM(QString nmeaString);

    void processIncomingNMEA(const QString &sentence);
    
    void handleGPSClick();
    void handleLOGClick();
    void handleECHOClick();
    void handleAWOSClick();
    void handleWINDClick();
    void updateTelemetryDisplay();
    void on_COMMS_clicked();
    void on_TCP_config_clicked();
    void on_UDP_config_clicked();

    void on_AWOS_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *radarScene;
    void setupRadarDisplay();
    QTimer *masterClock;
    QList<SimulatedTarget*> activeFleet;
    QMap<SimulatedTarget*, QGraphicsEllipseItem*> radarBlips;
    double radarRangeNM;

    QTimer *sweepTimer;
    QGraphicsLineItem *sweeper;
    double currentAngle;
    QGraphicsEllipseItem *dangerCircle;

    QString aisToBinary(const QString &answer);
    int binaryToSignInt(const QString &binaryStr);
    long binaryToLong(const QString &binaryStr);

    QTimer *alarmTimer;
    bool isBlinkVisible;
    double dangerZoneNM;
    QDialog *alertBox;
    QLabel *alertBoxLabel;
    QSet<SimulatedTarget*> alertedShips;

    UDPSetting *udpWindow;
    TCPSetting *tcpWindow;
    QLineEdit *cursorBearing_le;
    QLineEdit *cursorRange_le;
    ShipTelemetry currentTelemetry;
    
    QFrame *telemetryFrame;
    QLabel *telemetryLabel;
    QString currentActiveModule;

    QMap<QString, qint64> targetLastSeen;
    QGraphicsTextItem* targetDataBox = nullptr;
    SimulatedTarget* selectedShip = nullptr;
};

#endif // MAINWINDOW_H
