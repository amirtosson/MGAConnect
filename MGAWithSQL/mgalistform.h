#ifndef USERLISTFORM_H
#define USERLISTFORM_H

#include <QWidget>
#include <QTableWidget>

#include "addnewobjectform.h"
#include "mgalistformresources.h"
#include "mgalistformsetups.h"
#include "mgalistformtypesenum.h"

#define MGA_LIST_TYPY eMemberList

namespace Ui {
class MGAListForm;
}

class MGAListForm : public QWidget
{
    Q_OBJECT

public:
    explicit MGAListForm(QWidget *parent = 0, EListType eList = eMemberList);
    QTableWidget *GetUITable();
    ~MGAListForm();
    MGAUser *GetTheNewUser();

private slots:
    void on_userListWidget_cellPressed(int row, int column);

    void on_editUserButton_clicked();

    void on_addUserButton_clicked();

    void NewObjectIsReady();

    void on_searchTextBox_textChanged(const QString &arg1);

signals:
    void NewUserIsReady();

private:
    void SelectionIsChanged(const int id);

private:
    Ui::MGAListForm *userListFormUi;
    QIcon btnIcon;
    unsigned int nCurrentSelecttonID = -1;
    AddNewObjectForm *addNewUser;

    bool hasAddNewUserForm = false;
};

#endif // USERLISTFORM_H
