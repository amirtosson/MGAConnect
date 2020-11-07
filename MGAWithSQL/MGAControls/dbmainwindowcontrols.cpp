#include "dbmainwindowcontrols.h"

DBMainWindowControls::DBMainWindowControls(QWidget *parent)
{

}

DBMainWindowControls::~DBMainWindowControls()
{
    if(hasDBForm)delete _dbForm;
    if(hasOptionForm)delete _OptionForm;
    if(hasDatabasesListForm)delete _databasesListForm;
}

bool DBMainWindowControls::IntializeSidePanel(QWidget *sidePanelWidget)
{
    _sidePanal = new SidePanel(sidePanelWidget);
    _sidePanal->hide();
}

bool DBMainWindowControls::IntializeDBConnectionForm(QWidget *dbConnectionWidget)
{
    _dbForm = new DBConnectForm(dbConnectionWidget);
    hasDBForm = true;
}

bool DBMainWindowControls::IntializeMembersListForm(QWidget *membersListWidget)
{
    _membersListForm = new MGAListForm(membersListWidget, eMemberList);
}

bool DBMainWindowControls::IntializeDatabasesListForm(QWidget *databasesListWidget)
{
    _databasesListForm = new MGAListForm(databasesListWidget, eDatabasesList);
    hasDatabasesListForm = true;
}

bool DBMainWindowControls::IntializeUsersListForm(QWidget *usersListWidget)
{
    _usersListForm = new MGAListForm(usersListWidget, eUsersList);
}

bool DBMainWindowControls::AddNewMGAUserToDB()
{
    _dbForm->AddNewMGAUsers(_usersListForm->GetTheNewUser());
}

bool DBMainWindowControls::ShowMembersList()
{
    if(!hasMembersListForm)_dbForm->ShowMembersInQTalbe(_membersListForm->GetUITable());
    _membersListForm->show();
    hasMembersListForm = true;
}

bool DBMainWindowControls::ShowDatabasesList()
{
    _databasesListForm->show();
}

bool DBMainWindowControls::ShowUsersList()
{
    if(!hasUsersListForm)_dbForm->ShowUsersInQTalbe(_usersListForm->GetUITable());
    _usersListForm->show();
    hasUsersListForm = true;
}

void DBMainWindowControls::HideAll()
{
    if(hasDBForm)_dbForm->hide();
    if(hasOptionForm)_OptionForm->hide();
    if(hasMembersListForm)_membersListForm->hide();
    if(hasDatabasesListForm)_databasesListForm->hide();
    if(hasUsersListForm)_usersListForm->hide();
}

void DBMainWindowControls::SetLoginUserRole()
{
    _sidePanal->SetCurrentRole(_dbForm->GetCurrentUserRole());
}

EUserRole DBMainWindowControls::GetLoginUserRole()
{
    return _dbForm->GetCurrentUserRole();
}

QString DBMainWindowControls::GetLoginUserRoleName()
{
    _dbForm->GetCurrentUserRoleName();
}


