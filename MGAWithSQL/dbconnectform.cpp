#include "dbconnectform.h"
#include "ui_dbconnectform.h"


DBConnectForm::DBConnectForm(QWidget *parent) :
    QWidget(parent),
    dbConnectFormUi(new Ui::DBConnectForm)
{
    dbConnectFormUi->setupUi(this);
    connect(this, SIGNAL(DatabaseIsconnected()), this, SLOT(OnDataBaseIsconnected()));
    connect(this, SIGNAL(DatabaseIsDisconnected()), this, SLOT(OnDatabaseIsDisconnected()));
    socket = new QTcpSocket();
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
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

unsigned int DBConnectForm::GetUserNumber()
{
    return nMemberCount;
}

bool DBConnectForm::ShowMembersInQTalbe(QTableWidget *table)
{
    for(int i =0; i < nMemberCount; ++i)
    {
       table->insertRow(i);
       mgaMembersList[i].ShowInQTalbeRow(table,i);
    }
    return true;
}

bool DBConnectForm::ShowUsersInQTalbe(QTableWidget *table)
{
    for(int i =0; i<nUserCount; ++i)
    {
       table->insertRow(i);
       mgaUsersList[i].ShowInQTalbeRow(table,i);
    }
    return true;
}

bool DBConnectForm::AddNewMGAUsers(MGAUser *newUser)
{
//    if (con->isValid())
//    {
//        ADD_NEW_USER(newUser->GetName().toStdString(),newUser->GetHost().toStdString(),newUser->GetPWD().toStdString(),newUser->GetRole().toStdString())
//        qDebug()<<"valid";
//    }
//    else
//    {
//        qDebug()<<"Invalid";
//    }
    return true;

}

void DBConnectForm::CleanLists()
{
   mgaUsersList.clear();
   mgaMembersList.clear();
}

void DBConnectForm::OnDataBaseIsconnected()
{
    //TODO: cleaning only if new data is added
    CleanLists();
    DATABASE_IS_CONNECTED
    SERIALIZE_USER_ROLE
//    bDatabaseIsconnected = true;
//    if(eCurrentUserRole == eAdmin)
//    {
//        try
//       {
//            GET_USERS
//            GET_USERS_COUNTS
//            if(nUserCount>0)
//            {
//                GET_USERS
//                START_GETTING_DATA
//                MGAUser mgaUser;
//                std::string str = res->getString(1).asStdString();
//                mgaUser.SetName(str);
//                str = res->getString(2).asStdString();
//                mgaUser.SetHost(str);
//                str = res->getString(3).asStdString();
//                mgaUser.SetRole(str);
//                mgaUsersList.push_back(mgaUser);
//                END_GETTING_DATA
//            }
//            else
//            {
//                throw 404;
//            }
//        }
//        catch(sql::SQLException e)
//        {
//            //TODO: add exception handel
//           qDebug()<<e.what();
//           return;
//        }

//        try
//        {
//            GET_MEMEBRS_COUNTS
//            if(nMemberCount>0)
//            {
//                GET_MGA_MEMEBRS
//                START_GETTING_DATA
//                std::string str = res->getString(1).asStdString();
//                MGAMember mgaMember;
//                mgaMember.SetFirstName(str);
//                str = res->getString(2).asStdString();
//                mgaMember.SetLastName(str);
//                str = res->getString(3).asStdString();
//                mgaMember.SetEMail(str);
//                str = res->getString(4).asStdString();
//                mgaMember.SetUsnivesityName(str);
//                mgaMembersList.push_back(mgaMember);
//                END_GETTING_DATA
//            }
//            else
//            {
//                throw 404;
//            }
//        }
//        catch(sql::SQLException e)
//        {
//            //TODO: add exception handel
//           qDebug()<<e.what();
//           return;
//        }
//        catch(int i)
//        {
//            //TODO: add exception handel
//           if(i == 404 ) qDebug()<<"No users found";
//           return;
//        }
//    }
}

void DBConnectForm::OnDatabaseIsDisconnected()
{
    bDatabaseIsconnected = false;
    DATABASE_IS_NOT_CONNECTED
}

void DBConnectForm::on_connectToDBButton_clicked()
{

    QHostAddress addressIP ;
    addressIP.setAddress("192.168.178.28");
    addressIP.toIPv4Address();
    if (!socket->isValid()) socket->connectToHost(addressIP, 9999);
    socket->waitForConnected(5000);
    MGAServerClientMSG msg(EMSGType::eConnectToDB);
    //msg.InsertInMSGBody(JSON_ATT_HOST,dbConnectFormUi->DBURITextBox->text());
    //msg.InsertInMSGBody(JSON_ATT_USER,dbConnectFormUi->DBUserNameTextBox->text());
    //msg.InsertInMSGBody(JSON_ATT_PWD,dbConnectFormUi->DBPwdTextBox->text());
    msg.InsertInMSGBody(JSON_ATT_HOST,"localhost");
    msg.InsertInMSGBody(JSON_ATT_USER,"tosson");
    msg.InsertInMSGBody(JSON_ATT_PWD,"rock255");
    socket->write(msg.GetMSGAsByteArray());
    socket->waitForBytesWritten(5000);
    socket->flush();
}

void DBConnectForm::on_disconnectDBButton_clicked()
{
    if (!socket->isValid()) socket->connectToHost("localhost", 9999);
    MGAServerClientMSG msg(EMSGType::eDisconnectDB);
    socket->write(msg.GetMSGAsByteArray());
    socket->flush();
}

void DBConnectForm::ServerMSGHandling(MGAServerClientMSG *msg)
{
    QString host, user, password;
    if(msg->GetMSGType() == EMSGType::eConnectToDB)
    {
        if (msg->GetValue(JSON_ATT_CONNECTED, 0)=="true")
        {
            sCurrentUserRoleName = msg->GetValue(JSON_ATT_LOGIN_USER_ROLE,1);
            emit DatabaseIsconnected();
        }
    }
    else
    if (msg->GetMSGType() == EMSGType::eDisconnectDB)
    {
        if (msg->GetValue(JSON_ATT_DISCONNECTED, 0)=="true")
        {
            emit DatabaseIsDisconnected();
        }
    }
}

void DBConnectForm::connected()
{

}

void DBConnectForm::disconnected()
{
    qDebug() << "Disconnected!";
}

void DBConnectForm::bytesWritten(qint64 bytes)
{

}

void DBConnectForm::readyRead()
{
    MGAServerClientMSG msg;
    QByteArray res = socket->readAll();
    msg.GetFromResponse(res);
    ServerMSGHandling(&msg);
}
