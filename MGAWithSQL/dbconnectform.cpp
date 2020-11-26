#include "dbconnectform.h"
#include "ui_dbconnectform.h"



DBConnectForm::DBConnectForm(QWidget *parent) :
    QWidget(parent),
    dbConnectFormUi(new Ui::DBConnectForm)
{
    dbConnectFormUi->setupUi(this);
    connect(this, SIGNAL(DatabaseIsconnected()), this, SLOT(OnDataBaseIsconnected()));
    connect(this, SIGNAL(DatabaseIsDisconnected()), this, SLOT(OnDatabaseIsDisconnected()));
    connect(this, SIGNAL(UsersListIsReady()), this, SLOT(OnUsersListIsReady()));
    connect(this, SIGNAL(MembersListIsReady()), this, SLOT(OnMembersListIsReady()));

    socket = new QTcpSocket();
    QHostAddress addressIP ;
    addressIP.setAddress("192.168.178.28");
    addressIP.toIPv4Address();
    socket->disconnectFromHost();
    socket->connectToHost("Tosson-pnCCD", 9999);
    socket->waitForConnected(5000);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    DBCONNECTION_UI_COMMPONENTS_SETUP
}

DBConnectForm::~DBConnectForm()
{
    delete dbConnectFormUi;
}

void DBConnectForm::ServerMSGHandling(MGAServerClientMSG *msg)
{
    QString host, user, password;
    if(msg->GetMSGType() == EMSGType::eConnectToDB)
    {

        if (msg->GetValue(JSON_ATT_CONNECTED, 0)==TRUE)
        {
            sCurrentUserRoleName = msg->GetValue(JSON_ATT_LOGIN_USER_ROLE,1);
            SERIALIZE_USER_ROLE
            emit DatabaseIsconnected();
        }
    }
    else
    if (msg->GetMSGType() == EMSGType::eDisconnectDB)
    {
        if (msg->GetValue(JSON_ATT_DISCONNECTED, 0)==TRUE)
        {
            emit DatabaseIsDisconnected();
        }
    }
    else
    if (msg->GetMSGType() == EMSGType::eGetUsersList)
    {
        SerializeUsersListFromMSG(msg);
        emit UsersListIsReady();
    }
    else
    if (msg->GetMSGType() == EMSGType::eAddNewUser)
    {
        if (msg->GetValue(JSON_ATT_ADDED, 0)==TRUE)
        {
            CleanLists();
            ShowUsersInQTalbe(mainTable);
        }
    }
    else
    if (msg->GetMSGType() == EMSGType::eEditUser)
    {
        if (msg->GetValue(JSON_ATT_ADDED, 0)==TRUE)
        {

        }
    }
    else
    if (msg->GetMSGType() == EMSGType::eGetMembersList)
    {
        SerializeMemberssListFromMSG(msg);
        emit MembersListIsReady();
    }
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
    mainTable = table;
    SendServerGetMemberListMSG();
    return true;
}

bool DBConnectForm::ShowUsersInQTalbe(QTableWidget *table)
{
    mainTable = table;
    SendServerGetUserListMSG();
    return true;
}

bool DBConnectForm::AddNewMGAUsers(MGAUser *newUser)
{
    MGAServerClientMSG msg(EMSGType::eAddNewUser);
    msg.InsertInMSGBody(JSON_ATT_HOST,newUser->GetHost());
    msg.InsertInMSGBody(JSON_ATT_USER,newUser->GetName());
    msg.InsertInMSGBody(JSON_ATT_PWD,newUser->GetPWD());
    msg.InsertInMSGBody(JSON_ATT_LOGIN_USER_ROLE,newUser->GetRole());
    socket->write(msg.GetMSGAsByteArray());
    socket->waitForBytesWritten(1000);
    socket->flush();
    return true;
}

bool DBConnectForm::SendServerGetUserListMSG()
{
    MGAServerClientMSG msg(EMSGType::eGetUsersList);
    socket->write(msg.GetMSGAsByteArray());
    socket->flush();
    return true;
}

bool DBConnectForm::SendServerGetMemberListMSG()
{
    MGAServerClientMSG msg(EMSGType::eGetMembersList);
    socket->write(msg.GetMSGAsByteArray());
    socket->flush();
    return true;
}

void DBConnectForm::UpdateSizes(int w, int h)
{
    this->setGeometry(0,0, w , h);
    dbConnectFormUi->dbFormLabel->resize(w  - 20, 50);
    dbConnectFormUi->enteriesWidget->resize(DB_FORM_ENTRIES_WIDTH_RATIO*w-DB_FORM_60PX_MARGIN, DB_FORM_ENTRIES_HEIGHT_RATIO*h);
    dbConnectFormUi->databaseIconWidget->setGeometry(30,0.71*h,DB_FORM_DB_ICON_WIDTH_RATIO*w,DB_FORM_DB_ICON_HEIGHT_RATIO*h);
    QRect buttonsRec(dbConnectFormUi->databaseIconWidget->width() + DB_FORM_60PX_MARGIN+0.01*w, dbConnectFormUi->databaseIconWidget->y(), DB_FORM_BUTTON_WIDTH_RATIO*w, DB_FORM_BUTTON_HEIGHT_RATIO*h);
    dbConnectFormUi->buttonsWidget->setGeometry(buttonsRec);
}

void DBConnectForm::SetIconSize(int h)
{
    dbConnectFormUi->disconnectDBButton->setIconSize(QSize(h, h));
    dbConnectFormUi->connectToDBButton->setIconSize(QSize(h, h));
}

void DBConnectForm::CleanLists()
{
   mgaUsersList.clear();
   mgaMembersList.clear();
}

void DBConnectForm::OnSizeChange(int w, int h)
{
    w = MAIN_WIDGET_WIDTH_RATIO*w;
    h = MAIN_WIDGET_HEIGHT_RATIO*h;
    UpdateSizes(w,h);
}

void DBConnectForm::OnDataBaseIsconnected()
{
    //TODO: cleaning only if new data is added
    CleanLists();
    DATABASE_IS_CONNECTED
    bDatabaseIsconnected = true;
}

void DBConnectForm::OnDatabaseIsDisconnected()
{
    bDatabaseIsconnected = false;
    DATABASE_IS_NOT_CONNECTED
}

void DBConnectForm::OnUsersListIsReady()
{
    int row = 0;
    while (mainTable->rowCount() != nUserCount)
    {
        mainTable->insertRow(row);
        row++;
    }

    for(unsigned int i =0; i<nUserCount; ++i)
    {
       mgaUsersList[i].ShowInQTalbeRow(mainTable,i);
    }
}

void DBConnectForm::OnMembersListIsReady()
{
    int row = 0;
    while (mainTable->rowCount() != nMemberCount)
    {
        mainTable->insertRow(row);
        row++;
    }

    for(unsigned int i =0; i<nMemberCount; ++i)
    {
       mgaMembersList[i].ShowInQTalbeRow(mainTable,i);
    }
}

void DBConnectForm::on_connectToDBButton_clicked()
{
    MGAServerClientMSG msg(EMSGType::eConnectToDB);
    //msg.InsertInMSGBody(JSON_ATT_HOST,dbConnectFormUi->DBURITextBox->text());
    //msg.InsertInMSGBody(JSON_ATT_USER,dbConnectFormUi->DBUserNameTextBox->text());
    //msg.InsertInMSGBody(JSON_ATT_PWD,dbConnectFormUi->DBPwdTextBox->text());
    msg.InsertInMSGBody(JSON_ATT_HOST,"localhost");
    msg.InsertInMSGBody(JSON_ATT_USER,"tosson");
    msg.InsertInMSGBody(JSON_ATT_PWD,"rock255");
    socket->write(msg.GetMSGAsByteArray());
    socket->waitForBytesWritten(1000);
    socket->flush();
}

void DBConnectForm::on_disconnectDBButton_clicked()
{
    MGAServerClientMSG msg(EMSGType::eDisconnectDB);
    socket->write(msg.GetMSGAsByteArray());
    socket->flush();
}


void DBConnectForm::SerializeUsersListFromMSG(MGAServerClientMSG *msg)
{
    CleanLists();
    for (unsigned int i=0; i<msg->GetBodyLength(); ++i )
    {
        QString user;
        user = msg->GetValue(JSON_ATT_USER,i);
        std::string str = user.toStdString();
        size_t pos = 0;
        std::string delimiter = MGA_DELIMITER;
        pos = str.find(delimiter);
        std::string userName = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
        std::string userHost = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        MGAUser mgaUser;
        mgaUser.SetName(userName);
        mgaUser.SetHost(userHost);
        mgaUser.SetRole(str);
        mgaUsersList.push_back(mgaUser);

    }
    nUserCount = mgaUsersList.size();
}

void DBConnectForm::SerializeMemberssListFromMSG(MGAServerClientMSG *msg)
{
    CleanLists();
    for (unsigned int i=0; i<msg->GetBodyLength(); ++i )
    {
        QString user;
        user = msg->GetValue(JSON_ATT_MEMBER,i);
        std::string str = user.toStdString();
        size_t pos = 0;
        std::string delimiter = MGA_DELIMITER;
        pos = str.find(delimiter);
        unsigned int  memberID = 2;
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
        std::string firstname = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
        std::string lastname = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
        std::string joinat = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
        std::string workingby = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
        std::string email = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        MGAMember mgaMember;
        mgaMember.SetEMail(email);
        mgaMember.SetFirstName(firstname);
        mgaMember.SetID(memberID);
        mgaMember.SetJoinAt(joinat);
        mgaMember.SetsWorkingBy(workingby);
        mgaMember.SetLastName(lastname);
        mgaMembersList.push_back(mgaMember);
    }
    nMemberCount = mgaMembersList.size();
}

void DBConnectForm::connected()
{
    qDebug() << "connected!";
}

void DBConnectForm::disconnected()
{
    qDebug() << "Disconnected!";
}

void DBConnectForm::bytesWritten(qint64 bytes)
{
    qDebug() << "Writting";
}

void DBConnectForm::readyRead()
{
    MGAServerClientMSG msg;
    QByteArray res = socket->readAll();
    msg.GetFromResponse(res);
    ServerMSGHandling(&msg);
}

void DBConnectForm::on_updateDetailsButton_clicked()
{
    QSettings qSetting;
    if (!qSetting.contains(USER_SETTING_GROUP))
    {
        qSetting.beginGroup(USER_SETTING_GROUP);

    }
    qSetting.setValue(USER_SETTING_USER_NAME, dbConnectFormUi->DBUserNameTextBox->text());
    qSetting.setValue(USER_SETTING_DB_URI, dbConnectFormUi->DBURITextBox->text());

}

void DBConnectForm::on_loadDetailsButton_clicked()
{
    QSettings settings;
    dbConnectFormUi->DBUserNameTextBox->setText(settings.value(USER_SETTING_USER_NAME_GETTER).toString());
    dbConnectFormUi->DBURITextBox->setText(settings.value(USER_SETTING_DB_URI_GETTER).toString());

}
