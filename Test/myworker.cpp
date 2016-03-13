#include "myworker.h"
#include <QThread>
#include <QtCore>



#include <stdlib.h>


MyWorker::MyWorker(QObject *parent) :
    QObject(parent)
{
}

void MyWorker::DoSetup(ParkingSpace temp[],  Lot *tempLot, int size)
{
    mySize=size;
    myLot=temp;
    myLotlabels = tempLot;

  //  connect(&cThread, SIGNAL(started()), this, SLOT(DoWork()));



}

void MyWorker::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MyWorker::DoWork()
{
    while(true)
    {

   QThread::msleep(4000);


        for (int i=0; i<mySize; i++) {

                if(rand()%100 > 50) {
                  myLot[i].setStatus('O');

                } else if (myLot[i].getStatus()!='R') {
                    myLot[i].setStatus('E');
                }
            }

//            GPIOEXP(30); // MUX1 SENSORS
//            GPIOEXP(31); // MUX1 SENSORS
//            GPIOEXP(48); // MUX1 SENSORS




//                        BlackLib::BlackADC myAdc(BlackLib::AIN0);
//                        int i = 0;
//                                for (int C =0;C<2;C++){
//                                    for (int B=0;B<2; B++){
//                                        for (int A=0; A<2;A++){

//                                                GPIOVal(30,A);
//                                                GPIOVal(31,B);
//                                                GPIOVal(48,C);

//                                                val1 = myAdc.getNumericValue();
//                                                SensorValue[i]=val1;

                                   
//                                                if (i < 9){
//                                                            if (val1 < TreshValue && myLot[i].getStatus()!='R'){


//                                                                myLot[i].setStatus('E');
//                                                            }
//                                                            else if(val1 >= TreshValue ) {

//                                                                myLot[i].setStatus('O');
//                                                            }


//                                                        }
//                                                        i++;

//                                                }
//                                            }
//                                        }
                   //   myLotlabels->updateLabels(myLot); //Updates the labels on the Gui
                    emit workerSaysUpdateLabels();

                     }




}
