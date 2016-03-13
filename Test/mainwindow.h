#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QThread>
#include "Home.h"
#include "Lot.h"
#include "scanDialog.h"
#include "durationdialog.h"
#include "slotinfo.h"
#include <QStackedWidget>
#include <QMessageBox>
#include "checkoutdialog.h"
#include "authorizedform.h"
#include "ParkingSpace.h"
#include "myworker.h"
#include "server.h"


#include <QZXing.h>
#include <QImage>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "capturethread.h"
//#include "qrwidget.hpp"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    Home homeWidget;

    Lot lot;

    scanDialog scanMessage;

    DurationDialog duration;

    ParkingSpace myLot[12];

    QStackedWidget *stacked;

    slotInfo displayMessage;

    QThread cThread;

    MyWorker worker;

    QMessageBox occupiedMessage;

    QMessageBox reservationMessage;

    QMessageBox checkoutError;

    QMessageBox tempMessage;

    QFont font;

    AuthorizedForm authorizedWidget;

    Server serverDisplay;

    checkoutDialog checkoutWindow;

  //  QRWidget qrwidget;

    void updateStatus(int i , char x);

    void setStackIndex(int x);





    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionForward_triggered();

    void on_actionBack_triggered();

    void setStackLot();
    void setStackHome();


    void showScan();
    void checkOut(int x);
    void checkIn(int x);
    void CheckDecider(int x); // Decides if it's a check in or check out
    ParkingSpace* getEmptySpace(ParkingSpace lot[], int size);

    void autoSelect();
    void windowUpdateLabels();
    void onceDecoded(int x);

    void on_actionAuthorized_triggered();

    void on_actionServer_triggered();

private:
    Ui::MainWindow *ui;
    int index;
    int maxIndex;
    int minIndex;
    int sizeofLot;



    //Parking variables
    int count;


};

#endif // MAINWINDOW_H
