#ifndef LOT_H
#define LOT_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <ParkingSpace.h>


namespace Ui {
class Lot;
}

class Lot : public QWidget
{
    Q_OBJECT
    
public:
    explicit Lot(QWidget *parent = 0);

    void updateLabels(ParkingSpace temp[]);

    QString getStyleSheet(char x);


   //void setSymbol(QLabel label);

    ~Lot();
signals:
    void lotSignal(int i);


    
private slots:


    void on_lot_1_clicked();

    void on_lot_2_clicked();

    void on_lot_3_clicked();

    void on_lot_4_clicked();

    void on_lot_5_clicked();

    void on_lot_6_clicked();

    void on_lot_7_clicked();

    void on_lot_8_clicked();

    void on_lot_9_clicked();

    void on_lot_10_clicked();

    void on_lot_11_clicked();

    void on_lot_12_clicked();

private:
    Ui::Lot *ui;
    QString str;

};

#endif // LOT_H
