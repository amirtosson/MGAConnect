#include "addnewobjectform.h"

AddNewObjectForm::AddNewObjectForm(QWidget *parent, EListType eList):
        QDialog(parent),
        eCurrentList(eList)
{
        setupUi(this, eCurrentList);
        ResizeComponents(this->width(), this->height());
        switch (eCurrentList) {
        case eUsersList:
            {
                newUser = new MGAUser();
            }
            break;
        case eMemberList:
            {
                newMember = new MGAMember();
            }
            break;
        case eExperimentist:
            {
                newExp = new MGAExperiment();
            }
            break;
        case eAppointmentList:
            {
                newAppoint = new MGAAppointment();
            }
            break;
        case eSetup:
            {
                newSetup = new QStringList();
            }
            break;
        default:
            break;
        }

}



AddNewObjectForm::~AddNewObjectForm()
{
    //delete ui;
    switch (eCurrentList) {
    case eUsersList:
        delete newUser;
        break;
    case eMemberList:
        delete newMember;
        break;
    case eExperimentist:
        delete newExp;
        break;
    case eAppointmentList:
        delete newAppoint;
        break;
    case eSetup:
        delete newSetup;
        break;
    default:
        break;
    }
}

MGAUser* AddNewObjectForm::GetTheNewUser()
{
    return newUser;
}

MGAMember* AddNewObjectForm::GetTheNewMember()
{
    return newMember;
}

MGAExperiment* AddNewObjectForm::GetTheNewExp()
{
    return newExp;
}

QStringList *AddNewObjectForm::GetServerSetup()
{
    return newSetup;
}

void AddNewObjectForm::OnSizeChange(int w, int h)
{
    UpdateSizes(w,h);
}

void AddNewObjectForm::on_OkButton_clicked()
{

    switch (eCurrentList) {
    case eUsersList:
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, TXT_ADD_USER_MSG_BOX_LABEL, TXT_MSG_BOX_ADD_USER,
                                          QMessageBox::Yes|QMessageBox::No);
            if ((reply == QMessageBox::Yes) && AcceptNewUser())
            {
                emit NewObjectIsToBeAdded();
                this->close();
            }
        }
        break;
    case eMemberList:
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, TXT_ADD_MEMBER_MSG_BOX_LABEL, TXT_MSG_BOX_ADD_MEMBER,
                                          QMessageBox::Yes|QMessageBox::No);
            if ((reply == QMessageBox::Yes) && AcceptNewMember())
            {
                //emit NewUserIsToBeAdded();
                this->close();
            }
        }
        break;
    case eSetup:
        {
            *newSetup = GetLinesFields();
            emit NewObjectIsToBeAdded();
        }
        break;
    default:
        break;
    }

}

void AddNewObjectForm::on_CancelButton_clicked()
{
    this->close();
}

bool AddNewObjectForm::AcceptNewUser()
{
    std::string str = GetUserName().toStdString();
    newUser->SetName(str);
    str = GetUserPWD().toStdString();
    newUser->SetPWD(str);
    str = GetUserHost().toStdString();
    newUser->SetHost(str);
    str = GetUserRole().toStdString();
    newUser->SetRole(str);
    return true;
}

bool AddNewObjectForm::AcceptNewMember()
{
    return true;
}

void AddNewObjectForm::UpdateSizes(int w, int h)
{
    w = w * ADD_NEW_FORM_WIDTH_RATIO;
    h = h * ADD_NEW_FORM_HEIGHT_RATIO;
    this->resize(w,h);
    ResizeComponents(w,h);
}

void AddNewObjectForm::SetIconSize(int h)
{

}

