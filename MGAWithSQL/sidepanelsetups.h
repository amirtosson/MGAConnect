#ifndef SIDEPANELSETUPS_H
#define SIDEPANELSETUPS_H
#include "sidepanelresources.h"


#define SIDE_PANEL_UI_COMMPONENTS_SETUP\
        sidePanelUi->dbConnectBtn->setText(TXT_DB_CONNECT_BTN_LABEL);\
        sidePanelUi->addNewDatasetButton->setText(TXT_ADD_DATA_BTN_LABEL);\
        sidePanelUi->showDatasetsButton->setText(TXT_SHOW_DATA_BTN_LABEL);\
        sidePanelUi->showUserListButton->setText(TXT_SHOW_USER_BTN_LABEL);\
        sidePanelUi->addGuestButton->setText(TXT_ADD_GUEST_BTN_LABEL);\
        SET_BTN_ICON(dbConnectBtn,URL_DB_CONNECT_BTN_IMG)\
        DISABLE_BUTTONS

#define DISABLE_BUTTONS\
        sidePanelUi->addNewDatasetButton->setEnabled(false);\
        sidePanelUi->showDatasetsButton->setEnabled(false);\
        sidePanelUi->showUserListButton->setEnabled(false);\
        sidePanelUi->addGuestButton->setEnabled(false);

#define ENABLE_BUTTONS\
        sidePanelUi->addNewDatasetButton->setEnabled(true);\
        sidePanelUi->showDatasetsButton->setEnabled(true);\
        if(eCurrentRole == eAdmin)sidePanelUi->showUserListButton->setEnabled(true);\
        sidePanelUi->addGuestButton->setEnabled(true);

#define SET_BTN_ICON(btn,iconURI)\
    btnIcon = QIcon(iconURI);\
    sidePanelUi->btn->setIcon(btnIcon);\
    sidePanelUi->dbConnectBtn->setIconSize(QSize(20, 20));


#endif // SIDEPANELSETUPS_H
