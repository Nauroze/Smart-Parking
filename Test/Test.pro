#-------------------------------------------------
#
# Project created by QtCreator 2014-12-29T14:50:17
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test


TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    Home.cpp \
    Lot.cpp \
    scanDialog.cpp \
    ParkingSpace.cpp \
    durationdialog.cpp \
    slotinfo.cpp \
    myworker.cpp \
    BlackADC.cpp \
    GPIOVal.cpp \
    BlackCore.cpp \
    BlackGPIO.cpp \
    occupiedDialog.cpp \
    checkoutdialog.cpp \
    authorizedform.cpp \
    capturethread.cpp \
    server.cpp




HEADERS  += \
    mainwindow.h \
    Home.h \
    Lot.h \
    scanDialog.h \
    ParkingSpace.h \
    durationdialog.h \
    slotinfo.h \
    myworker.h \
    GPIOVal.h \
    BlackADC.h \
    BlackCore.h \
    BlackLib.h \
    BlackDef.h \
    BlackErr.h \
    BlackGPIO.h \
    occupiedDialog.h \
    checkoutdialog.h \
    authorizedform.h \
    capturethread.h \
    server.h




FORMS    += \
    mainwindow.ui \
    Home.ui \
    Lot.ui \
    scanDialog.ui \
    durationdialog.ui \
    slotinfo.ui \
    occupiedDialog.ui \
    checkoutdialog.ui \
    authorizedform.ui \
    server.ui

RESOURCES += \
    TestResource.qrc

OTHER_FILES += \
    ../Downloads/ParkBird.png \
    ParkBird.png \
    parking.gif \
    LotLayout.png \
    QR-SanValentinAR.png \
    Red.png \
    green.png




include(C:\Users\-naze\Documents\QTProjects\Test\QZXing_sourceV2.3\QZXing.pri)
