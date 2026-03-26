#include "GLL.h"
#include "ui_GLL.h"
#include <QMessageBox>
#include <QSettings>

GLL::GLL(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GLL)
{
    ui->setupUi(this);

    init();
    load();
}

GLL::~GLL()
{
    delete ui;


}

void GLL::on_pushButton_clicked()
{
  QMessageBox::information(this,"Confirm","");
}

void GLL::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Cleared","");
}

void GLL::on_comboBox_currentIndexChanged(int index)
{
  //ui->lblSelected->setText(QString::number(index) + " = " + ui->comboBox->currentText());
}

void GLL::init()
{
    ui->comboBox->clear();

    for (int i = 0;i < 10;i++) {
     ui->comboBox->addItem("Item number" + QString::number(i));
    }
}

void GLL::load()
{
 QSettings settings;
 QVariant value = settings.value("settings",0);

 bool ok;
 int index = value.toInt(&ok);

 /*{
     QMessageBox::critical(this,"Loading error","Error loading section");
     return;
 }*/

 if(index < ui->comboBox->count())
 {

 }
 else
 {
     ui->comboBox->setCurrentIndex(index);
 }
}
