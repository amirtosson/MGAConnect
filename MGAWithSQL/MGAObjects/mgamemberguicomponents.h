#ifndef MGAMEMBERGUICOMPONENTS_H
#define MGAMEMBERGUICOMPONENTS_H

#include <QWidget>
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


class MGAMemberGUIComponents
{
public:
    MGAMemberGUIComponents();
    bool IntializeMemberGUIComponents(QWidget *widget);

private:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *EmailLabel;
    QLabel *workingByLabel;
    QLabel *joinAtLabel;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *EmailEdit;
    QLineEdit *workingByEdit;
    QLineEdit *joinAtEdit;
};

#endif // MGAMEMBERGUICOMPONENTS_H
