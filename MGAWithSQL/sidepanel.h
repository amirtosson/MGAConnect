#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QWidget>
#include <QPixmap>
#include <QIcon>

#include "sidepanelsetups.h"
#include "mgauserrolesenum.h"


namespace Ui {
class SidePanel;
}


class SidePanel : public QWidget
{
    Q_OBJECT

public:
    explicit SidePanel(QWidget *parent = 0);
    ~SidePanel();
    void SetCurrentRole(EUserRole eRole);

private slots:
    void on_dbConnectBtn_clicked();
    void DatabaseIsConnected();
    void DatabaseIsDisconnected();
    void on_showMemberListButton_clicked();
    void on_showUsersButton_clicked();

signals:
    void DBCOnnectionButtonClicked();
    void ShowMembersListButtonClicked();
    void ShowUserListButtonIsClicked();
    void ShowDatabasesListButtonClicked();



private:
    Ui::SidePanel *sidePanelUi;
    QPixmap btnPixMap;
    QIcon btnIcon;
    EUserRole eCurrentRole = eUNKNOWN;

};

#endif // SIDEPANEL_H
