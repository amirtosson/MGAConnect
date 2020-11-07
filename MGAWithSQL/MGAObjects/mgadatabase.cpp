#include "mgadatabase.h"

MGADatabase::MGADatabase()
{

}

bool MGADatabase::ShowInQTalbeRow(QTableWidget *table, int row)
{
    QTableWidgetItem *databaseNameItem = new QTableWidgetItem();
    *databaseNameItem =  sDatabaseName.GetAsQTableWidgitItem();
    table->setItem(row,0, databaseNameItem);
    QTableWidgetItem *hostItem = new QTableWidgetItem();;
    *hostItem =  sHost.GetAsQTableWidgitItem();
    table->setItem(row,1, hostItem);
    return true;
}

void MGADatabase::SetDatabaseName(std::string &database)
{
    sDatabaseName.SetFromSTDString(database);
}

void MGADatabase::SetHost(std::string &host)
{
    sHost.SetFromSTDString(host);
}
