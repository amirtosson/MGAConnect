#-------------------------------------------------
#
# Project created by QtCreator 2020-10-24T10:04:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MGAWithSQL
TEMPLATE = app

INCLUDEPATH += ../mysqlConnect/include/
INCLUDEPATH += MGAObjects/

LIBS += -L$$PWD/../mysqlConnect/lib -lmysqlcppconn


SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnectform.cpp \
    sidepanel.cpp \
    optionform.cpp \
    mgawidgetextension.cpp \
    mgaoptionbuttonextension.cpp \
    MGAObjects/mgauser.cpp \
    mgalistform.cpp

HEADERS  += mainwindow.h\
    sqlmacro.h \
    dbconnectform.h \
    sidepanel.h \
    mainwindowstyle.h \
    optionform.h \
    dbconnectformresources.h \
    dbconnectionsetups.h \
    sidepanelresources.h \
    sidepanelsetups.h \
    mgawidgetextension.h \
    mgaoptionbuttonextension.h \
    optionformsetups.h \
    optionformresources.h \
    mainwindowresources.h \
    mgauserrolesenum.h \
    MGAObjects/mgauser.h \
    mgalistform.h \
    MGAObjects/mgalistformtypesenum.h \
    mgalistformresources.h \
    mgalistformsetups.h

FORMS    += mainwindow.ui \
    dbconnectform.ui \
    sidepanel.ui \
    optionform.ui \
    mgalistform.ui

RESOURCES += \
    imageresources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MGAStringLib/ -lMGAString
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MGAStringLib/ -lMGAStringd
else:unix: LIBS += -L$$OUT_PWD/../MGAStringLib/ -lMGAString

INCLUDEPATH += $$PWD/../MGAStringLib
DEPENDPATH += $$PWD/../MGAStringLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/libMGAString.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/libMGAStringd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/MGAString.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/MGAStringd.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/libMGAString.a


