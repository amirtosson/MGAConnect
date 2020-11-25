#include "mgalistform.h"
#include "ui_mgalistform.h"
#include <QDebug>

MGAListForm::MGAListForm(QWidget *parent, EListType eList) :
    QWidget(parent),
    userListFormUi(new Ui::MGAListForm),
    eCurrentListType(eList)
{
    userListFormUi->setupUi(this);
    const QIcon searchIcon =  QIcon(":/buttonIcons/Resources/Icons/search.png");
    QAction *openAct = new QAction(searchIcon,tr("search"), this);
    userListFormUi->searchTextBox->addAction(openAct,QLineEdit::LeadingPosition);

    switch (eCurrentListType) {
    case eUsersList:
        {
            USERS_LIST_FORM_SETUP           
            BUTTONS_SETUP
        }
        break;
    case eMemberList:
        {
            MEMBERS_LIST_FORM_SETUP
            BUTTONS_SETUP
        }
        break;
    case eDatabasesList:
        {
            DATABASES_LIST_FORM_SETUP
        }
        break;
    case eExperimentist:
        {
            EXP_LIST_FORM_SETUP
            BUTTONS_SETUP_DEFAULT
        }
        break;
    case eAppointmentList:
        {
            APPOINTS_LIST_FORM_SETUP
            BUTTONS_SETUP_DEFAULT
        }
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
    if(hasAddNewObjectForm) delete addNewObject;
}

MGAUser *MGAListForm::GetTheNewUser()
{
    return  addNewObject->GetTheNewUser();
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

void MGAListForm::UpdateTableColumsWidth(int w)
{
    for (int i = 0; i < (userListFormUi->userListWidget->columnCount()-1);++i )
    {
        userListFormUi->userListWidget->setColumnWidth(i, w / (userListFormUi->userListWidget->columnCount()));
    }

}

void MGAListForm::UpdateSizes(int w, int h)
{
    this->resize(w,h);
    userListFormUi->pageTitle->resize(w-20,50);
    userListFormUi->userListWidget->resize(TABLE_VIEW_WIDTH_RATIO*w, h-260);
    UpdateTableColumsWidth(TABLE_VIEW_WIDTH_RATIO*w);
    SetIconSize(h*TABLE_VIEW_ICON_RATIO);
}

void MGAListForm::SetIconSize(int h)
{
    userListFormUi->editUserButton->setIconSize(QSize(h, h));
    userListFormUi->deleteUserButton->setIconSize(QSize(h, h));
    userListFormUi->addUserButton->setIconSize(QSize(h, h));
}

void MGAListForm::on_editUserButton_clicked()
{

}

void MGAListForm::on_addUserButton_clicked()
{
    try
    {
        if(!hasAddNewObjectForm)
        {
           addNewObject = new AddNewObjectForm(this, eCurrentListType);
           connect(addNewObject, SIGNAL(NewObjectIsToBeAdded()),this ,SLOT(NewObjectIsReady()));
           addNewObject->setModal(true);
           addNewObject->exec();
        }

        else
        {
            addNewObject->open();
        }
    }
    catch(int e)
    {
        qDebug()<<e;
    }

    hasAddNewObjectForm = true;
}

void MGAListForm::NewObjectIsReady()
{
    emit NewObjectIsReadyToAdd(eCurrentListType);
}

void MGAListForm::on_searchTextBox_textChanged(const QString &arg1)
{
    for (int i =0; i< userListFormUi->userListWidget->rowCount(); ++i )
    {
        QTableWidgetItem *item = userListFormUi->userListWidget->item(i,0);
        if(!item->text().toLower().contains(arg1))
        {
            userListFormUi->userListWidget->hideRow(i);
        }
        else
        {
            userListFormUi->userListWidget->showRow(i);
        }
    }

}

void MGAListForm::OnSizeChange(int w, int h)
{
    w = MAIN_WIDGET_WIDTH_RATIO*w;
    h = MAIN_WIDGET_HEIGHT_RATIO*h;
    UpdateSizes(w,h);
}


