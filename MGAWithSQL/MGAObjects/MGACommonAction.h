#ifndef MGACOMMONACTION_H
#define MGACOMMONACTION_H
#include "MGACommonActionsRescources.h"

#define MGA_ACTION_DISCONNECT_SERVER(func)\
        SERVER_MENU_DISCONNECT_ACTION_TXT, [=](){\
        func;}

#define MGA_ACTION_TEST_CON_SERVER(func)\
        SERVER_MENU_TEST_CON_ACTION_TXT, [=](){\
        func;}

#define MGA_ACTION_RECONNECT_SERVER(func)\
        SERVER_MENU_RECONNECT_ACTION_TXT, [=](){\
        func;}

#define MGA_ACTION_SETTINGS_SERVER(func)\
        SERVER_MENU_SETTINGS_ACTION_TXT, [=](){\
        func;}

#endif // MGACOMMONACTION_H
