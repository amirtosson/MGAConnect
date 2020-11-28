#ifndef MGAUSER_H
#define MGAUSER_H

#include <QString>
#include <QTableWidget>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <vector>

#include "mgastring.h"

//Attributes definations

#define MGA_JSON_USER_NAME         "user"
#define MGA_JSON_HOST_NAME         "host"
#define MGA_JSON_ROLE_NAME         "role"


class MGAUser
{

public:
    MGAUser();

    bool ShowInQTalbeRow(QTableWidget *table, int row);
    //Setter
    void SetName(std::string &name);
    void SetHost(std::string &host);
    void SetRole(std::string &role);
    void SetPWD(std::string &pwd);
    bool SetFromQStringList(QStringList &fields);

    //getter
    QString GetName();
    QString GetHost();
    QString GetRole();
    QString GetPWD();

    int  CheckValidity();
    void Print();

    bool SerializeFromJSON(QJsonDocument *jsonResponse);

private:
    MGAString sName;
    MGAString sHost;
    MGAString sRole;
    MGAString sPWD;

};

typedef std::vector<MGAUser> MGAUserList;

#endif // MGAUSER_H
