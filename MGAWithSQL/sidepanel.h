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

public slots:
    void OnSizeChange(int w, int h);

private slots:
    void on_dbConnectBtn_clicked();
    void DatabaseIsConnected();
    void DatabaseIsDisconnected();
    void on_showMemberListButton_clicked();
    void on_showUsersButton_clicked();
    void on_showExpButton_clicked();
    void on_showAppointmentsButton_clicked();

signals:
    void DBCOnnectionButtonClicked();
    void ShowMembersListButtonClicked();
    void ShowUserListButtonIsClicked();
    void ShowExperimentsListButtonIsClicked();
    void ShowAppointmentsListButtonClicked();
    void ShowDatabasesListButtonClicked();



private:
    Ui::SidePanel *sidePanelUi;
    QPixmap btnPixMap;
    QIcon btnIcon;
    EUserRole eCurrentRole = eUNKNOWN;

};

#endif // SIDEPANEL_H
