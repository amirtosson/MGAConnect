#ifndef DBCONNECTFORM_H
#define DBCONNECTFORM_H

#include <QWidget>
#include <QTableWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QHostAddress>
#include <QSettings>
#include <vector>
#include <QRect>


#include "dbconnectionsetups.h"
#include "mgauserrolesenum.h"
#include "mgamember.h"
#include "mgadatabase.h"
#include "mgauser.h"
#include "mgaserverclientmsg.h"
#include "mgaappointment.h"
#include "mgaexperiment.h"
#include "MGAResizableWidgetAbstract.h"

#define UNKNOWN_ROLE      "unknown"

namespace Ui {
class DBConnectForm;
}

class DBConnectForm : public QWidget, MGAResizableWidget
{
    Q_OBJECT

public:
    explicit DBConnectForm(QWidget *parent = 0);

    ~DBConnectForm();
    //DECLAIR_SQL_REQUIRED_MEMBERS
    EUserRole GetCurrentUserRole();
    QString GetCurrentUserRoleName();
    unsigned int GetUserNumber();
    bool ShowListInQTalbe(QTableWidget *table, EMSGType eMsgType);
    bool AddNewMGAUsers(MGAUser *newUser);
    void CleanLists();

public slots:
    void OnSizeChange(int w, int h) override;

signals:
    void DatabaseIsconnected();
    void DatabaseIsDisconnected();
    void ListIsReady(EMSGType eMsgType);
    void ExpListIsReady();
    void AppointListIsReady();



public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private slots:
    void OnDataBaseIsconnected();
    void OnDatabaseIsDisconnected();
    void OnListIsReady(EMSGType eMsgType);
    void on_connectToDBButton_clicked();
    void on_disconnectDBButton_clicked();
    void on_updateDetailsButton_clicked();
    void on_loadDetailsButton_clicked();

private:
    Ui::DBConnectForm *dbConnectFormUi;
    bool bDatabaseIsconnected = false;
    EUserRole eCurrentUserRole = eUNKNOWN;
    QString sCurrentUserRoleName = UNKNOWN_ROLE;
    unsigned int nMemberCount = 0;
    unsigned int nUserCount = 0;
    unsigned int nExpCount = 0;
    unsigned int nAppointCount = 0;
    std::vector<MGAMember> mgaMembersList;
    std::vector<MGAUser> mgaUsersList;
    std::vector<MGAExperiment> mgaExpsList;
    std::vector<MGAAppointment> mgaAppointsList;
    std::vector<MGADatabase> databases;
    QTcpSocket *socket;
    bool IsUsersListUpdated = false;
    EMSGType eCurrentMsgType = EMSGType::eUNKNOWN;

    QTableWidget *mainTable;
    QIcon btnIcon;

private:
    void ServerMSGHandling(MGAServerClientMSG *msg);
    void SerializeUsersListFromMSG(MGAServerClientMSG *msg);
    void SerializeMemberssListFromMSG(MGAServerClientMSG *msg);
    void SerializeExpsListFromMSG(MGAServerClientMSG *msg);
    void SerializeAppointmentsListFromMSG(MGAServerClientMSG *msg);
    bool SendServerGetListMSG(EMSGType eMsgType);


private:
    void UpdateSizes(int w, int h) override;
    void SetIconSize(int h) override;

};

#endif // DBCONNECTFORM_H
