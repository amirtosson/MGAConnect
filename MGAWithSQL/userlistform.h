#ifndef USERLISTFORM_H
#define USERLISTFORM_H

#include <QWidget>
#include "mgauserlib.h"

namespace Ui {
class UserListForm;
}

class UserListForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserListForm(QWidget *parent = 0,unsigned int usernum = 0);
    ~UserListForm();
    MGAUser *users;

private slots:
    void on_userListWidget_cellPressed(int row, int column);

private:
    Ui::UserListForm *userListFormUi;
    unsigned int nUsers = 0;
};

#endif // USERLISTFORM_H
