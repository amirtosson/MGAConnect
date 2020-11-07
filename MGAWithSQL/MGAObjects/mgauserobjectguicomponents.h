#ifndef MGAUSEROBJECTGUICOMPONENTS_H
#define MGAUSEROBJECTGUICOMPONENTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

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
