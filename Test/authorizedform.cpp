#include "authorizedform.h"
#include "ui_authorizedform.h"

AuthorizedForm::AuthorizedForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorizedForm)
{
    ui->setupUi(this);

}

AuthorizedForm::~AuthorizedForm()
{
    delete ui;
}

void AuthorizedForm::addErrorMessage(QString error) {
    ui->listWidget->addItem(error);
}
