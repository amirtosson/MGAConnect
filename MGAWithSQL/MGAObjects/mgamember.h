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
    void SetUsnivesityName(std::string &university);
    void SetEMail(std::__cxx11::string &email);
    void Print();



private:
    MGAString sFirstName;
    MGAString sLastName;
    MGAString sUniversityName;
    MGAString sEMail;

};

#endif // MGAMEMBER_H
