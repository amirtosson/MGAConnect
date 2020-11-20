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

    template<typename T> T GetTheNewObject()
    {
        switch (eCurrentListType) {
        case eUsersList:
            return addNewObject->GetTheNewUser();
            break;
        case eMemberList:
            return addNewObject->GetTheNewMember();
            break;
        case eDatabasesList:

            break;
        case eExperimentist:
            return addNewObject->GetTheNewExp();
            break;
        default:
            break;
        }
    }

private slots:
    void on_userListWidget_cellPressed(int row, int column);

    void on_editUserButton_clicked();

    void on_addUserButton_clicked();

    void NewObjectIsReady();

    void on_searchTextBox_textChanged(const QString &arg1);

signals:
    void NewUserIsReady();
    void NewMemberIsReady();
    void NewExpIsReady();


private:
    void SelectionIsChanged(const int id);

private:
    Ui::MGAListForm *userListFormUi;
    QIcon btnIcon;
    unsigned int nCurrentSelecttonID = -1;
    EListType eCurrentListType = eUNKOWN;
    AddNewObjectForm *addNewObject;
    bool hasAddNewObjectForm = false;
};

#endif // USERLISTFORM_H
