#ifndef ZDA_H
#define ZDA_H

#include <QFrame>

namespace Ui {
class ZDA;
}

class ZDA : public QFrame
{
    Q_OBJECT

public:
    explicit ZDA(QWidget *parent = nullptr);
    ~ZDA();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ZDA *ui;
};

#endif // ZDA_H
