#ifndef CXDR_H
#define CXDR_H
#include <QTimer>

#include <QFrame>

namespace Ui {
class CXDR;
}

class CXDR : public QFrame
{
    Q_OBJECT

public:
    explicit CXDR(QWidget *parent = nullptr);
    ~CXDR();

private slots:


    void on_XDR_confirm_clicked();

    void on_XDR_cancel_clicked();

    void on_cb_Unit_currentTextChanged(const QString &selection);

    void sendNMEA();

signals:
    void nmeaSentenceReady(const QString &sentence);

private:
    Ui::CXDR *ui;
    QTimer *timer;
    QString getUnit(QString measureName);
};

#endif // CXDR_H
