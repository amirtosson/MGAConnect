#ifndef MGAMEMBER_H
#define MGAMEMBER_H

#include <QString>
#include <QTableWidget>
#include <QDebug>

#include "mgastring.h"

class MGAMember
{

public:
    MGAMember();

    bool ShowInQTalbeRow(QTableWidget *table, int row);
    //Setter
    void SetFirstName(std::string &firstname);
    void SetLastName(std::string &lastname);
    void SetsWorkingBy(std::string &workingby);
    void SetID(unsigned int &id);
    void SetEMail(std::string &email);
    void SetJoinAt(std::string &joinat);

    void Print();



private:
    unsigned int memberID;
    MGAString sFirstName;
    MGAString sLastName;
    MGAString sWorkingBy;
    MGAString sEMail;
    //TODO: implement data class
    MGAString sJoinAt;

};

#endif // MGAMEMBER_H
