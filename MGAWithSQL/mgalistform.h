#ifndef USERLISTFORM_H
#define USERLISTFORM_H

#include <QWidget>
#include <QTableWidget>

#include "mgalistformresources.h"
#include "mgalistformsetups.h"
#include "mgalistformtypesenum.h"

#define MGA_LIST_TYPY eUsersList

namespace Ui {
class MGAListForm;
}

class MGAListForm : public QWidget
{
    Q_OBJECT

public:
    explicit MGAListForm(QWidget *parent = 0, EListType eList = eUsersList);
    QTableWidget *GetUITable();
    ~MGAListForm();

private slots:
    void on_userListWidget_cellPressed(int row, int column);

private:
    Ui::MGAListForm *userListFormUi;
};

#endif // USERLISTFORM_H
