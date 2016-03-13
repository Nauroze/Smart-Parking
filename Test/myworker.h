#ifndef MYWORKER_H
#define MYWORKER_H
#define Spots 8
#define TreshValue 18

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QString>
#include "ParkingSpace.h"
#include "Lot.h"

/*  //Mahmoud's Variables unused
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> */

    //Mahmoud's Variables used
#include <BlackADC.h>
#include <BlackGPIO.h>
#include "GPIOEXP.h"
#include "GPIOVal.h"

class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(QObject *parent = 0);
    void DoSetup(ParkingSpace temp[], Lot *tempLot, int size);
    int  mySize;
    ParkingSpace *myLot;
    Lot *myLotlabels;
    void delay();

    // Mahmouds stuff
 /*   int* GetArray();
    int LEDStatus(int,int,int,string);
    int ParkingLocation [Spots];
    string ParkingStatus[Spots]; */

    int SensorValue [Spots];
    int val1;




signals:
    void workerSaysUpdateLabels();


public slots:

    void DoWork();

};

#endif // MYWORKER_H
