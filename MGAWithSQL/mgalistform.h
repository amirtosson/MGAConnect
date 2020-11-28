#ifndef USERLISTFORM_H
#define USERLISTFORM_H

#include <QWidget>
#include <QTableWidget>

#include "addnewobjectform.h"
#include "mgalistformresources.h"
#include "mgalistformsetups.h"
#include "mgalistformtypesenum.h"
#include "MGAResizableWidgetAbstract.h"

#define MGA_LIST_TYPY eMemberList

namespace Ui {
class MGAListForm;
}

class MGAListForm : public QWidget, MGAResizableWidget
{
    Q_OBJECT

public:
    explicit MGAListForm(QWidget *parent = 0, EListType eList = eUNKOWN);
    QTableWidget *GetUITable();
    ~MGAListForm();
    MGAUser *GetTheNewUser();

private slots:
    void on_userListWidget_cellPressed(int row, int column);

    void on_editUserButton_clicked();

    void on_addUserButton_clicked();

    void NewObjectIsReady();

    void on_searchTextBox_textChanged(const QString &arg1);

public slots:
    virtual void OnSizeChange(int w, int h) override;

signals:
    void NewUserIsReady();
    void NewMemberIsReady();
    void NewExpIsReady();

    void NewObjectIsReadyToAdd(EListType eList);
    void SizeChanged(int w, int h);


private:
    void SelectionIsChanged(const int id);
    void UpdateTableColumsWidth(int w);

private:
    Ui::MGAListForm *userListFormUi;
    QIcon btnIcon;
    unsigned int nCurrentSelecttonID = -1;
    EListType eCurrentListType = eUNKOWN;
    AddNewObjectForm *addNewObject;
    bool hasAddNewObjectForm = false;

private:
    void UpdateSizes(int w, int h) override;
    void SetIconSize(int h) override;
};

#endif // USERLISTFORM_H
