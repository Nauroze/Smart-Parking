#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Home.h"
#include "Lot.h"
#include "scanDialog.h"


#include <QStackedWidget>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->hide();
    this->setStyleSheet("MainWindow {border-image: url(:/background-todo.jpg);}""QToolBar {background-color: lightGray}");


 //Starting the camera and scanner
  //  this->homeWidget.cameraStart();
  //  this->homeWidget.threadStart();


//Set up of Parking
    lot.updateLabels(myLot);



//Setting the index limits
    index=0 ;MainWindow::
    maxIndex=3;                              // Update the max index everytime an additional widget is added
    minIndex=0;

//Setting the stacked widgets
    stacked = new QStackedWidget();
    stacked->addWidget(&homeWidget);   //index 0
    stacked->addWidget(&lot);   //index 1
    stacked->addWidget(&authorizedWidget);  //index 2
    stacked->addWidget(&serverDisplay);
    setStackIndex(index);

    this->setCentralWidget(stacked);


//Connecting buttons and widgets
    //Scan dialog
    QObject::connect(&scanMessage, SIGNAL(destroyed()), &homeWidget, SLOT(threadClose()));

    //Home widget = 'wid'
    QObject::connect(&homeWidget, SIGNAL(sendSignal()), this , SLOT(setStackLot())); // Continue here, trying to connect push button to lot
    QObject::connect(&homeWidget,SIGNAL(sendSignal2()), this , SLOT(showScan()));    // On Reserved button press
    QObject::connect(&homeWidget,SIGNAL(sendSignal3()), &checkoutWindow , SLOT(show())); //checkout
    QObject::connect(&homeWidget, SIGNAL(autoSignal()),this, SLOT(autoSelect()));
    QObject::connect(&homeWidget, SIGNAL(decodedID(int)),this, SLOT(onceDecoded(int)));


    //Checkout Dialog Widget
     QObject::connect(&checkoutWindow, SIGNAL(checkoutIDSignal(int)), this , SLOT(checkOut(int)));

    //Lot widget = 'lot'
    QObject::connect(&lot, SIGNAL(lotSignal(int)), this , SLOT(CheckDecider(int)));

    //Display message after autoselect
    QObject::connect(&displayMessage, SIGNAL(goHomeSignal()), this , SLOT(setStackHome()));

    //Duration exit
    QObject::connect(&duration, SIGNAL(goHomeSignal()), this , SLOT(setStackHome()));


// Setting up the thread for changing lots

    worker.DoSetup(myLot,&lot,12);
    worker.moveToThread(&cThread);
    connect(&cThread, SIGNAL(started()), &worker, SLOT(DoWork()));
    cThread.start();
    QObject::connect(&worker, SIGNAL(workerSaysUpdateLabels()), this , SLOT(windowUpdateLabels()));


// Setting reservation message font size


    font.setPixelSize(15);
    reservationMessage.setFont(font);

}

//Deconstructor
MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_actionForward_triggered()
{   index++;

    if(index>maxIndex)//   stacked->setCurrentIndex(index);
    {
        index=maxIndex;
    }

    setStackIndex(index);
}

void MainWindow::on_actionBack_triggered()
{   index--;

    if(index<minIndex)
    {
        index=minIndex;
    }

    setStackIndex(index);
}


void MainWindow::setStackIndex(int x)  // Sets the index of stackedwidgets
{
    stacked->setCurrentIndex(x);
}



void MainWindow::setStackLot()
{

    lot.updateLabels(myLot);
    setStackIndex(1) ; //When called goes to parking layout widget

}



void MainWindow::setStackHome()
{


    setStackIndex(0) ; //When called goes to home widget

}

void MainWindow::showScan()
{
    scanMessage.show();

}

//Frank's Part

void MainWindow::CheckDecider(int x)
{
    if(myLot[x].getStatus()=='O'||myLot[x].getStatus()=='R')
        {
            occupiedMessage.setIcon(QMessageBox::Information);
            occupiedMessage.setText("The parking spot is already taken! Please select another location.");
            occupiedMessage.exec();
            lot.updateLabels(myLot);
        }
    else if (myLot[x].getStatus()=='E')
    {
        checkIn(x);
    }
}

void MainWindow::checkIn(int x)
{

    if(myLot[x].getStatus()=='O')
    {
        occupiedMessage.setText("The parking spot is already taken! Please select another location.");
        occupiedMessage.exec();
        lot.updateLabels(myLot);
    }
    else {
    myLot[x].setStatus('R');
    myLot[x].setTime_in();
    myLot[x].setResId();
    lot.updateLabels(myLot);


    reservationMessage.setText( "You have selected slot number " + QString::number(x+1) + "\n" + "Your CheckIn ID is : " + QString::number(myLot[x].getResId())  );
    reservationMessage.exec();
   // qrwidget.setQRData(QString::number(myLot[x].getResId()));


    }
}


void MainWindow::checkOut(int x) // recieves the reservation id, finds the spot, checks them out.

{
//    myLot[x].setStatus('E');
//    myLot[x].setTime_out();
//    lot.updateLabels(myLot);
//    duration.setLabel(myLot[x].getDuration(), myLot[x].getCost());
//    duration.show();

    sizeofLot= sizeof(myLot)/sizeof(myLot[0]);
    int i=0;
    for (; i<sizeofLot ; i++){
        if (myLot[i].getResId()==x)
        {
            myLot[i].setTime_out();
            duration.setLabel(myLot[i].getDuration(), myLot[i].getCost());
            duration.show();
            myLot[i].resetAll();
            break;
        }
    }
    if(i==sizeofLot) {

            checkoutError.setIcon(QMessageBox::Information);
            checkoutError.setText("Sorry, the ID provided is incorrect.\nPlease try again..");
            checkoutError.exec();
        }

}

ParkingSpace* MainWindow::getEmptySpace(ParkingSpace lot[], int size) {
    if(lot==NULL) { return NULL; }
    for (int i=0; i<size;i++) {
        if ('E' == lot[i].getStatus()) {
            return &lot[i];
        }
    }
    return NULL;
}

void MainWindow::autoSelect()
{


        for (int i=0; i<12;i++) {
            if ('E' == myLot[i].getStatus()) {
                checkIn(i);
                break;
            }
        }


}

void MainWindow::updateStatus(int i , char x)
{
    if (myLot[i].getStatus()=='E' && x=='O') {

        //Display Alert Message = Unreserved spot taken.

    }
        myLot[i].setStatus(x);

}

void MainWindow::windowUpdateLabels()
{
    lot.updateLabels(myLot);
}

void MainWindow::onceDecoded(int x)
{
    if(checkoutWindow.isVisible())
    {
    checkoutWindow.close();
    tempMessage.setText("Your Checkout Id is "+ QString::number(x));
    tempMessage.exec();
    this->checkOut(x);
    homeWidget.threadClose();
    }
    else if (scanMessage.isVisible())
    {
        scanMessage.close();
        tempMessage.setText("Your Reservation Id is "+ QString::number(x));
        tempMessage.exec();
        this->checkIn(x);
        homeWidget.threadClose();
    }
    else{
    tempMessage.setText("Your General Id is "+ QString::number(x));
    tempMessage.exec();
    homeWidget.threadClose();
    }


}

void MainWindow::on_actionAuthorized_triggered()
{
    setStackIndex(2);
    index=2;
}

void MainWindow::on_actionServer_triggered()
{
    setStackIndex(3);
    index=3;
}
