#include "CRMCView.h"
#include "ui_CRMCView.h"
#include <QMessageBox>
#include <qradiobutton.h>

CRMCView::CRMCView(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CRMCView)
{
    ui->setupUi(this);
}

CRMCView::~CRMCView()
{
    delete ui;
}

void CRMCView::on_radioButton_clicked()
{
    {
        if(ui->radioButton->isChecked()){
            QMessageBox::information(this,"Position Valid",ui->radioButton->text());
        }
    }
}

void CRMCView::on_radioButton_2_clicked()
{
    if(ui->radioButton_2->isChecked()){
        QMessageBox::information(this,"Position Valid",ui->radioButton_2->text());
    }
}

void CRMCView::on_radioButton_3_clicked()
{
    if(ui->radioButton_3->isChecked()){
        QMessageBox::information(this,"Magnetic Variation Direction",ui->radioButton_3->text());
    }
}



void CRMCView::on_radioButton_4_clicked()
{
    if(ui->radioButton_4->isChecked()){
        QMessageBox::information(this,"Magnetic Variation Direction",ui->radioButton_4->text());
    }
}

void CRMCView::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Confirmed","",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
        QMessageBox::information(this,"This is Confirmed","");
}

void CRMCView::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Canceled","",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
        QMessageBox::information(this,"This is Canceled","");
}
