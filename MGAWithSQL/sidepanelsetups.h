#ifndef SIDEPANELSETUPS_H
#define SIDEPANELSETUPS_H
#include "sidepanelresources.h"


#define SIDE_PANEL_UI_COMMPONENTS_SETUP\
        sidePanelUi->dbConnectBtn->setText(TXT_DB_CONNECT_BTN_LABEL);\
        QPixmap pixmap(URL_DB_CONNECT_BTN_IMG);\
        QIcon ButtonIcon(pixmap);\
        sidePanelUi->dbConnectBtn->setIcon(ButtonIcon);\
        sidePanelUi->dbConnectBtn->setIconSize(QSize(20, 20));




#endif // SIDEPANELSETUPS_H
