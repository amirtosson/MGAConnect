#include "mgauser.h"

MGAUser::MGAUser()
{

}

bool MGAUser::ShowInQTalbeRow(QTableWidget *table, int row)
{
    QTableWidgetItem *nameItem = new QTableWidgetItem();
    *nameItem =  sName.GetAsQTableWidgitItem();
    table->setItem(row,0, nameItem);
    QTableWidgetItem *hostItem = new QTableWidgetItem();;
    *hostItem =  sHost.GetAsQTableWidgitItem();
    table->setItem(row,1, hostItem);
    QTableWidgetItem *roleItem = new QTableWidgetItem();;
    *roleItem =  sRole.GetAsQTableWidgitItem();
    table->setItem(row,2, roleItem);
    return true;
}

void MGAUser::SetName(std::string &name)
{
    sName.SetFromSTDString(name);
}

void MGAUser::SetHost(std::string &host)
{
    sHost.SetFromSTDString(host);
}

void MGAUser::SetRole(std::string &role)
{
    sRole.SetFromSTDString(role);
}

void MGAUser::SetPWD(std::string &pwd)
{
    sPWD.SetFromSTDString(pwd);
}

bool MGAUser::SetFromQStringList(QStringList &fields)
{
    if (fields.size() != 3) return false;
    QString str = fields.at(0);
    sName.SetFromQString(&str);
    str = fields.at(1);
    sHost.SetFromQString(&str);
    str = fields.at(2);
    sPWD.SetFromQString(&str);
    return true;
}

QString MGAUser::GetName()
{
    return sName.GetAsQString();
}

QString MGAUser::GetHost()
{
    return sHost.GetAsQString();
}

QString MGAUser::GetRole()
{
    return sRole.GetAsQString();
}

QString MGAUser::GetPWD()
{
    return sPWD.GetAsQString();
}

int MGAUser::CheckValidity()
{
    //returns: 1 valid, -1 invalid name, -2 invalid role, -3 invalid host, -4 invalid pwd
    if (!sName.IsValidUserName()) return -1;
    //if (!sPWD.IsValidPwd()) return -4;
    //TODO: add host and role checker

    return 1;

}

bool MGAUser::SerializeFromJSON(QJsonDocument *jsonResponse)
{
    QJsonArray jsonArray = jsonResponse->array();
    if(!jsonArray.isEmpty())
    {
        int nUserCount;
        for(nUserCount=0; nUserCount<jsonArray.size(); ++nUserCount)
        {
            QJsonObject jsonObject = jsonArray[nUserCount].toObject();
            QString host= jsonObject.value(MGA_JSON_HOST_NAME).toString();
            QString user= jsonObject.value(MGA_JSON_USER_NAME).toString();
            QString role= jsonObject.value(MGA_JSON_ROLE_NAME).toString();
            sHost.SetFromQString(&host);
            sName.SetFromQString(&user);
            sRole.SetFromQString(&role);
            qDebug()<<"name: " <<sHost.GetAsQString()<<endl;
            qDebug()<<"role: " <<sRole.GetAsQString()<<endl;
            qDebug()<<"host: " <<sHost.GetAsQString()<<endl;
        }
    }


    if(sName.IsEmpty()
       ||sRole.IsEmpty())
    {
        return false;
    }
    return  true;
}
