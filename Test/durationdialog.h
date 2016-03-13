#ifndef DURATIONDIALOG_H
#define DURATIONDIALOG_H

#include <QDialog>

namespace Ui {
class DurationDialog;
}

class DurationDialog : public QDialog
{
    Q_OBJECT

public:
    void setLabel(int x, double y);
    explicit DurationDialog(QWidget *parent = 0);
    ~DurationDialog();
signals:
    void goHomeSignal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DurationDialog *ui;
};

#endif // DURATIONDIALOG_H
