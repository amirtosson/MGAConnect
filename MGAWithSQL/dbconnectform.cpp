#include "dbconnectform.h"
#include "ui_dbconnectform.h"


DBConnectForm::DBConnectForm(QWidget *parent) :
    QWidget(parent),
    dbConnectFormUi(new Ui::DBConnectForm)
{
    dbConnectFormUi->setupUi(this);
    connect(this, SIGNAL(DatabaseIsconnected()), this, SLOT(OnDataBaseIsconnected()));
    DBCONNECTION_UI_COMMPONENTS_SETUP

}

DBConnectForm::~DBConnectForm()
{
    delete dbConnectFormUi;
    delete con;
}

void DBConnectForm::OnDataBaseIsconnected()
{
    DATABASE_IS_CONNECTED
}

void DBConnectForm::on_connectToDBButton_clicked()
{
    try
    {
        driver = get_driver_instance();
        con = driver->connect( dbConnectFormUi->DBURITextBox->text().toStdString(), dbConnectFormUi->DBUserNameTextBox->text().toStdString(), dbConnectFormUi->DBPwdTextBox->text().toStdString());

        //con->setSchema(dbConnectFormUi->DBNameTextBox->text().toStdString());
    }
    catch(sql::SQLException e)
    {
#ifdef QT_DEBUG
       qDebug()<<e.what();
#endif
       return;
    }
    if(con->isValid())
    {
        bDatabaseIsconnected = true;
        emit DatabaseIsconnected();
    }
}

void DBConnectForm::on_disconnectDBButton_clicked()
{
    con->close();
    DATABASE_IS_NOT_CONNECTED
}
