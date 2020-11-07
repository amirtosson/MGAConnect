#include "sidepanel.h"
#include "ui_sidepanel.h"
#include <QSize>


SidePanel::SidePanel(QWidget *parent) :
    QWidget(parent),
    sidePanelUi(new Ui::SidePanel)
{
    sidePanelUi->setupUi(this);
    SIDE_PANEL_UI_COMMPONENTS_SETUP

}

SidePanel::~SidePanel()
{
    delete sidePanelUi;
}

void SidePanel::SetCurrentRole(EUserRole eRole)
{
    eCurrentRole = eRole;
}

void SidePanel::on_dbConnectBtn_clicked()
{
    emit DBCOnnectionButtonClicked();
}

void SidePanel::DatabaseIsConnected()
{
    ENABLE_BUTTONS
}

void SidePanel::DatabaseIsDisconnected()
{
    DISABLE_BUTTONS
}

void SidePanel::on_showMemberListButton_clicked()
{
    emit ShowMembersListButtonClicked();
}

void SidePanel::on_showUsersButton_clicked()
{
    emit ShowUserListButtonIsClicked();
}
