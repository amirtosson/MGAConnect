#include "sidepanel.h"
#include "ui_sidepanel.h"
#include <QSize>


SidePanel::SidePanel(QWidget *parent) :
    QWidget(parent),
    sidePanelUi(new Ui::SidePanel)
{
    sidePanelUi->setupUi(this);
    this->setGeometry(0,0,parent->width(),parent->height());
    sidePanelUi->dbConnectBtn->setGeometry(0,0 ,this->width(), this->height()/5);
    sidePanelUi->showUsersButton->setGeometry(0,sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);
    sidePanelUi->showMemberListButton->setGeometry(0,2*sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);
    sidePanelUi->showExpButton->setGeometry(0,3*sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);
    sidePanelUi->showAppointmentsButton->setGeometry(0,4*sidePanelUi->dbConnectBtn->height() ,this->width(), this->height()/5);
    UPDATE_SIZES(parent->width(),parent->height())
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
    UPDATE_SIZES(w,h)
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
