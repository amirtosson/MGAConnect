#ifndef ADDNEWOBJECTFORM_H
#define ADDNEWOBJECTFORM_H

#include <QDialog>
#include <QStyle>
#include <QMessageBox>

#include "mgamember.h"
#include "mgauser.h"
#include "mgaexperiment.h"
#include "mgaappointment.h"
#include "mganewobjectformview.h"
#include "MGAResizableWidgetAbstract.h"
#include "MGAObject.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>


class AddNewObjectForm : public QDialog, private MGANewObjectFormView, MGAResizableWidget
{
    Q_OBJECT

public:
    explicit AddNewObjectForm(QWidget *parent = 0, EListType eList = eUNKOWN);
    ~AddNewObjectForm();
    MGAUser* GetTheNewUser();
    MGAMember* GetTheNewMember();
    MGAExperiment* GetTheNewExp();
    QStringList* GetServerSetup();

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
    MGAAppointment *newAppoint;
    //TODO: setup object --- for now, as string list
    QStringList *newSetup;

    EListType eCurrentList = eUNKOWN;


private:
    bool AcceptNewUser();
    bool AcceptNewMember();

private:
    void UpdateSizes(int w, int h) override;
    void SetIconSize(int h) override;
};

#endif // ADDNEWOBJECTFORM_H
