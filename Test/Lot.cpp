#include "Lot.h"
#include "ui_Lot.h"
#include <QString>
#include <QLabel>



#include <ParkingSpace.h>

Lot::Lot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lot)
{
    ui->setupUi(this);
   // ui->pushButton->setFlat(true);
   // ui->pushButton->setStyleSheet("* { background-color: rgba(0,125,0,0) }");
     //ui->pushButton->setStyleSheet( "background-color: transparent;" );


}

Lot::~Lot()
{
    delete ui;
}

void Lot::updateLabels(ParkingSpace temp[])
{
//Code written in Sysc computer



    ui->lot_1->setStyleSheet(getStyleSheet((temp[0].getStatus())));
    ui->lot_2->setStyleSheet(getStyleSheet((temp[1].getStatus())));
    ui->lot_3->setStyleSheet(getStyleSheet((temp[2].getStatus())));
    ui->lot_4->setStyleSheet(getStyleSheet((temp[3].getStatus())));
    ui->lot_5->setStyleSheet(getStyleSheet((temp[4].getStatus())));
    ui->lot_6->setStyleSheet(getStyleSheet((temp[5].getStatus())));
    ui->lot_7->setStyleSheet(getStyleSheet((temp[6].getStatus())));
    ui->lot_8->setStyleSheet(getStyleSheet((temp[7].getStatus())));
    ui->lot_9->setStyleSheet(getStyleSheet((temp[8].getStatus())));
    ui->lot_10->setStyleSheet(getStyleSheet((temp[9].getStatus())));
    ui->lot_11->setStyleSheet(getStyleSheet((temp[10].getStatus())));
    ui->lot_12->setStyleSheet(getStyleSheet((temp[11].getStatus())));

}



void Lot::on_lot_1_clicked()
{
    emit lotSignal(0);

}

void Lot::on_lot_2_clicked()
{
    emit lotSignal(1);
}

void Lot::on_lot_3_clicked()
{
    emit lotSignal(2);
}

void Lot::on_lot_4_clicked()
{
    emit lotSignal(3);
}


void Lot::on_lot_5_clicked()
{
    emit lotSignal(4);
}


void Lot::on_lot_6_clicked()
{
    emit lotSignal(5);
}


void Lot::on_lot_7_clicked()
{
    emit lotSignal(6);
}


void Lot::on_lot_8_clicked()
{
    emit lotSignal(7);
}

void Lot::on_lot_9_clicked()
{
    emit lotSignal(8);
}

void Lot::on_lot_10_clicked()
{
    emit lotSignal(9);
}

void Lot::on_lot_11_clicked()
{
    emit lotSignal(10);
}

void Lot::on_lot_12_clicked()
{
    emit lotSignal(11);
}

QString Lot::getStyleSheet(char x)
{

    if(x=='E')
    {
        return "border-image: url(:/green.png)";
    }
    if(x=='O')
    {
        return "border-image: url(:/Red.png)";
    }
    if(x=='R')
    {
        return "border-image: url(:/blue.png)";
    }
return "border-image: url(:/warning.png)";
}
