#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QObject>
#include <QTime>
#include <QCameraImageCapture>
#include <QThread>
#include <QCoreApplication>
#include <QEventLoop>

class captureThread : public QObject
{
    Q_OBJECT
public:
    explicit captureThread(QObject *parent = 0);
    void DoSetup(QCameraImageCapture *tempCapture);
    QCameraImageCapture* myCapture;
    void delay();

signals:

public slots:

    void DoWork();

};

#endif // CAPTURETHREAD_H
