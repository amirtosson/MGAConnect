#ifndef DBMAINWINDOWCONTROLS_H
#define DBMAINWINDOWCONTROLS_H

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>

#include "dbconnectform.h"
#include "sidepanel.h"
#include "optionform.h"
#include "mainwindowresources.h"
#include "mgalistform.h"

class DBMainWindowControls
{

public:

    explicit DBMainWindowControls(QWidget *parent = 0);
    ~DBMainWindowControls();

public:
    // Components intialization
    bool IntializeSidePanel(QWidget *sidePanelWidget);
    bool IntializeDBConnectionForm(QWidget *dbConnectionWidget);
    bool IntializeMembersListForm(QWidget *membersListWidget);    
    bool IntializeDatabasesListForm(QWidget *databasesListWidget);
    bool IntializeUsersListForm(QWidget *usersListWidget);
    bool IntializeExperimentsListForm(QWidget *usersListWidget);
    bool IntializeAppointmentsListForm(QWidget *appointsListWidget);


    bool IntializeDBFOrmConnections();


public:
    bool ShowMembersList();
    bool ShowDatabasesList();
    bool ShowUsersList();
    bool ShowExperimentsList();
    bool ShowAppointmentsList();
    bool AddNewMGAUserToDB();
    bool AddNewMGAMemberToDB();
    bool AddNewMGAExpToDB();
    bool AddNewMGAAppointmentToDB();
    void HideAll();

public:
    void SetLoginUserRole();


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



    bool hasDBForm = false;
    bool hasOptionForm = false;
    bool hasMembersListForm =false;
    bool hasDatabasesListForm =false;
    bool hasUsersListForm =false;
    bool hasExpListForm =false;
    bool hasAppointListForm =false;


    bool IsUsersListChanged =false;


};

#endif // DBMAINWINDOWCONTROLS_H
