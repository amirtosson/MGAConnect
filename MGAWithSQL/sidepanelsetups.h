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

#define SET_BTN_ICON_SIZE(S)\
        sidePanelUi->dbConnectBtn->setIconSize(QSize(S, S));\
        sidePanelUi->showUsersButton->setIconSize(QSize(S, S));\
        sidePanelUi->showMemberListButton->setIconSize(QSize(S, S));\
        sidePanelUi->showExpButton->setIconSize(QSize(S, S));\
        sidePanelUi->showAppointmentsButton->setIconSize(QSize(S, S));\

#define UPDATE_SIZES(W,H)\
    this->setGeometry(0,0,W,H);\
    sidePanelUi->dbConnectBtn->setGeometry(0,0 ,this->width(), this->height()/5);\
    sidePanelUi->showUsersButton->setGeometry(0,sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);\
    sidePanelUi->showMemberListButton->setGeometry(0,2*sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);\
    sidePanelUi->showExpButton->setGeometry(0,3*sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);\
    sidePanelUi->showAppointmentsButton->setGeometry(0,4*sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);\
    if(H  <  450)\
    {\
        this->setStyleSheet(STYLE_FONT_12PIX_BOLD);\
        SET_BTN_ICON_SIZE(40)\
    }\
    else\
    {\
        this->setStyleSheet(STYLE_FONT_24PIX_BOLD);\
        SET_BTN_ICON_SIZE(80)\
    }\

#endif // SIDEPANELSETUPS_H
