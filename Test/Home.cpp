#include "Home.h"
#include "ui_Home.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QPalette>
#include <QString>



Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    ui->label->setMinimumSize(200,300);


    ui->listWidget->addItem("- Parking is now Open!");
    ui->listWidget->addItem("- Parking is running 24/7!");
    ui->listWidget->addItem("- Parking is now Open!");
    ui->listWidget->addItem("- Parking is running 24/7!");
    ui->listWidget->addItem("- Parking is now Open!");
    ui->listWidget->addItem("- Parking is running 24/7!");


    //Set up Camera
    camera= new QCamera(this);
    ui->viewfinder->setAspectRatioMode(Qt::IgnoreAspectRatio);
    camera->setViewfinder(ui->viewfinder);

    imageCapture= new QCameraImageCapture(camera);
    captureWorker.DoSetup(imageCapture);
    captureWorker.moveToThread(&cThread);
    connect(&cThread, SIGNAL(started()), &captureWorker, SLOT(DoWork()));
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(onImageCaptured(int,QImage)));




    //Pick Button
    ui->pickButton->setStyleSheet("QPushButton{"
                                     "color: white;"
                                     "border-radius: 6px;"
                                     "border-image: url(:/bt_off.png);"
                                     "}"
                                 "QPushButton:pressed {"
                                     "border: 1px solid #333333;"
                                     "border-radius: 6px;"
                                     "border-image: url(:/bt_on.png);"
                                 "}");


     ui->pickButton->setMaximumSize(300,40);
     ui->pickButton->setMinimumSize(0,0);
     ui->pickButton->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);

     //Checkout Button
     ui->checkoutButton->setStyleSheet("QPushButton{"
                                      "color: white;"
                                      "border-radius: 6px;"
                                      "border-image: url(:/bt_off.png);"
                                      "}"
                                  "QPushButton:pressed {"
                                      "border: 1px solid #333333;"
                                      "border-radius: 6px;"
                                      "border-image: url(:/bt_on.png);"
                                  "}");

      ui->checkoutButton->setMaximumSize(300,40);
      ui->checkoutButton->setMinimumSize(0,0);
      ui->checkoutButton->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);


      //Autoselect Button
      ui->autoselectButton->setStyleSheet("QPushButton{"
                                       "color: white;"
                                       "border-radius: 6px;"
                                       "border-image: url(:/bt_off.png);"
                                       "}"
                                   "QPushButton:pressed {"
                                       "border: 1px solid #333333;"
                                       "border-radius: 6px;"
                                       "border-image: url(:/bt_on.png);"
                                   "}");

       ui->autoselectButton->setMaximumSize(300,40);
       ui->autoselectButton->setMinimumSize(0,0);
       ui->autoselectButton->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);


       //Reserved Button
       ui->reservedButton->setStyleSheet("QPushButton{"
                                        "color: white;"
                                        "border-radius: 6px;"
                                        "border-image: url(:/bt_off.png);"
                                        "}"
                                    "QPushButton:pressed {"
                                        "border: 1px solid #333333;"
                                        "border-radius: 6px;"
                                        "border-image: url(:/bt_on.png);"
                                    "}");

        ui->reservedButton->setMaximumSize(300,40);
        ui->reservedButton->setMinimumSize(0,0);
        ui->reservedButton->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);



}

Home::~Home()
{
    delete ui;
}


void Home::on_pickButton_clicked()
{

    emit sendSignal();

}

void Home::on_reservedButton_clicked()
{
    emit sendSignal2();
}



void Home::on_checkoutButton_clicked()
{
    emit sendSignal3();
}

void Home::on_autoselectButton_clicked()
{
    emit autoSignal();
}

void Home::cameraStart()
{

    camera->start();



}

void Home::threadStart()
{
    cThread.start();


    cThread.setPriority(QThread::HighPriority);
}

void Home::threadClose()
{
    cThread.quit();

}


void Home::onImageCaptured(int id, const QImage &preview)
{

   tempID= (decoder.decodeImage(preview)).toInt();

   if(tempID>0)
   {
       emit decodedID(tempID);
   }
   imageCapture->cancelCapture();
   tempID=0;

}
