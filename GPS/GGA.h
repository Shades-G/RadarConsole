#ifndef GGA_H
#define GGA_H

#include <QFrame>

namespace Ui {
class GGA;
}

class GGA : public QFrame
{
    Q_OBJECT

public:
    explicit GGA(QWidget *parent = nullptr);
    ~GGA();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GGA *ui;
};

#endif // GGA_H
