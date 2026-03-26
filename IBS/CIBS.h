#ifndef CIBS_H
#define CIBS_H

#include <QFrame>
#include <QTimer>
#include "SimulatedTarget/SimulatedTarget.h"

namespace Ui {
class CIBS;
}

class CIBS : public QFrame
{
    Q_OBJECT
signals:
    void nmeaSentenceReady(const QString &sentence);

public:
    explicit CIBS(QWidget *parent = nullptr);
    ~CIBS();
    void updateUIFromNetwork(const QStringList &parts);

private slots:
    void on_TTM_confirm_clicked();


    void on_TTM_cancel_clicked();

    void sendTTM();

private:
    Ui::CIBS *ui;
    QTimer *timer;

};

#endif // CIBS_H
