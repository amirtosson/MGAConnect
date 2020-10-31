#ifndef DBCONNECTFORM_H
#define DBCONNECTFORM_H

#include <QWidget>
#include "dbconnectionsetups.h"
#include "sqlmacro.h"
namespace Ui {
class DBConnectForm;
}

class DBConnectForm : public QWidget
{
    Q_OBJECT

public:
    explicit DBConnectForm(QWidget *parent = 0);

    ~DBConnectForm();
    DECLAIR_SQL_REQUIRED_MEMBERS
signals:
    void DatabaseIsconnected();

private slots:
    void OnDataBaseIsconnected();

    void on_connectToDBButton_clicked();

    void on_disconnectDBButton_clicked();

private:
    Ui::DBConnectForm *dbConnectFormUi;
    bool bDatabaseIsconnected = false;
};

#endif // DBCONNECTFORM_H
