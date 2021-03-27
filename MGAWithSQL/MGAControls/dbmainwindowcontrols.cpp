#include "dbmainwindowcontrols.h"
#include <QSettings>

void DBMainWindowControls::Clean()
{
    if(hasDBForm)delete _dbForm;
    if(hasOptionForm)delete _OptionForm;
    if(hasDatabasesListForm)delete _databasesListForm;
}

void DBMainWindowControls::SetCurrentMainWindowInstanceControls(QMainWindow *mainWindow)
{
    currentMainWindow = mainWindow;
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

bool DBMainWindowControls::IntializeSetupDialog(QWidget *parent)
{
    try
    {
        _setupForm = new AddNewObjectForm(parent, eSetup);
        _setupForm->setModal(true);
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_setupForm, SIGNAL(NewObjectIsToBeAdded()),currentMainWindow ,SLOT(ServerSetupChanged()));
    _setupForm->exec();
    return true;
}

bool DBMainWindowControls::IntializeChatbot()
{
    try
    {
        _chatbotServer = new MGAChatBotServerControls();
    }
    catch (...)
    {
        return false;
    }

    QObject::connect(_chatForm, SIGNAL(ChatBotMSGHasBeenSent(QString)),_chatbotServer ,SLOT(UserToChatBotMSGHasBeenSent(QString)));
    QObject::connect(_chatbotServer, SIGNAL(MSGRecieved(QString, int)), _chatForm ,SLOT(OnMSGHasBeenRecieved(QString, int)));
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
    QObject::connect(_sidePanal, SIGNAL(DBCOnnectionButtonClicked()),currentMainWindow ,SLOT(DBConnectionSetUpClicked()));
    QObject::connect(_sidePanal, SIGNAL(ShowMembersListButtonClicked()),currentMainWindow ,SLOT(ShowMemberListClicked()));
    QObject::connect(_sidePanal, SIGNAL(ShowDatabasesListButtonClicked()),currentMainWindow ,SLOT(ShowDatabasesListClicked()));
    QObject::connect(_sidePanal, SIGNAL(ShowUserListButtonIsClicked()),currentMainWindow ,SLOT(ShowUserListClicked()));
    QObject::connect(_sidePanal, SIGNAL(ShowExperimentsListButtonIsClicked()),currentMainWindow ,SLOT(ShowExperimentsListClicked()));
    QObject::connect(_sidePanal, SIGNAL(ShowAppointmentsListButtonClicked()),currentMainWindow ,SLOT(ShowAppointmentsListClicked()));
    QObject::connect(_sidePanal, SIGNAL(ShowGroupsButtonClicked()),currentMainWindow ,SLOT(ShowGroupsListClicked()));

    return true;
}

bool DBMainWindowControls::IntializeDBConnectionForm(QWidget *dbConnectionWidget)
{
    try
    {
        _dbForm = new DBConnectForm(dbConnectionWidget, _mgaServer->GetServerSocket());
        hasDBForm = true;
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_dbForm, SIGNAL(DatabaseIsconnected()),currentMainWindow ,SLOT(DatabaseHasConnection()));
    QObject::connect(_dbForm, SIGNAL(DatabaseIsDisconnected()),currentMainWindow ,SLOT(DatabaseNotConnected()));
    QObject::connect(_dbForm, SIGNAL(DatabaseIsconnected()),_sidePanal ,SLOT(DatabaseIsConnected()));
    QObject::connect(_dbForm, SIGNAL(DatabaseIsDisconnected()),_sidePanal ,SLOT(DatabaseIsDisconnected()));
    QObject::connect(currentMainWindow, SIGNAL(SizeChanged(int,int)),_dbForm ,SLOT(OnSizeChange(const int, const int)));
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
    QObject::connect(_membersListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),currentMainWindow ,SLOT(AddNewObjectClicked(const EListType)));
    QObject::connect(currentMainWindow, SIGNAL(SizeChanged(int,int)),_membersListForm ,SLOT(OnSizeChange(const int, const int)));
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
    try
    {
        _usersListForm = new MGAListForm(usersListWidget, eUsersList);
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_usersListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),currentMainWindow ,SLOT(AddNewObjectClicked(const EListType)));
    QObject::connect(currentMainWindow, SIGNAL(SizeChanged(int,int)),_usersListForm ,SLOT(OnSizeChange(const int, const int)));
    return true;
}

bool DBMainWindowControls::IntializeExperimentsListForm(QWidget *usersListWidget)
{
    try
    {
        _experimentsListForm = new MGAListForm(usersListWidget, eExperimentist);
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_experimentsListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),currentMainWindow ,SLOT(AddNewObjectClicked(const EListType)));
    QObject::connect(currentMainWindow, SIGNAL(SizeChanged(int,int)),_experimentsListForm ,SLOT(OnSizeChange(const int, const int)));
    return true;
}

bool DBMainWindowControls::IntializeAppointmentsListForm(QWidget *appointsListWidget)
{
    try
    {
        _appointmentsListForm = new MGAListForm(appointsListWidget, eAppointmentList);
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_appointmentsListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),currentMainWindow ,SLOT(AddNewObjectClicked(const EListType)));
    QObject::connect(currentMainWindow, SIGNAL(SizeChanged(int,int)),_appointmentsListForm ,SLOT(OnSizeChange(const int, const int)));
    return true;
}

bool DBMainWindowControls::IntializeGroupsListForm(QWidget *groupsListWidget)
{
    try
    {
        _groupsListForm = new MGAListForm(groupsListWidget, eGroupsList);
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_groupsListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),currentMainWindow ,SLOT(AddNewObjectClicked(const EListType)));
    QObject::connect(currentMainWindow, SIGNAL(SizeChanged(int,int)),_groupsListForm ,SLOT(OnSizeChange(const int, const int)));
    return true;
}

bool DBMainWindowControls::IntializeOptionsForm(QWidget *optionsWidget)
{
    try
    {
        _OptionForm = new OptionForm(optionsWidget);
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_OptionForm, SIGNAL(StyleIsChanged()),currentMainWindow ,SLOT(StyleHasBeenChanged()));
    return true;
}

bool DBMainWindowControls::IntializeMGAServer()
{
    try
    {
        _mgaServer= new MGAServerControls();
    }
    catch (...)
    {
        return false;
    }
    QObject::connect(_mgaServer ,SIGNAL(OpenSettingWindow()), currentMainWindow, SLOT(on_actionOptions_triggered()));

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

bool DBMainWindowControls::IntializeSeverConnections()
{
    return _mgaServer->IntializeSeverConnections();
}


void DBMainWindowControls::SaveServerParametersAsSetting()
{
    _mgaServer->SaveServerParametersAsSetting(*_setupForm->GetServerSetup());
}

EUserRole DBMainWindowControls::GetLoginUserRole()
{
    return _dbForm->GetCurrentUserRole();
}

QString DBMainWindowControls::GetLoginUserRoleName()
{
   return  _dbForm->GetCurrentUserRoleName();
}


