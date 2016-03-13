#ifndef SLOTINFO_H
#define SLOTINFO_H

#include <QDialog>

namespace Ui {
class slotInfo;
}

class slotInfo : public QDialog
{
    Q_OBJECT
    
public:
    explicit slotInfo(QWidget *parent = 0);
    void setLabel(int i);
    ~slotInfo();
signals:
    void goHomeSignal();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::slotInfo *ui;
};

#endif // SLOTINFO_H
