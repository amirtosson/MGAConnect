#ifndef DBCONNECTFORM_H
#define DBCONNECTFORM_H

#include <QWidget>
#include <QTableWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QHostAddress>

#include <vector>
#include "dbconnectionsetups.h"
//#include "sqlmacro.h"
#include "mgauserrolesenum.h"
#include "mgamember.h"
#include "mgadatabase.h"
#include "mgauser.h"
#include "mgaserverclientmsg.h"

#define UNKNOWN_ROLE      "unknown"

namespace Ui {
class DBConnectForm;
}

class DBConnectForm : public QWidget
{
    Q_OBJECT

public:
    explicit DBConnectForm(QWidget *parent = 0);

    ~DBConnectForm();
    //DECLAIR_SQL_REQUIRED_MEMBERS
    EUserRole GetCurrentUserRole();
    QString GetCurrentUserRoleName();
    unsigned int GetUserNumber();
    bool ShowMembersInQTalbe(QTableWidget *table);
    bool ShowUsersInQTalbe(QTableWidget *table);
    bool AddNewMGAUsers(MGAUser *newUser);


    void CleanLists();


signals:
    void DatabaseIsconnected();
    void DatabaseIsDisconnected();
    void UsersListIsReady();
    void MembersListIsReady();


public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private slots:
    void OnDataBaseIsconnected();
    void OnDatabaseIsDisconnected();
    void OnUsersListIsReady();
    void OnMembersListIsReady();
    void on_connectToDBButton_clicked();
    void on_disconnectDBButton_clicked();

private:
    Ui::DBConnectForm *dbConnectFormUi;
    bool bDatabaseIsconnected = false;
    EUserRole eCurrentUserRole = eUNKNOWN;
    QString sCurrentUserRoleName = UNKNOWN_ROLE;
    unsigned int nMemberCount = 0;
    unsigned int nUserCount = 0;
    std::vector<MGAMember> mgaMembersList;
    std::vector<MGAUser> mgaUsersList;
    std::vector<MGADatabase> databases;
    QTcpSocket *socket;
    bool IsUsersListUpdated = false;
    QTableWidget *mainTable;

private:
    void ServerMSGHandling(MGAServerClientMSG *msg);
    void SerializeUsersListFromMSG(MGAServerClientMSG *msg);
    void SerializeMemberssListFromMSG(MGAServerClientMSG *msg);
    bool SendServerGetUserListMSG();
    bool SendServerGetMemberListMSG();

};

#endif // DBCONNECTFORM_H
