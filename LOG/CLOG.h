#ifndef CLOG_H
#define CLOG_H
#include <QTimer>
#include <QFrame>
#include "mainwindow.h"

namespace Ui {
class CLOG;
}

class CLOG : public QFrame
{
    Q_OBJECT

public:
    explicit CLOG(QWidget *parent = nullptr);
    ~CLOG();

private slots:
    void on_LOG_cancel_clicked();
    void on_LOG_confirmn_clicked();
    void sendNMEA();

signals:
    void nmeaSentenceReady(const QString &sentence);

private:
    Ui::CLOG *ui;
    QTimer *timer;
    QString calculateChecksum(QString answer);
};

#endif // CLOG_H
