#ifndef MGAUSERLIB_H
#define MGAUSERLIB_H

#include <QString>
#include <QTableWidget>

class MGAUser
{

public:
    MGAUser();
    QTableWidgetItem item[4];

    bool ShowInQTalbeRow(QTableWidget *table, int colNum, int row);
};

#endif // MGAUSERLIB_H
