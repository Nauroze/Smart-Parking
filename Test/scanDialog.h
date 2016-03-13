#ifndef SCANDIALOG_H
#define SCANDIALOG_H

#include <QDialog>

namespace Ui {
class scanDialog;
}

class scanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit scanDialog(QWidget *parent = 0);
    ~scanDialog();

private:
    Ui::scanDialog *ui;
};

#endif // SCANDIALOG_H
