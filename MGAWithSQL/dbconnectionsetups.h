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
        dbConnectFormUi->dbFormLabel->setStyleSheet(STYLE_FONT_BOLD);\
        dbConnectFormUi->dbFormLabel->setAlignment(Qt::AlignCenter);\
        dbConnectFormUi->loadDetailsButton->setToolTip(TXT_LOAD_DATA_BTN_LABEL);\
        dbConnectFormUi->updateDetailsButton->setToolTip(TXT_SAVE_DATA_BTN_LABEL);\
        dbConnectFormUi->connectToDBButton->setText(TXT_ADD_DB_BTN_LABEL);\
        dbConnectFormUi->disconnectDBButton->setText(TXT_DISCONNECT_DB_BTN_LABEL);\
        dbConnectFormUi->connectToDBButton->setStyleSheet(STYLE_FONT_BOLD);\
        dbConnectFormUi->disconnectDBButton->setStyleSheet(STYLE_FONT_BOLD);\
        SET_BTN_ICON(loadDetailsButton,IMG_LOAD_DATA)\
        SET_BTN_ICON(updateDetailsButton,IMG_UPDATE_DATA)\
        SET_BTN_ICON(connectToDBButton,IMG_CONNECT)\
        SET_BTN_ICON(disconnectDBButton,IMG_DISCONNECT)\
        DATABASE_IS_NOT_CONNECTED\

#define DATABASE_IS_CONNECTED\
        dbConnectFormUi->databaseIconWidget->setStyleSheet(IMG_CONNECTED);\
        dbConnectFormUi->connectToDBButton->setEnabled(false);\
        dbConnectFormUi->disconnectDBButton->setEnabled(true);

#define DATABASE_IS_NOT_CONNECTED\
        dbConnectFormUi->databaseIconWidget->setStyleSheet(IMG_NOT_CONNECTED);\
        dbConnectFormUi->connectToDBButton->setEnabled(true);\
        dbConnectFormUi->disconnectDBButton->setEnabled(false);

#define SERIALIZE_USER_ROLE\
    if(sCurrentUserRoleName == ADMIN_ROLE) eCurrentUserRole = eAdmin;\
    else if (sCurrentUserRoleName == USER_ROLE) eCurrentUserRole = eUser;\
    else if (sCurrentUserRoleName == GUEST_ROLE) eCurrentUserRole = eGuest;\
    else if (sCurrentUserRoleName == STUDENT_ROLE) eCurrentUserRole = eStudent;\
    else eCurrentUserRole = eUNKNOWN;

#define SET_BTN_ICON(btn,iconURI)\
    btnIcon = QIcon(iconURI);\
    dbConnectFormUi->btn->setIcon(btnIcon);\
    dbConnectFormUi->btn->setIconSize(QSize(30, 30));


#endif // MAINWINDOWDBCONNECTIONSETUPS_H
