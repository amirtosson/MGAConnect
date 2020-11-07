#ifndef ADDNEWOBJECTFORM_H
#define ADDNEWOBJECTFORM_H

#include <QDialog>
#include <QStyle>
#include <QMessageBox>


#include "mgamember.h"
#include "mgauser.h"
#include "mgalistformtypesenum.h"
#include "mgauserobjectguicomponents.h"


namespace Ui {
class AddNewObjectForm;
}

class AddNewObjectForm : public QDialog, public MGAUserObjectGUIComponents
{
    Q_OBJECT

public:
    explicit AddNewObjectForm(QWidget *parent = 0, EListType eList = eUNKOWN);
    ~AddNewObjectForm();
    MGAUser *GetTheNewUser();

signals:
    void NewUserIsToBeAdded();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();


private:
    Ui::AddNewObjectForm *ui;
    MGAUser *newUser;
    MGAMember *newMember;
    EListType eCurrentList = eUNKOWN;
};

#endif // ADDNEWOBJECTFORM_H
