#ifndef MGAUSER_H
#define MGAUSER_H

#include <QString>
#include <QTableWidget>
#include <QDebug>

#include "mgastring.h"

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

    //getter
    QString GetName();
    QString GetHost();
    QString GetRole();
    QString GetPWD();
    int  CheckValidity();
    void Print();



private:
    MGAString sName;
    MGAString sHost;
    MGAString sRole;
    MGAString sPWD;

};

#endif // MGAUSER_H
