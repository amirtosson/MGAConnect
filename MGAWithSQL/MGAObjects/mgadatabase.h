#ifndef MGADATABASE_H
#define MGADATABASE_H

#include <QString>
#include <QTableWidget>
#include <QDebug>

#include "mgastring.h"

class MGADatabase
{
public:
    MGADatabase();
    bool ShowInQTalbeRow(QTableWidget *table, int row);
    void SetDatabaseName(std::string &database);
    void SetHost(std::string &host);

private:
    MGAString sDatabaseName;
    MGAString sHost;
};

#endif // MGADATABASE_H
