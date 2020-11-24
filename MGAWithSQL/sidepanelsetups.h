#ifndef SIDEPANELSETUPS_H
#define SIDEPANELSETUPS_H
#include "sidepanelresources.h"


#define SIDE_PANEL_UI_COMMPONENTS_SETUP\
        SET_BTN_ICON(dbConnectBtn,URL_DB_CONNECT_IMG)\
        SET_BTN_ICON(showMemberListButton,URL_MEMBERS_LIST_IMG)\
        SET_BTN_ICON(showUsersButton,URL_USERS_LIST_IMG)\
        SET_BTN_ICON(showExpButton,URL_EXP_LIST_IMG)\
        SET_BTN_ICON(showAppointmentsButton,URL_APPOINTS_LIST_IMG)\
        sidePanelUi->dbConnectBtn->setText(TXT_DB_CONNECT_BTN_LABEL);\
        sidePanelUi->showExpButton->setText(TXT_SHOW_EXP_BTN_LABEL);\
        sidePanelUi->showUsersButton->setText(TXT_SHOW_USER_BTN_LABEL);\
        sidePanelUi->showMemberListButton->setText(TXT_SHOW_MEMBER_BTN_LABEL);\
        sidePanelUi->showAppointmentsButton->setText(TXT_SOWM_APPOINTMENTS_BTN_LABEL);\
        DISABLE_BUTTONS

#define DISABLE_BUTTONS\
        sidePanelUi->showExpButton->setEnabled(false);\
        sidePanelUi->showUsersButton->setEnabled(false);\
        sidePanelUi->showMemberListButton->setEnabled(false);\
        sidePanelUi->showAppointmentsButton->setEnabled(false);

#define ENABLE_BUTTONS\
        sidePanelUi->showExpButton->setEnabled(true);\
        if(eCurrentRole == eAdmin)sidePanelUi->showUsersButton->setEnabled(true);\
        if(eCurrentRole == eAdmin)sidePanelUi->showMemberListButton->setEnabled(true);\
        sidePanelUi->showAppointmentsButton->setEnabled(true);

#define SET_BTN_ICON(btn,iconURI)\
        btnIcon = QIcon(iconURI);\
        sidePanelUi->btn->setIcon(btnIcon);\
        sidePanelUi->btn->setIconSize(QSize(40, 40));



#endif // SIDEPANELSETUPS_H
