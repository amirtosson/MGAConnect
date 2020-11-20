#ifndef ADDNEWOBJECTFORM_H
#define ADDNEWOBJECTFORM_H

#include <QDialog>
#include <QStyle>
#include <QMessageBox>

#include "mgamember.h"
#include "mgauser.h"
#include "mgaexperiment.h"
#include "mgalistformtypesenum.h"
#include "mgauserobjectguicomponents.h"
#include "mgamemberguicomponents.h"


namespace Ui {
class AddNewObjectForm;
}

class AddNewObjectForm : public QDialog, public MGAUserObjectGUIComponents, public MGAMemberGUIComponents
{
    Q_OBJECT

public:
    explicit AddNewObjectForm(QWidget *parent = 0, EListType eList = eUNKOWN);
    ~AddNewObjectForm();
    MGAUser *GetTheNewUser();
    MGAMember *GetTheNewMember();
    MGAExperiment *GetTheNewExp();

signals:
    void NewObjectIsToBeAdded();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::AddNewObjectForm *ui;
    MGAUser *newUser;
    MGAMember *newMember;
    MGAExperiment *newExp;
    EListType eCurrentList = eUNKOWN;

private:
    bool AcceptNewUser();
    bool AcceptNewMember();
};

#endif // ADDNEWOBJECTFORM_H
