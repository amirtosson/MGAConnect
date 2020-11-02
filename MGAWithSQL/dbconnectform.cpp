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
    //if(nUserCounts>0) delete[] users;
}

EUserRole DBConnectForm::GetCurrentUserRole()
{
    return eCurrentUserRole;
}

QString DBConnectForm::GetCurrentUserRoleName()
{
    return sCurrentUserRoleName;
}

unsigned int DBConnectForm::GetUserNumber()
{
    return nUserCounts;
}

bool DBConnectForm::ShowUsersInQTalbe(QTableWidget *table)
{
    for(int i =0; i<nUserCounts; ++i)
    {
       table->insertRow(i);
       users[i].ShowInQTalbeRow(table,i);
    }
    return true;
}

void DBConnectForm::OnDataBaseIsconnected()
{
    DATABASE_IS_CONNECTED
    SERIALIZE_USER_ROLE
    bDatabaseIsconnected = true;
    if(eCurrentUserRole == eAdmin)
    {
        try
        {
            GET_MEMEBRS_COUNTS
            if(nUserCounts>0)
            {
                GET_MGA_MEMEBRS
                START_GETTING_DATA
                std::string str = res->getString(1).asStdString();
                MGAUser mgaUser;
                mgaUser.SetFirstName(str);
                str = res->getString(2).asStdString();
                mgaUser.SetLastName(str);
                str = res->getString(3).asStdString();
                mgaUser.SetEMail(str);
                str = res->getString(4).asStdString();
                mgaUser.SetUsnivesityName(str);
                users.push_back(mgaUser);
                END_GETTING_DATA
            }
            else
            {
                throw 0;
            }
        }
        catch(sql::SQLException e)
        {
            //TODO: add exception handel
           qDebug()<<e.what();
           return;
        }
    }
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
