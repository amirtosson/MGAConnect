#include "userlistform.h"
#include "ui_userlistform.h"
#include <QDebug>

UserListForm::UserListForm(QWidget *parent, unsigned int usernum) :
    QWidget(parent),
    userListFormUi(new Ui::UserListForm)
{
    userListFormUi->setupUi(this);
    nUsers = usernum;
    users = new MGAUser[nUsers];
    userListFormUi->userListWidget->insertColumn(0);
    userListFormUi->userListWidget->insertColumn(1);
    userListFormUi->userListWidget->insertColumn(2);
    userListFormUi->userListWidget->insertColumn(3);
    QStringList q;
    q.append("First name");
    q.append("Last name");
    q.append("University");
    q.append("Email");
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q);
    userListFormUi->userListWidget->horizontalHeader()->setStretchLastSection(true);
    userListFormUi->userListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    userListFormUi->userListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i =0; i<nUsers; ++i)
    {
       userListFormUi->userListWidget->insertRow(i);
       users[i].item[0].setText("jjj");
       users[i].item[1].setText("vvv");
       users[i].item[2].setText("ddd");
       users[i].item[3].setText("eee");
       users[i].ShowInQTalbeRow(userListFormUi->userListWidget,4,i);
    }



}

UserListForm::~UserListForm()
{
    delete userListFormUi;
    delete[] users;
}


void UserListForm::on_userListWidget_cellPressed(int row, int column)
{

}
