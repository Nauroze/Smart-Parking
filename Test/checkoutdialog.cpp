#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"

checkoutDialog::checkoutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkoutDialog)
{
    ui->setupUi(this);
}

checkoutDialog::~checkoutDialog()
{
    delete ui;
}



int checkoutDialog::getCheckoutID()
{
    if(ID>0)
    {
    return ID;
    }
    return 0;
}

void checkoutDialog::on_okButton_clicked()
{
    if(ui->lineEdit->text()!=NULL) {
        this->ID = ui->lineEdit->text().toInt();
        emit checkoutIDSignal(ID) ;
        ui->lineEdit->clear();
    }else{
        QMessageBox errorSMS;
        errorSMS.setIcon(QMessageBox::Information);
        errorSMS.setText("Sorry, the ID provided is incorrect.\nPlease try again..");
        errorSMS.exec();
    }
}
