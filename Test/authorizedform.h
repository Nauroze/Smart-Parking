#ifndef AUTHORIZEDFORM_H
#define AUTHORIZEDFORM_H

#include <QWidget>
#include <QString>

namespace Ui {
class AuthorizedForm;
}

class AuthorizedForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit AuthorizedForm(QWidget *parent = 0);
    void addErrorMessage(QString error);
    void removeErrorMessage();

    ~AuthorizedForm();
    
private:
    Ui::AuthorizedForm *ui;
};

#endif // AUTHORIZEDFORM_H
