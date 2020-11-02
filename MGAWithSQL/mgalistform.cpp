#include "mgalistform.h"
#include "ui_mgalistform.h"
#include <QDebug>

MGAListForm::MGAListForm(QWidget *parent, EListType eList) :
    QWidget(parent),
    userListFormUi(new Ui::MGAListForm)
{
    userListFormUi->setupUi(this);
    switch (eList) {
    case eUsersList:
        {USER_LIST_FORM_SETUP}
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

}


void MGAListForm::on_userListWidget_cellPressed(int row, int column)
{

}
