#include "sidepanel.h"
//#include "ui_sidepanel.h"
#include <QSize>
#include "QDebug"

SidePanel::SidePanel(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this, eCurrentRole);
    ResizeComponents(parent->width(),parent->height());
    //SIDE_PANEL_UI_COMMPONENTS_SETUP
    //UpdateSizes(parent->width(),parent->height());
}

SidePanel::~SidePanel()
{

}

void SidePanel::SetCurrentRole(EUserRole eRole)
{
    eCurrentRole = eRole;
}

void SidePanel::OnSizeChange(int w, int h)
{
    UpdateSizes(SIDE_PANEL_WIDTH_RATIO*w , SIDE_PANEL_HEIGHT_RATIO*h);
}

void SidePanel::on_dbConnectBtn_clicked()
{
    emit DBCOnnectionButtonClicked();
}

void SidePanel::DatabaseIsConnected()
{
    ButtonsState(true);
}

void SidePanel::DatabaseIsDisconnected()
{
    ButtonsState(false);
}

void SidePanel::on_showMemberListButton_clicked()
{
    emit ShowMembersListButtonClicked();
}

void SidePanel::on_showUsersButton_clicked()
{
    emit ShowUserListButtonIsClicked();
}

void SidePanel::on_showExpButton_clicked()
{
    emit ShowExperimentsListButtonIsClicked();
}

void SidePanel::on_showAppointmentsButton_clicked()
{
    emit ShowAppointmentsListButtonClicked();
}

void SidePanel::on_showGroupsButton_clicked()
{
    emit ShowGroupsButtonClicked();
}

void SidePanel::UpdateSizes(int w, int h)
{
    this->resize(w,h);
    ResizeComponents(w,h);
}

void SidePanel::SetIconSize(int h)
{

}
