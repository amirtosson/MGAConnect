#include "mgamainwindowcontrols.h"
#include <QSettings>
#include <QThread>
#include <QMessageBox>

void MGAMainWindowControls::Clean()
{
    if(hasDBForm)delete _dbForm;
    if(hasOptionForm)delete _OptionForm;
    if(hasDatabasesListForm)delete _databasesListForm;
}

void MGAMainWindowControls::SetCurrentMainWindowInstanceControls(QMainWindow *mainWindow)
{
    currentMainWindow = mainWindow;
}

bool MGAMainWindowControls::IntializeChatDialog(QWidget *parent)
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

bool MGAMainWindowControls::IntializeSetupDialog(QWidget *parent)
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

bool MGAMainWindowControls::IntializeChatbot()
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

bool MGAMainWindowControls::IntializeSidePanel(QWidget *sidePanelWidget)
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

bool MGAMainWindowControls::IntializeDBConnectionForm(QWidget *dbConnectionWidget)
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

bool MGAMainWindowControls::IntializeMembersListForm(QWidget *membersListWidget)
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

bool MGAMainWindowControls::IntializeDatabasesListForm(QWidget *databasesListWidget)
{
    _databasesListForm = new MGAListForm(databasesListWidget, eDatabasesList);
    hasDatabasesListForm = true;
    return true;

}

bool MGAMainWindowControls::IntializeUsersListForm(QWidget *usersListWidget)
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

bool MGAMainWindowControls::IntializeExperimentsListForm(QWidget *usersListWidget)
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

bool MGAMainWindowControls::IntializeAppointmentsListForm(QWidget *appointsListWidget)
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

bool MGAMainWindowControls::IntializeGroupsListForm(QWidget *groupsListWidget)
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

bool MGAMainWindowControls::IntializeOptionsForm(QWidget *optionsWidget)
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

bool MGAMainWindowControls::IntializeMGAServer()
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

bool MGAMainWindowControls::AddNewMGAUserToDB()
{
    _dbForm->AddNewMGAUsers(_usersListForm->GetTheNewUser());
    return true;

}

bool MGAMainWindowControls::AddNewMGAMemberToDB()
{
    return true;
}

bool MGAMainWindowControls::AddNewMGAExpToDB()
{
    return true;
}

bool MGAMainWindowControls::AddNewMGAAppointmentToDB()
{
    return true;
}

bool MGAMainWindowControls::ShowMembersList()
{
    if(!hasMembersListForm)_dbForm->ShowListInQTalbe(_membersListForm->GetUITable(), EMSGType::eGetMembersList);
    _membersListForm->show();
    hasMembersListForm = true;
    return true;

}

bool MGAMainWindowControls::ShowDatabasesList()
{
    _databasesListForm->show();
    return true;

}

bool MGAMainWindowControls::ShowGroupsList()
{
    _groupsListForm->show();
    hasGroupsListForm = true;
    return true;
}

bool MGAMainWindowControls::ShowUsersList()
{
    if(!hasUsersListForm)_dbForm->ShowListInQTalbe(_usersListForm->GetUITable(), EMSGType::eGetUsersList);
    _usersListForm->show();
    hasUsersListForm = true;
    return true;

}

bool MGAMainWindowControls::ShowExperimentsList()
{
    if(!hasExpListForm)_dbForm->ShowListInQTalbe(_experimentsListForm->GetUITable(), EMSGType::eGetExpList);
    _experimentsListForm->show();
    hasExpListForm = true;
    return true;
}

bool MGAMainWindowControls::ShowAppointmentsList()
{
    if(!hasAppointListForm)_dbForm->ShowListInQTalbe(_appointmentsListForm->GetUITable(), EMSGType::eGetAppointsList);
    _appointmentsListForm->show();
    hasAppointListForm = true;
    return true;
}

void MGAMainWindowControls::HideAll()
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

void MGAMainWindowControls::SetLoginUserRole()
{
    _sidePanal->SetCurrentRole(_dbForm->GetCurrentUserRole());
}

void MGAMainWindowControls::HideChatWindow()
{
    _chatForm->hide();
}

void MGAMainWindowControls::ShowChatWindow()
{
    _chatForm->show();
}

bool MGAMainWindowControls::IntializeSeverConnections()
{
   // QThread *thread = new QThread;
    //_mgaServer->moveToThread(thread);
    //thread->start();
    //bool bConnected = _mgaServer->IntializeSeverConnections();
    //_mgaServer->moveToThread(QApplication::instance()->thread());
    return _mgaServer->IntializeSeverConnections();
}

void MGAMainWindowControls::SaveServerParametersAsSetting()
{
    _mgaServer->SaveServerParametersAsSetting(*_setupForm->GetServerSetup());
}

EUserRole MGAMainWindowControls::GetLoginUserRole()
{
    return _dbForm->GetCurrentUserRole();
}

QString MGAMainWindowControls::GetLoginUserRoleName()
{
   return  _dbForm->GetCurrentUserRoleName();
}


