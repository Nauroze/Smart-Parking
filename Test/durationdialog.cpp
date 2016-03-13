#include "durationdialog.h"
#include "ui_durationdialog.h"
#include <QString>

DurationDialog::DurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DurationDialog)
{
    ui->setupUi(this);
}

DurationDialog::~DurationDialog()
{
    delete ui;
}

void DurationDialog::setLabel(int x, double y)

{

    ui->costLabel->setText("Stay Duration: "+ QString::number(x) + "seconds. Total Cost: $" + QString::number(y));
}

void DurationDialog::on_pushButton_clicked()
{
    emit goHomeSignal();
}
