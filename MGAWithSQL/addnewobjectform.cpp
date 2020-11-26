#include "addnewobjectform.h"


void AddNewObjectForm::setupUi(QDialog *AddNewObjectForm)
{
    if (AddNewObjectForm->objectName().isEmpty())
    {
        AddNewObjectForm->setObjectName(QString::fromUtf8("AddNewObjectForm"));
    }
    AddNewObjectForm->resize(400,300);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(5);
    sizePolicy.setVerticalStretch(5);
    sizePolicy.setHeightForWidth(AddNewObjectForm->sizePolicy().hasHeightForWidth());
    AddNewObjectForm->setSizePolicy(sizePolicy);

    okButton = new QPushButton(AddNewObjectForm);
    okButton->setObjectName(QString::fromUtf8("OkButton"));
    cancelButton = new QPushButton(AddNewObjectForm);
    cancelButton->setObjectName(QString::fromUtf8("CancelButton"));

    QMetaObject::connectSlotsByName(AddNewObjectForm);
}

AddNewObjectForm::AddNewObjectForm(QWidget *parent, EListType eList):
        QDialog(parent)
{
        setupUi(this);
        eCurrentList = eList;
        switch (eCurrentList) {
        case eUsersList:
            {
                newUser = new MGAUser();
                if (IntializeUserGUIComponents(this))
                ResizeComponents(this->width(), this->height());
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
    //delete ui;
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

MGAMember *AddNewObjectForm::GetTheNewMember()
{
    return newMember;
}

MGAExperiment *AddNewObjectForm::GetTheNewExp()
{
    return newExp;
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
    w = w*0.75;
    h = h*0.75;
    this->resize(w,h);
    ResizeComponents(w,h);
}

void AddNewObjectForm::SetIconSize(int h)
{

}

