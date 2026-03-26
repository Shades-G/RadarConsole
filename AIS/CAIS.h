#ifndef CAIS_H
#define CAIS_H

#include <QFrame>
#include <QTimer>
#include <QString>
#include "SimulatedTarget/SimulatedTarget.h"

namespace Ui {
class CAIS;
}

class CAIS : public QFrame
{
    Q_OBJECT

public:
    void updateUIFromNetwork(long mmsi, double lat, double lon , double speed);
    void generateFromLiveTarget(SimulatedTarget *ship);
    explicit CAIS(QWidget *parent = nullptr);
    ~CAIS();

signals:
    void nmeaSentenceReady(const QString &sentence);

private slots:
    //void on_AIS_customContextMenuRequested(const QPoint &pos);

    void on_Cancel_AIS_clicked();

    void on_Confirm_AIS_clicked();

    void sendAIS();

private:
    Ui::CAIS *ui;
    QTimer *timer;
};

#endif // CAIS_H
