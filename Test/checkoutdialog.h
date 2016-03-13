#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class checkoutDialog;
}

class checkoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit checkoutDialog(QWidget *parent = 0);
    int getCheckoutID();
    int ID;
    ~checkoutDialog();

private slots:


    void on_okButton_clicked();

signals:
    void checkoutIDSignal(int x);

private:
    Ui::checkoutDialog *ui;
};

#endif // CHECKOUTDIALOG_H
