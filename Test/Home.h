#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QCamera>
#include <QCameraViewfinder>

#include <QZXing.h>
#include <QImage>
#include <QCameraImageCapture>
#include <QTime>
#include <QThread>
#include "capturethread.h"


namespace Ui {
class Home;
}

class Home :public QWidget
{
    Q_OBJECT
    
public:
    explicit Home(QWidget *parent = 0);
    QLabel timeLabel;
    QCamera* camera;

    QZXing decoder;
    QImage image;
    QCameraImageCapture *imageCapture;
    QThread cThread;
    captureThread captureWorker;
    void imageCaptured(QImage image);

    ~Home();

signals:
    void sendSignal(); //For Pick Button
    void sendSignal2(); //For Reserved Button
    void sendSignal3(); //For Checkout
    void autoSignal();
    

private slots:
    void on_pickButton_clicked();
    void on_reservedButton_clicked();
    void on_checkoutButton_clicked();
    void on_autoselectButton_clicked();

public slots:
    void cameraStart();
    void threadStart();
    void threadClose();
    void onImageCaptured(int id, const QImage &preview);


signals:
    void decodedID(int x);


private:
    Ui::Home *ui;
    int tempID;

};

#endif // HOME_H
