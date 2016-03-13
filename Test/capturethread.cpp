#include "capturethread.h"

captureThread::captureThread(QObject *parent) :
    QObject(parent)
{
}

void captureThread::DoSetup(QCameraImageCapture *tempCapture)
{

    myCapture= tempCapture;


}
void captureThread::DoWork()
{
    while(true)
    {
        myCapture->capture();
        delay();

    }
}

void captureThread::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(2500);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
