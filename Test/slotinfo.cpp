#include "slotinfo.h"
#include "ui_slotinfo.h"
#include "mainwindow.h"
#include <QString>

slotInfo::slotInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::slotInfo)
{
    ui->setupUi(this);
}

slotInfo::~slotInfo()
{
    delete ui;
}

void slotInfo::on_pushButton_clicked()
{
    emit goHomeSignal();
    this->close();


}

void slotInfo::setLabel(int i)
{
    ui->displayLabel->setText("You have selected Slot number " + QString::number(i));

}
