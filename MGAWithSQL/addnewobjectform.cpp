#include "addnewobjectform.h"
#include "ui_addnewobjectform.h"


AddNewObjectForm::AddNewObjectForm(QWidget *parent, EListType eList):
        QDialog(parent),
        ui(new Ui::AddNewObjectForm)
{
        ui->setupUi(this);
        eCurrentList = eList;
        switch (eCurrentList) {
        case eUsersList:
            {
                newUser = new MGAUser();
                IntializeUserGUIComponents(this);
            }
            break;
        case eMemberList:
            {
                newMember = new MGAMember();
                IntializeMemberGUIComponents(this);
            }
            break;
        default:
            break;
        }

}



AddNewObjectForm::~AddNewObjectForm()
{
    delete ui;
    switch (eCurrentList) {
    case eUsersList:
        delete newUser;
        break;
    case eMemberList:
        delete newMember;
        break;
    default:
        break;
    }
}

MGAUser* AddNewObjectForm::GetTheNewUser()
{
    return newUser;
}

void AddNewObjectForm::on_okButton_clicked()
{

    switch (eCurrentList) {
    case eUsersList:
        {
            if (GetNewUser())
            {
                emit NewUserIsToBeAdded();
                this->close();
            }
        }
        break;
    case eMemberList:
        {
            if (GetNewMember())
            {
                //emit NewUserIsToBeAdded();
                this->close();
            }
        }
        break;
    default:
        break;
    }





}

void AddNewObjectForm::on_cancelButton_clicked()
{
    this->close();
}

bool AddNewObjectForm::GetNewUser()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, TXT_ADD_USER_MSG_BOX_LABEL, TXT_MSG_BOX_ADD_USER,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        std::string str = GetUserName().toStdString();
        newUser->SetName(str);
        str = GetUserPWD().toStdString();
        newUser->SetPWD(str);
        str = GetUserHost().toStdString();
        newUser->SetHost(str);
        str = GetUserRole().toStdString();
        newUser->SetRole(str);
    }
    return true;
}

bool AddNewObjectForm::GetNewMember()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, TXT_ADD_MEMBER_MSG_BOX_LABEL, TXT_MSG_BOX_ADD_MEMBER,
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {

    }
    return true;
}
