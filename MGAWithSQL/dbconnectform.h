#ifndef DBCONNECTFORM_H
#define DBCONNECTFORM_H

#include <QWidget>
#include "dbconnectionsetups.h"
#include "sqlmacro.h"
#include "mgauserrolesenum.h"

namespace Ui {
class DBConnectForm;
}

class DBConnectForm : public QWidget
{
    Q_OBJECT

public:
    explicit DBConnectForm(QWidget *parent = 0);

    ~DBConnectForm();
    DECLAIR_SQL_REQUIRED_MEMBERS
    EUserRole GetCurrentUserRole();
    QString GetCurrentUserRoleName();
    unsigned int GetUserNumber();

signals:
    void DatabaseIsconnected();
    void DatabaseIsDisconnected();


private slots:
    void OnDataBaseIsconnected();

    void OnDatabaseIsDisconnected();

    void on_connectToDBButton_clicked();

    void on_disconnectDBButton_clicked();

private:
    Ui::DBConnectForm *dbConnectFormUi;
    bool bDatabaseIsconnected = false;
    EUserRole eCurrentUserRole = eUNKNOWN;
    QString sCurrentUserRoleName = UNKNOWN_ROLE;
    unsigned int nUserCounts = 0;


};

#endif // DBCONNECTFORM_H
