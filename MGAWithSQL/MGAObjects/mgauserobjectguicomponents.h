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
    QString GetUserName();
    QString GetUserHost();
    QString GetUserPWD();
    QString GetUserRole();

private:
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
};



#endif // MGAUSEROBJECTGUICOMPONENTS_H
