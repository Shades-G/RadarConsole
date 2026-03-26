#ifndef CECHO_H
#define CECHO_H
#include <QTimer>
#include <QFrame>
#include "mainwindow.h"

namespace Ui {
class CECHO;
}

class CECHO : public QFrame
{
    Q_OBJECT

public:
    explicit CECHO(QWidget *parent = nullptr);
    ~CECHO();

private slots:
    void on_LOG_confirmn_clicked();

    void on_LOG_cancel_clicked();

    void sendLOG();

signals:
    void nmeaSentenceReady(const QString &sentence);

private:
    Ui::CECHO *ui;
    QTimer *timer;

};

#endif // CECHO_H
