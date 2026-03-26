#ifndef CRMCVIEW_H
#define CRMCVIEW_H
#include <QFrame>

namespace Ui {
class CRMCView;
}

class CRMCView : public QFrame
{
    Q_OBJECT

public:
    explicit CRMCView(QWidget *parent = nullptr);
    ~CRMCView();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CRMCView *ui;
};

#endif // CRMCVIEW_H
