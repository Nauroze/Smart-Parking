#include "qrscanner.h"

QrScanner::QrScanner(QCamera *camera, QObject *parent) :
    QObject(parent)
{
    myCamera=camera;
    imageCapture= new QCameraImageCapture(myCamera);
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(onImageCaptured(int,QImage)));
    captureWorker.DoSetup(cThread, imageCapture);
    captureWorker.moveToThread(&cThread);
}

void QrScanner::start()
{

    cThread.start();

}

void QrScanner::onImageCaptured(int id, const QImage &preview)
{

   decoder.decodeImage(preview);

   imageCapture->cancelCapture();

}

