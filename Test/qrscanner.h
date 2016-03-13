#ifndef QRSCANNER_H
#define QRSCANNER_H

#include <QObject>
#include <QZXing.h>
#include <QImage>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QTime>
#include <QThread>
#include "capturethread.h"


class QrScanner : public QObject
{
    Q_OBJECT
public:
    explicit QrScanner(QCamera *camera, QObject *parent = 0);
    QZXing decoder;
    QImage image;
    QCamera *myCamera;
    QCameraImageCapture *imageCapture;
    QThread cThread;
    captureThread captureWorker;
    void start();

signals:

public slots:
    void onImageCaptured(int id, const QImage &preview);

};

#endif // QRSCANNER_H
