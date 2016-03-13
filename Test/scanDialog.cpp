#include "scanDialog.h"
#include "ui_scanDialog.h"

scanDialog::scanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scanDialog)
{
    ui->setupUi(this);
}

scanDialog::~scanDialog()
{
    delete ui;
}
