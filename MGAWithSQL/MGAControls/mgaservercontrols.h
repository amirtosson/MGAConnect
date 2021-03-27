#ifndef MGASERVERCONTROLS_H
#define MGASERVERCONTROLS_H

#include <QWidget>
#include <QTableWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QWidget>
#include <QToolButton>
#include <QVariant>
#include <QApplication>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QHostAddress>
#include <QSettings>
#include <vector>
#include <QRect>
#include <QMenu>
#include <QObject>
#include "mgasidepanelview.h"
#include "MGACommonAction.h"
#include "mgaserverresources.h"
#include "mgawidgetextension.h"


class MGAServerControls:  public QObject
{
    Q_OBJECT

public:
    MGAServerControls();
    bool IntializeSeverConnections();
    bool IntializePopupMenuConnected(QWidget *parent);
    bool IntializePopupMenuDisconnected(QWidget *parent);
    bool ServerParametersAreSaved();
    QMenu *GetConnectecdPopubServerMenu(QWidget *parent);
    QMenu *GetDisconnectecdPopubServerMenu(QWidget *parent);
    void SaveServerParametersAsSetting(QStringList serverSetupList);
    void ServerSettingsActionCalled();
    QTcpSocket * GetServerSocket();

public  slots:
    void DisconnectTheServer();

signals:
    void OpenSettingWindow();

private:

    QTcpSocket *socket = nullptr;
    QMenu *menuPopupConnected;
    QMenu *menuPopupDisconnected;


};

#endif // MGASERVERCONTROLS_H
