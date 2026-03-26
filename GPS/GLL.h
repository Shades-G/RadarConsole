#ifndef GLL_H
#define GLL_H

#include <QFrame>

namespace Ui {
class GLL;
}

class GLL : public QFrame
{
    Q_OBJECT

public:
    explicit GLL(QWidget *parent = nullptr);
    ~GLL();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::GLL *ui;

    void init();
    void load();
};

#endif // GLL_H
