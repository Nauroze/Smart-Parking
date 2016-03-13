#ifndef QRWIDGET_HPP
#define QRWIDGET_HPP

#include <QWidget>

class QRWidget : public QWidget{
    Q_OBJECT
private:
    QString data;
public:
    explicit QRWidget(QWidget *parent = 0);
    void setQRData(QString data);
    void Input (int id);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // QRWIDGET_HPP
