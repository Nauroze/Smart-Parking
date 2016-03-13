ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>

namespace Ui {
class customButton;
}

class customButton : public QWidget
{
    Q_OBJECT
    
public:
    explicit customButton(QWidget *parent = 0);
    ~customButton();
    
private:
    Ui::customButton *ui;
};

#endif // CUSTOMBUTTON_H
