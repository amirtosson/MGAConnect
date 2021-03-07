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

bool DBMainWindowControls::IntializeChatDialog(QWidget *parent)
{
    try
    {
        _chatForm = new MGAChatForm(parent);
        _chatForm->setWindowFlags(Qt::Window | Qt::FramelessWindowHint );
        _chatForm->show();
    }
    catch (...)
    {
        return false;
    }

    return true;
}

bool DBMainWindowControls::IntializeChatbot()
{
    try
    {
        socket = new QTcpSocket();
        _chatbotServer = new MGAChatBotServerControls(socket);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

bool DBMainWindowControls::IntializeSidePanel(QWidget *sidePanelWidget)
{
    try
    {
        _sidePanal = new SidePanel(sidePanelWidget);
        _sidePanal->hide();
    }
    catch (...)
    {
        return false;
    }

    return true;
}

bool DBMainWindowControls::IntializeDBConnectionForm(QWidget *dbConnectionWidget)
{
    try
    {
        _dbForm = new DBConnectForm(dbConnectionWidget);
        hasDBForm = true;
    }
    catch (...)
    {
        return false;
    }

    return true;

}

bool DBMainWindowControls::IntializeMembersListForm(QWidget *membersListWidget)
{

    try
    {
        _membersListForm = new MGAListForm(membersListWidget, eMemberList);
    }
    catch (...)
    {
        return false;
    }
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

bool DBMainWindowControls::IntializeAppointmentsListForm(QWidget *appointsListWidget)
{
    _appointmentsListForm = new MGAListForm(appointsListWidget, eAppointmentList);
    return true;
}

bool DBMainWindowControls::IntializeGroupsListForm(QWidget *groupsListWidget)
{
    _groupsListForm = new MGAListForm(groupsListWidget, eGroupsList);
    return true;
}

bool DBMainWindowControls::AddNewMGAUserToDB()
{
    _dbForm->AddNewMGAUsers(_usersListForm->GetTheNewUser());
    return true;

}

bool DBMainWindowControls::AddNewMGAMemberToDB()
{
    return true;
}

bool DBMainWindowControls::AddNewMGAExpToDB()
{
    return true;
}

bool DBMainWindowControls::AddNewMGAAppointmentToDB()
{
    return true;
}

bool DBMainWindowControls::ShowMembersList()
{
    if(!hasMembersListForm)_dbForm->ShowListInQTalbe(_membersListForm->GetUITable(), EMSGType::eGetMembersList);
    _membersListForm->show();
    hasMembersListForm = true;
    return true;

}

bool DBMainWindowControls::ShowDatabasesList()
{
    _databasesListForm->show();
    return true;

}

bool DBMainWindowControls::ShowGroupsList()
{
    _groupsListForm->show();
    hasGroupsListForm = true;
    return true;
}

bool DBMainWindowControls::ShowUsersList()
{
    if(!hasUsersListForm)_dbForm->ShowListInQTalbe(_usersListForm->GetUITable(), EMSGType::eGetUsersList);
    _usersListForm->show();
    hasUsersListForm = true;
    return true;

}

bool DBMainWindowControls::ShowExperimentsList()
{
    if(!hasExpListForm)_dbForm->ShowListInQTalbe(_experimentsListForm->GetUITable(), EMSGType::eGetExpList);
    _experimentsListForm->show();
    hasExpListForm = true;
    return true;
}

bool DBMainWindowControls::ShowAppointmentsList()
{
    if(!hasAppointListForm)_dbForm->ShowListInQTalbe(_appointmentsListForm->GetUITable(), EMSGType::eGetAppointsList);
    _appointmentsListForm->show();
    hasAppointListForm = true;
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
    if(hasAppointListForm)_appointmentsListForm->hide();
    if(hasGroupsListForm)_groupsListForm->hide();
}

void DBMainWindowControls::SetLoginUserRole()
{
    _sidePanal->SetCurrentRole(_dbForm->GetCurrentUserRole());
}

void DBMainWindowControls::HideChatWindow()
{
    _chatForm->hide();
}

void DBMainWindowControls::ShowChatWindow()
{
    _chatForm->show();
}

EUserRole DBMainWindowControls::GetLoginUserRole()
{
    return _dbForm->GetCurrentUserRole();
}

QString DBMainWindowControls::GetLoginUserRoleName()
{
   return  _dbForm->GetCurrentUserRoleName();
}


