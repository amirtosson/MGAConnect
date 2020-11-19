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
    return true;
}

bool DBMainWindowControls::IntializeDBConnectionForm(QWidget *dbConnectionWidget)
{
    _dbForm = new DBConnectForm(dbConnectionWidget);
    hasDBForm = true;
    return true;

}

bool DBMainWindowControls::IntializeMembersListForm(QWidget *membersListWidget)
{
    _membersListForm = new MGAListForm(membersListWidget, eMemberList);
    return true;

}

bool DBMainWindowControls::IntializeDatabasesListForm(QWidget *databasesListWidget)
{
    _databasesListForm = new MGAListForm(databasesListWidget, eDatabasesList);
    hasDatabasesListForm = true;
    return true;

}

bool DBMainWindowControls::IntializeUsersListForm(QWidget *usersListWidget)
{
    _usersListForm = new MGAListForm(usersListWidget, eUsersList);
    return true;

}

bool DBMainWindowControls::IntializeExperimentsListForm(QWidget *usersListWidget)
{
    _experimentsListForm = new MGAListForm(usersListWidget, eExperimentist);
    return true;
}

bool DBMainWindowControls::AddNewMGAUserToDB()
{
    _dbForm->AddNewMGAUsers(_usersListForm->GetTheNewUser());
    return true;

}

bool DBMainWindowControls::ShowMembersList()
{
    if(!hasMembersListForm)_dbForm->ShowMembersInQTalbe(_membersListForm->GetUITable());
    _membersListForm->show();
    hasMembersListForm = true;
    return true;

}

bool DBMainWindowControls::ShowDatabasesList()
{
    _databasesListForm->show();
    return true;

}

bool DBMainWindowControls::ShowUsersList()
{
    if(!hasUsersListForm)_dbForm->ShowUsersInQTalbe(_usersListForm->GetUITable());
    _usersListForm->show();
    hasUsersListForm = true;
    return true;

}

bool DBMainWindowControls::ShowExperimentsList()
{
   // if(!hasExpListForm)_dbForm              ->ShowUsersInQTalbe(_usersListForm->GetUITable());
    _experimentsListForm->show();
    hasExpListForm = true;
    return true;
}

void DBMainWindowControls::HideAll()
{
    if(hasDBForm)_dbForm->hide();
    if(hasOptionForm)_OptionForm->hide();
    if(hasMembersListForm)_membersListForm->hide();
    if(hasDatabasesListForm)_databasesListForm->hide();
    if(hasUsersListForm)_usersListForm->hide();
    if(hasExpListForm)_experimentsListForm->hide();
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
   return  _dbForm->GetCurrentUserRoleName();
}


