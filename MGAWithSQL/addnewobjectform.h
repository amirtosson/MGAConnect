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
#include "MGAResizableWidgetAbstract.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>


class AddNewObjectForm : public QDialog, private MGAUserObjectGUIComponents, public MGAMemberGUIComponents, MGAResizableWidget
{
    Q_OBJECT

public:
     void setupUi(QDialog *AddNewObjectForm);
    explicit AddNewObjectForm(QWidget *parent = 0, EListType eList = eUNKOWN);
    ~AddNewObjectForm();
    MGAUser *GetTheNewUser();
    MGAMember *GetTheNewMember();
    MGAExperiment *GetTheNewExp();

signals:
    void NewObjectIsToBeAdded();

public slots:
    void OnSizeChange(int w, int h) override;

private slots:
    void on_OkButton_clicked() override;
    void on_CancelButton_clicked() override;

private:
    MGAUser *newUser;
    MGAMember *newMember;
    MGAExperiment *newExp;
    EListType eCurrentList = eUNKOWN;

private:
    bool AcceptNewUser();
    bool AcceptNewMember();

private:
    void UpdateSizes(int w, int h) override;
    void SetIconSize(int h) override;
};

#endif // ADDNEWOBJECTFORM_H
