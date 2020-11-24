#-------------------------------------------------
#
# Project created by QtCreator 2020-10-24T10:04:24
#
#-------------------------------------------------

QT       +=core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MGAWithSQL
TEMPLATE = app

INCLUDEPATH += MGAObjects/
INCLUDEPATH += MGAControls/

SOURCES += main.cpp\
    MGAObjects/mgaexperiment.cpp \
        mainwindow.cpp \
    dbconnectform.cpp \
    MGAObjects/mgamemberguicomponents.cpp \
    sidepanel.cpp \
    optionform.cpp \
    mgawidgetextension.cpp \
    mgaoptionbuttonextension.cpp \
    mgalistform.cpp \
    MGAObjects/mgadatabase.cpp \
    MGAControls/dbmainwindowcontrols.cpp \
    mgaemailform.cpp \
    MGAObjects/mgamember.cpp \
    MGAObjects/mgauser.cpp \
    addnewobjectform.cpp \
    MGAObjects/mgauserobjectguicomponents.cpp

HEADERS  += mainwindow.h\
    MGAControls/MGAResizableWidgetAbstract.h \
    MGAObjects/mgaexperiment.h \
    dbconnectform.h \
    MGAObjects/mgamemberguicomponents.h \
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
    mgalistform.h \
    MGAObjects/mgalistformtypesenum.h \
    mgalistformresources.h \
    mgalistformsetups.h \
    MGAObjects/mgadatabase.h \
    MGAControls/dbmainwindowcontrols.h \
    mgaemailform.h \
    MGAObjects/mgamember.h \
    MGAObjects/mgauser.h \
    addnewobjectform.h \
    MGAObjects/mgastyleenum.h \
    MGAObjects/mgauserobjectguicomponents.h \
    addnewobjectformresources.h \
    sqlmacro.h

FORMS    += mainwindow.ui \
    dbconnectform.ui \
    sidepanel.ui \
    optionform.ui \
    mgalistform.ui \
    mgaemailform.ui \
    addnewobjectform.ui

RESOURCES += \
    imageresources.qrc \
    styles.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MGAServerClientMSG/release/ -lMGAServerClientMSG
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MGAServerClientMSG/debug/ -lMGAServerClientMSG
else:unix: LIBS += -L$$OUT_PWD/../MGAServerClientMSG/ -lMGAServerClientMSG

INCLUDEPATH += $$PWD/../MGAServerClientMSG
DEPENDPATH += $$PWD/../MGAServerClientMSG

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAServerClientMSG/release/libMGAServerClientMSG.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAServerClientMSG/debug/libMGAServerClientMSG.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAServerClientMSG/release/MGAServerClientMSG.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAServerClientMSG/debug/MGAServerClientMSG.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../MGAServerClientMSG/libMGAServerClientMSG.a


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MGAStringLib/release/ -lMGAString
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MGAStringLib/debug/ -lMGAString
else:unix: LIBS += -L$$OUT_PWD/../MGAStringLib/ -lMGAString

INCLUDEPATH += $$PWD/../MGAStringLib
DEPENDPATH += $$PWD/../MGAStringLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/release/libMGAString.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/debug/libMGAString.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/release/MGAString.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/debug/MGAString.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../MGAStringLib/libMGAString.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SmtpClientThirdParty/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SmtpClientThirdParty/debug/ -lSMTPEmail
else:unix: LIBS += -L$$OUT_PWD/../SmtpClientThirdParty/ -lSMTPEmail

INCLUDEPATH += $$PWD/../SmtpClientThirdParty/src
DEPENDPATH += $$PWD/../SmtpClientThirdParty/src
