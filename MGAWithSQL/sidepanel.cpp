#include "sidepanel.h"
#include "ui_sidepanel.h"
#include <QSize>


SidePanel::SidePanel(QWidget *parent) :
    QWidget(parent),
    sidePanelUi(new Ui::SidePanel)
{
    sidePanelUi->setupUi(this);
    UpdateSizes(parent->width(),parent->height());
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

void SidePanel::on_showExpButton_clicked()
{
    emit ShowExperimentsListButtonIsClicked();
}

void SidePanel::on_showAppointmentsButton_clicked()
{
    emit ShowAppointmentsListButtonClicked();
}

void SidePanel::UpdateSizes(int w, int h)
{
    this->setGeometry(0,0,w,h);
    SetIconSize(h*SIDE_PANEL_ICON_RATIO);
    sidePanelUi->dbConnectBtn->setGeometry(0,0 ,this->width()-10, this->height()*SIDE_PANEL_BUTTON_HEIGHT_RATIO);
    sidePanelUi->showUsersButton->setGeometry(0,sidePanelUi->dbConnectBtn->height() ,this->width()-10, this->height()*SIDE_PANEL_BUTTON_HEIGHT_RATIO);
    sidePanelUi->showMemberListButton->setGeometry(0,2*sidePanelUi->dbConnectBtn->height() ,this->width()-10, this->height()*SIDE_PANEL_BUTTON_HEIGHT_RATIO);
    sidePanelUi->showExpButton->setGeometry(0,3*sidePanelUi->dbConnectBtn->height() ,this->width()-10, this->height()*SIDE_PANEL_BUTTON_HEIGHT_RATIO);
    sidePanelUi->showAppointmentsButton->setGeometry(0,4*sidePanelUi->dbConnectBtn->height() ,this->width()-10, this->height()*SIDE_PANEL_BUTTON_HEIGHT_RATIO);
    this->update();
}

void SidePanel::SetIconSize(int h)
{
    sidePanelUi->dbConnectBtn->setIconSize(QSize(h, h));
    sidePanelUi->showUsersButton->setIconSize(QSize(h, h));
    sidePanelUi->showMemberListButton->setIconSize(QSize(h, h));
    sidePanelUi->showExpButton->setIconSize(QSize(h, h));
    sidePanelUi->showAppointmentsButton->setIconSize(QSize(h, h));
}
