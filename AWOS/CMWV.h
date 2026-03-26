#ifndef CMWV_H
#define CMWV_H
#include <QTimer>

#include <QFrame>

namespace Ui {
class CMWV;
}

class CMWV : public QFrame
{
    Q_OBJECT

public:
    explicit CMWV(QWidget *parent = nullptr);
    ~CMWV();

private slots:
    void on_MWV_confirm_clicked();

    void on_MWV_cancel_clicked();

    void sendNMEA();

signals:
    void nmeaSentenceReady(const QString &sentence);

private:
    Ui::CMWV *ui;
    QTimer *timer;
    QString conditionStr(double angle, QString ref, double speed, QString unit, QString status);
};

#endif // CMWV_H
