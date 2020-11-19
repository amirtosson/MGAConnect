#ifndef MGASQLRESOURCES_H
#define MGASQLRESOURCES_H
#include <QString>

#define TXT_DB_NAME_LABEL               "Database Name:"

#define TXT_DB_NAME_PH                  "My database"

#define TXT_DB_URI_LABEL                "Database URI:"

#define TXT_DB_URI_PH                   "tcp://127.0.0.1:8888"

#define TXT_DB_USER_NAME_LABEL          "User Name:"

#define TXT_DB_USER_NAME_PH             "My name"

#define TXT_DB_PASSWORD_LABEL           "Password:"

#define TXT_DB_PASSWORD_PH              "password"

#define TXT_ADD_DB_BTN_LABEL            "Connect"

#define TXT_DISCONNECT_DB_BTN_LABEL     "Disconnect"

#define TXT_FORM_TITLE_LABEL            "Database parameters"

//styles
#define STYLE_FONT_24PIX_BOLD           "font-size:24px; font-weight: bold;"


//images URLs
#define IMG_NOT_CONNECTED               "border-image: url(:/db/Resources/Images/databasenotconnected.png);"
#define IMG_CONNECTED                   "border-image: url(:/db/Resources/Images/databaseconnected.png);"
#define IMG_CONNECT                     ":/db/Resources/Icons/connect.png"

//Server Msg JSON defines
#define JSON_ATT_USER                   "user"
#define JSON_ATT_MEMBER                 "member"
#define JSON_ATT_HOST                   "host"
#define JSON_ATT_PWD                    "password"
#define JSON_ATT_LOGIN_USER_ROLE        "role"
#define JSON_ATT_CONNECTED              "connected"
#define JSON_ATT_ADDED                  "added"
#define JSON_ATT_DISCONNECTED           "disconnected"
#define JSON_ATT_ADDED                  "added"
#define JSON_ATT_DELETED                "deleted"

#define TRUE                            "true"
#define FALSE                           "false"

#define MGA_DELIMITER                   "#-#"

#endif // MGASQLRESOURCES_H
