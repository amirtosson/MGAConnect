#include "sidepanel.h"
#include "ui_sidepanel.h"
#include <QSize>


SidePanel::SidePanel(QWidget *parent) :
    QWidget(parent),
    sidePanelUi(new Ui::SidePanel)
{
    sidePanelUi->setupUi(this);
    //this->setStyleSheet(SIDE_PANEL_BUTTON_STYLE);
    SIDE_PANEL_UI_COMMPONENTS_SETUP
}

SidePanel::~SidePanel()
{
    delete sidePanelUi;
}

void SidePanel::on_dbConnectBtn_clicked()
{
    emit DBCOnnectionButtonClicked();
}


