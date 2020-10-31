#include "dbconnectform.h"
#include "ui_dbconnectform.h"


DBConnectForm::DBConnectForm(QWidget *parent) :
    QWidget(parent),
    dbConnectFormUi(new Ui::DBConnectForm)
{
    dbConnectFormUi->setupUi(this);
    connect(this, SIGNAL(DatabaseIsconnected()), this, SLOT(OnDataBaseIsconnected()));
    connect(this, SIGNAL(DatabaseIsDisconnected()), this, SLOT(OnDatabaseIsDisconnected()));
    DBCONNECTION_UI_COMMPONENTS_SETUP

}

DBConnectForm::~DBConnectForm()
{
    delete dbConnectFormUi;
}

EUserRole DBConnectForm::GetCurrentUserRole()
{
    return eCurrentUserRole;
}

QString DBConnectForm::GetCurrentUserRoleName()
{
    return sCurrentUserRoleName;
}

void DBConnectForm::OnDataBaseIsconnected()
{
    DATABASE_IS_CONNECTED
    SERIALIZE_USER_ROLE
    bDatabaseIsconnected = true;
}

void DBConnectForm::OnDatabaseIsDisconnected()
{
    con->close();
    bDatabaseIsconnected = false;
    DATABASE_IS_NOT_CONNECTED

}

void DBConnectForm::on_connectToDBButton_clicked()
{
    try
    {
        CONNECT_TO_SQL_DRIVER(dbConnectFormUi->DBURITextBox->text().toStdString()
                             ,dbConnectFormUi->DBUserNameTextBox->text().toStdString()
                             ,dbConnectFormUi->DBPwdTextBox->text().toStdString())

        //con->setSchema(dbConnectFormUi->DBNameTextBox->text().toStdString());
    }
    catch(sql::SQLException e)
    {
#ifdef QT_DEBUG
        //TODO: add exception handel
       qDebug()<<e.what();
#endif
       return;
    }

    if(con->isValid()) emit DatabaseIsconnected();
}

void DBConnectForm::on_disconnectDBButton_clicked()
{
    emit DatabaseIsDisconnected();
}
