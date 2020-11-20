#include "mgamemberguicomponents.h"

MGAMemberGUIComponents::MGAMemberGUIComponents()
{

}

bool MGAMemberGUIComponents::IntializeMemberGUIComponents(QWidget *widget)
{
    try
    {
        gridLayoutWidget = new QWidget(widget);
        gridLayout = new QGridLayout(gridLayoutWidget);
        firstNameLabel = new QLabel(gridLayoutWidget);
        lastNameLabel = new QLabel(gridLayoutWidget);
        EmailLabel = new QLabel(gridLayoutWidget);
        workingByLabel = new QLabel(gridLayoutWidget);
        joinAtLabel = new QLabel(gridLayoutWidget);


        firstNameEdit = new QLineEdit(gridLayoutWidget);
        lastNameEdit = new QLineEdit(gridLayoutWidget);
        EmailEdit = new QLineEdit(gridLayoutWidget);
        workingByEdit = new QLineEdit(gridLayoutWidget);
        joinAtEdit = new QLineEdit(gridLayoutWidget);


    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }

    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 10, 370, 210));
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    firstNameLabel->setObjectName(QString::fromUtf8("firstnameLabel"));
    gridLayout->addWidget(firstNameLabel, 0, 0, 1, 1);
    lastNameLabel->setObjectName(QString::fromUtf8("lastnameLabel"));
    gridLayout->addWidget(lastNameLabel, 1, 0, 1, 1);
    EmailLabel->setObjectName(QString::fromUtf8("emailLabel"));
    gridLayout->addWidget(EmailLabel, 2, 0, 1, 1);
    workingByLabel->setObjectName(QString::fromUtf8("workinbyLabel"));
    gridLayout->addWidget(workingByLabel, 3, 0, 1, 1);
    joinAtLabel->setObjectName(QString::fromUtf8("joinatLabel"));
    gridLayout->addWidget(joinAtLabel, 4, 0, 1, 1);

    firstNameEdit->setObjectName(QString::fromUtf8("firstNameEdit"));
    gridLayout->addWidget(firstNameEdit, 0, 1, 1, 1);
    lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));
    gridLayout->addWidget(lastNameEdit, 1, 1, 1, 1);
    EmailEdit->setObjectName(QString::fromUtf8("EmailEdit"));
    gridLayout->addWidget(EmailEdit, 2, 1, 1, 1);
    workingByEdit->setObjectName(QString::fromUtf8("workingByEdit"));
    gridLayout->addWidget(workingByEdit, 3, 1, 1, 1);
    joinAtEdit->setObjectName(QString::fromUtf8("joinAtEdit"));
    gridLayout->addWidget(joinAtEdit, 4, 1, 1, 1);

    firstNameLabel->setText(TXT_FIRST_NAME_LABEL);
    lastNameLabel->setText(TXT_LAST_NAME_LABEL);
    EmailLabel->setText(TXT_EMAIL_LABEL);
    workingByLabel->setText(TXT_WORKIN_BY_LABEL);
    joinAtLabel->setText(TXT_JOIN_AT_LABEL);

    firstNameEdit->setPlaceholderText(TXT_FIRST_NAME_PH);
    lastNameEdit->setPlaceholderText(TXT_LAST_NAME_PH);
    EmailEdit->setPlaceholderText(TXT_EMAIL_PH);
    workingByEdit->setPlaceholderText(TXT_WORKIN_BY_PH);
    joinAtEdit->setPlaceholderText(TXT_JOIN_AT_PH);
    return true;
}
