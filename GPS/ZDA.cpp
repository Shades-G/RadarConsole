#include "ZDA.h"
#include "ui_ZDA.h"
#include <QMessageBox>

ZDA::ZDA(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ZDA)
{
    ui->setupUi(this);
}

ZDA::~ZDA()
{
    delete ui;
}

void ZDA::on_pushButton_clicked()
{
 QMessageBox::information(this,"Confirmed","",QMessageBox::Yes|QMessageBox::No);
}

void ZDA::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Canceled","",QMessageBox::Yes|QMessageBox::No);
}
