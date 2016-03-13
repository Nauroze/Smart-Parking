#ifndef OCCUPIEDDIALOG_H
#define OCCUPIEDDIALOG_H

#include <QDialog>

namespace Ui {
class occupiedDialog;
}

class occupiedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit occupiedDialog(QWidget *parent = 0);
    ~occupiedDialog();

private:
    Ui::occupiedDialog *ui;
};

#endif // OCCUPIEDDIALOG_H
