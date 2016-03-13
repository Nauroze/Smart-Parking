#include "occupiedDialog.h"
#include "ui_occupiedDialog.h"

occupiedDialog::occupiedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::occupiedDialog)
{
    ui->setupUi(this);
}

occupiedDialog::~occupiedDialog()
{
    delete ui;
}
