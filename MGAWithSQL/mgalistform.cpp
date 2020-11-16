#include "mgalistform.h"
#include "ui_mgalistform.h"
#include <QDebug>

MGAListForm::MGAListForm(QWidget *parent, EListType eList) :
    QWidget(parent),
    userListFormUi(new Ui::MGAListForm)
{
    userListFormUi->setupUi(this);
    BUTTONS_SETUP
    switch (eList) {
    case eUsersList:
        {USERS_LIST_FORM_SETUP}
        break;
    case eMemberList:
        {MEMBERS_LIST_FORM_SETUP}
        break;
    case eDatabasesList:
        {DATABASES_LIST_FORM_SETUP}
        break;
    default:
        break;
    }
}

QTableWidget *MGAListForm::GetUITable()
{
    return userListFormUi->userListWidget;
}

MGAListForm::~MGAListForm()
{
    delete userListFormUi;
    if(hasAddNewUserForm) delete addNewUser;

}

MGAUser *MGAListForm::GetTheNewUser()
{
    return  addNewUser->GetTheNewUser();
}

void MGAListForm::on_userListWidget_cellPressed(int row, int column)
{
    SelectionIsChanged(row);
}

void MGAListForm::SelectionIsChanged(const int id)
{
    ENABLE_BUTTONS
    nCurrentSelecttonID = id;
}

void MGAListForm::on_editUserButton_clicked()
{

}

void MGAListForm::on_addUserButton_clicked()
{
    try
    {
        if(!hasAddNewUserForm)
        {
           addNewUser = new AddNewObjectForm(this, eUsersList);
           connect(addNewUser, SIGNAL(NewUserIsToBeAdded()),this ,SLOT(NewObjectIsReady()));
           addNewUser->setModal(true);
           addNewUser->exec();
        }

        else
        {
            addNewUser->open();
        }
    }
    catch(int e)
    {
        qDebug()<<e;
    }

    hasAddNewUserForm = true;
}

void MGAListForm::NewObjectIsReady()
{
   //qstr =  addNewUser->GetTheNewUser().GetName();
   emit NewUserIsReady();
}

void MGAListForm::on_searchTextBox_textChanged(const QString &arg1)
{
    for (int i =0; i< userListFormUi->userListWidget->rowCount(); ++i )
    {
        QTableWidgetItem *item = userListFormUi->userListWidget->item(i,0);
        if(!item->text().contains(arg1))
        {
            userListFormUi->userListWidget->hideRow(i);
        }
        else
        {
            userListFormUi->userListWidget->showRow(i);
        }
    }

}
