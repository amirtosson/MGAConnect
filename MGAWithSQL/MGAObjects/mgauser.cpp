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

void MGAUser::SetHost(std::__cxx11::string &host)
{
    sHost.SetFromSTDString(host);
}

void MGAUser::SetRole(std::__cxx11::string &role)
{
    sRole.SetFromSTDString(role);
}

void MGAUser::SetPWD(std::__cxx11::string &pwd)
{
    sPWD.SetFromSTDString(pwd);
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
