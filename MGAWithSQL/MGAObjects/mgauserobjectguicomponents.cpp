#include "mgauserobjectguicomponents.h"

bool MGAUserObjectGUIComponents::IntializeUserGUIComponents(QWidget *widget)
{
    try
    {
        gridLayoutWidget = new QWidget(widget);
        gridLayout = new QGridLayout(gridLayoutWidget);
        nameLabel = new QLabel(gridLayoutWidget);
        hostLabel = new QLabel(gridLayoutWidget);
        hostEdit = new QLineEdit(gridLayoutWidget);
        pwdLabel = new QLabel(gridLayoutWidget);
        nameEdit = new QLineEdit(gridLayoutWidget);
        pwdEdit = new QLineEdit(gridLayoutWidget);
        roleComboBox = new QComboBox(gridLayoutWidget);
        roleLabel = new QLabel(gridLayoutWidget);

    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 10, 371, 211));
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
    gridLayout->addWidget(nameLabel, 0, 0, 1, 1);
    hostLabel->setObjectName(QString::fromUtf8("hostLabel"));
    gridLayout->addWidget(hostLabel, 1, 0, 1, 1);
    hostEdit->setObjectName(QString::fromUtf8("hostEdit"));
    gridLayout->addWidget(hostEdit, 1, 1, 1, 1);
    pwdLabel->setObjectName(QString::fromUtf8("pwdLabel"));
    gridLayout->addWidget(pwdLabel, 2, 0, 1, 1);
    nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
    gridLayout->addWidget(nameEdit, 0, 1, 1, 1);
    pwdEdit->setObjectName(QString::fromUtf8("pwdEdit"));
    gridLayout->addWidget(pwdEdit, 2, 1, 1, 1);
    roleComboBox->setObjectName(QString::fromUtf8("roleComboBox"));
    gridLayout->addWidget(roleComboBox, 3, 1, 1, 1);
    roleLabel->setObjectName(QString::fromUtf8("roleLabel"));
    gridLayout->addWidget(roleLabel, 3, 0, 1, 1);


    nameLabel->setText(TXT_NAME_LABEL);
    hostLabel->setText(TXT_HOST_LABEL);
    pwdLabel->setText(TXT_PWD_LABEL);
    roleLabel->setText(TXT_ROLE_LABEL);
    pwdEdit->setEchoMode(QLineEdit::Password);
    nameEdit->setPlaceholderText(TXT_NAME_PH);
    hostEdit->setPlaceholderText(TXT_HOST_PH);
    pwdEdit->setPlaceholderText(TXT_PWD_PH);

    QStringList styleList;
    styleList.append(TXT_ADMIN_ROLE);
    styleList.append(TXT_USER_ROLE);
    styleList.append(TXT_GUEST_ROLE);
    styleList.append(TXT_STUDENT_ROLE);
    roleComboBox->clear();
    roleComboBox->addItems(styleList);
    roleComboBox->setCurrentIndex(-1);
}

QString MGAUserObjectGUIComponents::GetUserName()
{
    return nameEdit->text();
}

QString MGAUserObjectGUIComponents::GetUserHost()
{
    return hostEdit->text();
}

QString MGAUserObjectGUIComponents::GetUserPWD()
{
    return pwdEdit->text();
}

QString MGAUserObjectGUIComponents::GetUserRole()
{
    switch (roleComboBox->currentIndex()) {
    case eAdmin:
        return ADMIN_ROLE;
        break;
    case eGuest:
        return GUEST_ROLE;
        break;
    case eStudent:
        return STUDENT_ROLE;
        break;
    case eUser:
        return USER_ROLE;
        break;
    default:
        break;
    }
    return 0;
}
