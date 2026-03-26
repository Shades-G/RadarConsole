#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UDPSetting.h"
#include "TCPSetting.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include "GPS/CRMCView.h"
#include "GPS/GLL.h"
#include "GPS/GGA.h"
#include "GPS/ZDA.h"
#include "SimulatedTarget/SimulatedTarget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QList>
#include <QMap>
#include <QTimer>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class CLOG;
class CECHO;
class CXDR;
class CMWV;
class CIBS;
class CAIS;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void m_MemoryCreation();

    static QString calculateChecksum(QString answer);

public slots:

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_GPS_PB_clicked();

    void on_LOG_PB_clicked();

    void on_AWOS_PB_clicked();

    void on_ECHO_PB_clicked();

    void on_RMC_PB_clicked();

    void on_GLL_PB_clicked();

    void on_GGA_PB_clicked();

    void on_ZDA_PB_clicked();

    void on_MWV_PB_clicked();

    void on_XDR_PB_clicked();

    void on_COMMS_PB_clicked();

    void on_UDP_PB_clicked();

    void on_TCP_PB_clicked();

    void on_IBS_PB_clicked();

    void on_AIS_PB_clicked();

    void onMasterClock();

    void onSweeperTimer();

    void redrawAllTgt();

    void runProximitySweep();

    void on_scale_selector_currentTextChanged(const QString &arg1);

    void processIncomingAIS(const QString &sentence);

    void processIncomingTTM(QString nmeaString);

    void processIncomingNMEA(const QString &sentence);

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

    QString aisToBinary(const QString &answer);
    int binaryToSignInt(const QString &binaryStr);
    long binaryToLong(const QString &binaryStr);

    QTimer *alarmTimer;
    bool isBlinkVisible;
    double dangerZoneNM;

    QSqlDatabase vdrDatabase;
    void setupDatabase();
    void logTargetToDB(const QString& tgt_id, double lat , double lon , double speed, const QString& sourceType);

    CIBS *objIBS;
    CAIS *objAIS;
    CLOG *objLOG;
    CECHO *objECHO;
    GLL *objGLL;
    GGA *objGGA;
    ZDA *objZDA;
    CXDR *objXDR;
    CMWV *objMWV;
    CRMCView *objCRMCView;

    UDPSetting *udpWindow;
    TCPSetting *tcpWindow;
};

#endif // MAINWINDOW_H
