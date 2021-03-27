#ifndef DBMAINWINDOWCONTROLS_H
#define DBMAINWINDOWCONTROLS_H

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <utility>

#include "dbconnectform.h"
#include "sidepanel.h"
#include "optionform.h"
#include "mainwindowresources.h"
#include "mgalistform.h"
#include "mgaserverclientmsg.h"
#include "mgachatform.h"
#include "mgachatbotservercontrols.h"
#include "addnewobjectform.h"
#include "mgaservercontrols.h"


class DBMainWindowControls
{

public:
    void SetCurrentMainWindowInstanceControls(QMainWindow *mainWindow);
    // Components intialization
    bool IntializeChatDialog(QWidget *parent);
    bool IntializeSetupDialog(QWidget *parent);
    bool IntializeChatbot();
    bool IntializeSidePanel(QWidget *sidePanelWidget);
    bool IntializeDBConnectionForm(QWidget *dbConnectionWidget);
    bool IntializeMembersListForm(QWidget *membersListWidget);    
    bool IntializeDatabasesListForm(QWidget *databasesListWidget);
    bool IntializeUsersListForm(QWidget *usersListWidget);
    bool IntializeExperimentsListForm(QWidget *usersListWidget);
    bool IntializeAppointmentsListForm(QWidget *appointsListWidget);
    bool IntializeGroupsListForm(QWidget *groupsListWidget);
    bool IntializeOptionsForm(QWidget *optionsWidget);
    bool IntializeDBFOrmConnections();
    bool IntializeMGAServer();
    bool IntializeSeverConnections();
    void SaveServerParametersAsSetting();

    bool ShowMembersList();
    bool ShowDatabasesList();
    bool ShowGroupsList();
    bool ShowUsersList();
    bool ShowExperimentsList();
    bool ShowAppointmentsList();
    bool AddNewMGAUserToDB();
    bool AddNewMGAMemberToDB();
    bool AddNewMGAExpToDB();
    bool AddNewMGAAppointmentToDB();

    void HideAll();
    void SetLoginUserRole();
    void HideChatWindow();
    void ShowChatWindow();

    void Clean();

public:
    EUserRole GetLoginUserRole();
    QString GetLoginUserRoleName();

protected:
    DBConnectForm *_dbForm;
    SidePanel *_sidePanal;
    OptionForm *_OptionForm;
    MGAListForm *_membersListForm;
    MGAListForm *_databasesListForm;
    MGAListForm *_usersListForm;
    MGAListForm *_experimentsListForm;
    MGAListForm *_appointmentsListForm;
    MGAListForm *_groupsListForm;
    MGAChatForm *_chatForm;
    MGAChatBotServerControls *_chatbotServer;
    AddNewObjectForm *_setupForm;
    MGAServerControls *_mgaServer;
    QMainWindow *currentMainWindow;

    bool hasDBForm = false;
    bool hasOptionForm = false;
    bool hasMembersListForm = false;
    bool hasDatabasesListForm = false;
    bool hasUsersListForm = false;
    bool hasExpListForm = false;
    bool hasAppointListForm = false;
    bool hasGroupsListForm = false;
    bool IsUsersListChanged = false;
    bool HasChatWindow = true;
};

#endif // DBMAINWINDOWCONTROLS_H
