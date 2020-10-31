#ifndef SIDEPANELSETUPS_H
#define SIDEPANELSETUPS_H
#include "sidepanelresources.h"


#define SIDE_PANEL_UI_COMMPONENTS_SETUP\
        sidePanelUi->dbConnectBtn->setText(TXT_DB_CONNECT_BTN_LABEL);\
        sidePanelUi->addNewDatasetButton->setText(TXT_ADD_DATA_BTN_LABEL);\
        sidePanelUi->showDatasetsButton->setText(TXT_SHOW_DATA_BTN_LABEL);\
        sidePanelUi->showUserListButton->setText(TXT_SHOW_USER_BTN_LABEL);\
        sidePanelUi->extraButton->setText(TXT_EXTRA_BTN_LABEL);\
        QPixmap pixmap(URL_DB_CONNECT_BTN_IMG);\
        QIcon ButtonIcon(pixmap);\
        sidePanelUi->dbConnectBtn->setIcon(ButtonIcon);\
        sidePanelUi->dbConnectBtn->setIconSize(QSize(20, 20));\
        DISABLE_BUTTONS

#define DISABLE_BUTTONS\
        sidePanelUi->addNewDatasetButton->setEnabled(false);\
        sidePanelUi->showDatasetsButton->setEnabled(false);\
        sidePanelUi->showUserListButton->setEnabled(false);\
        sidePanelUi->extraButton->setEnabled(false);

#define ENABLE_BUTTONS\
        sidePanelUi->addNewDatasetButton->setEnabled(true);\
        sidePanelUi->showDatasetsButton->setEnabled(true);\
        sidePanelUi->showUserListButton->setEnabled(true);\
        sidePanelUi->extraButton->setEnabled(true);



#endif // SIDEPANELSETUPS_H
