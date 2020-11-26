#ifndef MGAUSEROBJECTGUICOMPONENTS_H
#define MGAUSEROBJECTGUICOMPONENTS_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "addnewobjectformresources.h"
#include "mgauserrolesenum.h"

class MGAUserObjectGUIComponents
{

public:
    bool IntializeUserGUIComponents(QWidget *widget);
    void ResizeComponents(int w, int h);
    QString GetUserName();
    QString GetUserHost();
    QString GetUserPWD();
    QString GetUserRole();


public slots:
    virtual void on_OkButton_clicked() = 0;
    virtual void on_CancelButton_clicked() = 0;

protected:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *hostLabel;
    QLineEdit *hostEdit;
    QLabel *pwdLabel;
    QLineEdit *nameEdit;
    QLineEdit *pwdEdit;
    QComboBox *roleComboBox;
    QLabel *roleLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *errorText;
};



#endif // MGAUSEROBJECTGUICOMPONENTS_H
