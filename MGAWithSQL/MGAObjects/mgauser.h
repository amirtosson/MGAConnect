#ifndef MGAUSERLIB_H
#define MGAUSERLIB_H

#include <QString>
#include <QTableWidget>
#include "mgastring.h"
#include <QDebug>

class MGAUser
{

public:
    MGAUser();
    QTableWidgetItem item[4];

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

#endif // MGAUSERLIB_H
