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

        errorText = new QLabel(widget);
        errorText->setObjectName(QString::fromUtf8("errorText"));

    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(20, 20, widget->width() -40 ,widget->height()*0.6));
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
    nameEdit->setClearButtonEnabled(true);
    hostEdit->setClearButtonEnabled(true);
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
    QWidget::setTabOrder(nameEdit, hostEdit);


    ResizeComponents(widget->width(),widget->height());
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
    okButton->setIcon(icon);
    okButton->setIconSize(QSize(20, 20));

    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
    cancelButton->setIcon(icon1);
    cancelButton->setIconSize(QSize(20, 20));

    widget->setWindowTitle(QCoreApplication::translate("AddNewObjectForm", "OBBA", nullptr));
    okButton->setText(QCoreApplication::translate("AddNewObjectForm", "OK", nullptr));
    cancelButton->setText(QCoreApplication::translate("AddNewObjectForm", "Cancel", nullptr));
    QMetaObject::connectSlotsByName(widget);
    return true;
}

void MGAUserObjectGUIComponents::ResizeComponents(int w, int h)
{
     gridLayoutWidget->resize(w-40,h*0.6);
     cancelButton->setGeometry(QRect(w*0.5, gridLayoutWidget->height() +20, w*0.2, h*0.1));
     okButton->setGeometry(QRect(w*0.5 + cancelButton->width() + 20, gridLayoutWidget->height() +20, w*0.2, h*0.1));
     errorText->setGeometry(QRect(20, gridLayoutWidget->height() +20, w*0.4, h*0.1));
     okButton->setIconSize(QSize(okButton->height()-10, okButton->height()-10));
     cancelButton->setIconSize(QSize(okButton->height()-10, okButton->height()-10));
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
