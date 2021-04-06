#include "mgaservercontrols.h"
#include <QThread>
#include <QMessageBox>


MGAServerControls::MGAServerControls()
{
    try
    {
        socket = new QTcpSocket();
    }
    catch (...)
    {
        return;
    }
}


bool MGAServerControls::IntializeSeverConnections()
{

    if (socket != nullptr)socket = new QTcpSocket();
    QSettings settings;
    QString ip = settings.value(SERVER_SETTING_IP_GETTER).toString();
    QString port = settings.value(SERVER_SETTING_PORT_GETTER).toString();
    socket->connectToHost(ip,port.toInt());
    return socket->waitForConnected(500);
}

bool MGAServerControls::IntializePopupMenuConnected(QWidget *parent)
{
    try
    {
        menuPopupConnected = new QMenu(parent);
    }
    catch (...)
    {
        return false;
    }
    menuPopupConnected->addAction(MGA_ACTION_DISCONNECT_SERVER(DisconnectTheServer()));
    menuPopupConnected->addAction(MGA_ACTION_TEST_CON_SERVER(DisconnectTheServer()));
    menuPopupConnected->addAction(MGA_ACTION_SETTINGS_SERVER(ServerSettingsActionCalled()));
    return true;
}

bool MGAServerControls::IntializePopupMenuDisconnected(QWidget *parent)
{
    try
    {
        menuPopupDisconnected = new QMenu(parent);
    }
    catch (...)
    {
        return false;
    }
    menuPopupDisconnected->addAction(MGA_ACTION_RECONNECT_SERVER(DisconnectTheServer()));
    menuPopupDisconnected->addAction(MGA_ACTION_SETTINGS_SERVER(ServerSettingsActionCalled()));
    return true;
}

bool MGAServerControls::ServerParametersAreSaved()
{
    QSettings qSetting;
    return !qSetting.value(SERVER_SETTING_IP_GETTER).toString().isEmpty()
            && !qSetting.value(SERVER_SETTING_PORT_GETTER).toString().isEmpty();
}

QMenu *MGAServerControls::GetConnectecdPopubServerMenu(QWidget *parent)
{
    IntializePopupMenuConnected(parent);
    return menuPopupConnected;
}

QMenu *MGAServerControls::GetDisconnectecdPopubServerMenu(QWidget *parent)
{
    IntializePopupMenuDisconnected(parent);
    return menuPopupDisconnected;
}

void MGAServerControls::DisconnectTheServer()
{
    qDebug() << "DIIIIII";
}

void MGAServerControls::SaveServerParametersAsSetting(QStringList serverSetupList)
{
    QSettings qSetting;
    if (!qSetting.contains(SERVER_SETTING_GROUP))
    {
        qSetting.beginGroup(SERVER_SETTING_GROUP);

    }
    qSetting.setValue(SERVER_SETTING_IP, serverSetupList[0]);
    qSetting.setValue(SERVER_SETTING_PORT, serverSetupList[1]);
}

void MGAServerControls::ServerSettingsActionCalled()
{
   emit OpenSettingWindow();
}

QTcpSocket *MGAServerControls::GetServerSocket()
{
    return socket;
}

