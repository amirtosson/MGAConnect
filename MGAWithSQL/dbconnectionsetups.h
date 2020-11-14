#ifndef MAINWINDOWDBCONNECTIONSETUPS_H
#define MAINWINDOWDBCONNECTIONSETUPS_H
#include "dbconnectformresources.h"

#define DBCONNECTION_UI_COMMPONENTS_SETUP\
        dbConnectFormUi->bdNameLabel->setText(TXT_DB_NAME_LABEL);\
        dbConnectFormUi->bdUserNameLabel->setText(TXT_DB_USER_NAME_LABEL);\
        dbConnectFormUi->DBNameTextBox->setPlaceholderText(TXT_DB_NAME_PH);\
        dbConnectFormUi->bdURILabel->setText(TXT_DB_URI_LABEL);\
        dbConnectFormUi->DBURITextBox->setPlaceholderText(TXT_DB_URI_PH);\
        dbConnectFormUi->DBUserNameTextBox->setPlaceholderText(TXT_DB_USER_NAME_PH);\
        dbConnectFormUi->bdPwdLabel->setText(TXT_DB_PASSWORD_LABEL);\
        dbConnectFormUi->DBPwdTextBox->setPlaceholderText(TXT_DB_PASSWORD_PH);\
        dbConnectFormUi->DBPwdTextBox->setEchoMode(QLineEdit::Password);\
        dbConnectFormUi->dbFormLabel->setText(TXT_FORM_TITLE_LABEL);\
        dbConnectFormUi->dbFormLabel->setStyleSheet(STYLE_FONT_24PIX_BOLD);\
        dbConnectFormUi->dbFormLabel->setAlignment(Qt::AlignCenter);\
        DATABASE_IS_NOT_CONNECTED\
        ADD_DB_BUTTON_SETUP


#define DATABASE_IS_CONNECTED\
        dbConnectFormUi->databaseIconWidget->setStyleSheet(IMG_CONNECTED);\
        dbConnectFormUi->connectToDBButton->setEnabled(false);\
        dbConnectFormUi->disconnectDBButton->setEnabled(true);

#define DATABASE_IS_NOT_CONNECTED\
        dbConnectFormUi->databaseIconWidget->setStyleSheet(IMG_NOT_CONNECTED);\
        dbConnectFormUi->connectToDBButton->setEnabled(true);\
        dbConnectFormUi->disconnectDBButton->setEnabled(false);


#define ADD_DB_BUTTON_SETUP\
        dbConnectFormUi->connectToDBButton->setText(TXT_ADD_DB_BTN_LABEL);\
        dbConnectFormUi->disconnectDBButton->setText(TXT_DISCONNECT_DB_BTN_LABEL);\
        QPixmap pixmap(IMG_CONNECT);\
        QIcon ButtonIcon(pixmap);\
        dbConnectFormUi->connectToDBButton->setIcon(ButtonIcon);\
        dbConnectFormUi->connectToDBButton->setIconSize(QSize(20, 20));

#define SERIALIZE_USER_ROLE\
    if(sCurrentUserRoleName == ADMIN_ROLE) eCurrentUserRole = eAdmin;\
    else if (sCurrentUserRoleName == USER_ROLE) eCurrentUserRole = eUser;\
    else if (sCurrentUserRoleName == GUEST_ROLE) eCurrentUserRole = eGuest;\
    else if (sCurrentUserRoleName == STUDENT_ROLE) eCurrentUserRole = eStudent;\
    else eCurrentUserRole = eUNKNOWN;

#endif // MAINWINDOWDBCONNECTIONSETUPS_H
