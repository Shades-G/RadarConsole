#include "GGA.h"
#include "ui_GGA.h"
#include <QMessageBox>

GGA::GGA(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GGA)
{
    ui->setupUi(this);
}

GGA::~GGA()
{
    delete ui;
}

void GGA::on_pushButton_clicked()
{
 QMessageBox::information(this,"Confirmed","");
}

void GGA::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Canceled","");
}
