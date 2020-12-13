#include "mgasidepanelview.h"
#include <QDebug>



void MGASidePanelView::setupUi(QWidget *sidePanel, EUserRole eRole)
{
    if (sidePanel->objectName().isEmpty())
    {
        sidePanel->setObjectName(QString::fromUtf8("SidePanel"));
    }
    sidePanel->resize(120, 550);

    try
    {
        parentGridLayout = new QGridLayout(sidePanel);
        buttonsScrollArea = new QScrollArea(sidePanel);
        scrollAreaWidgetContents = new QWidget();
        contentsGridLayout = new QGridLayout(scrollAreaWidgetContents);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    }
    catch (...)
    {
        return;
    }
    parentGridLayout->setSpacing(0);
    parentGridLayout->setContentsMargins(0, 0, 0, 0);
    buttonsScrollArea->setWidgetResizable(true);
    buttonsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 548));
    contentsGridLayout->setSpacing(5);
    contentsGridLayout->setContentsMargins(5, 5, 5, 5);
    IntializeAdminButtons(scrollAreaWidgetContents);
    IntializeButtonsStyles();
        switch (eRole)
    {
        case eAdmin:

            break;
        case eUser:

            break;
        case eGuest:

            break;
        case eStudent:

            break;
        default:
            break;
    }
    buttonsScrollArea->setWidget(scrollAreaWidgetContents);
    parentGridLayout->addWidget(buttonsScrollArea, 0, 0, 3, 2);
    QMetaObject::connectSlotsByName(sidePanel);
}

void MGASidePanelView::ToolButtonsIntialization(QWidget *buttonsArea)
{
    try
    {
        unsigned int counter = 0;
        for (auto it = sidePanelButtons.begin() ; it != sidePanelButtons.end(); ++it)
        {
            *it =   new QToolButton(buttonsArea);
            contentsGridLayout->addWidget(*it, counter, 0, 1, 1);
            (*it)->setMinimumWidth(buttonsArea->width() *0.8 );
            (*it)->setMaximumWidth(buttonsArea->width() *0.8 );
            (*it)->setMinimumHeight((*it)->width()*0.9 );
            (*it)->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

            counter++;
        }
        contentsGridLayout->addItem(verticalSpacer, counter, 0, 1, 1);
    }
    catch (...)
    {

    }

}

void MGASidePanelView::IntializeAdminButtons(QWidget *buttonsArea)
{
    sidePanelButtons.resize(6);
    ToolButtonsIntialization(buttonsArea);
}

void MGASidePanelView::IntializeDBConnectButton()
{

    sidePanelButtons[0]->setObjectName(QString::fromUtf8("dbConnectBtn"));
    sidePanelButtons[0]->setText(TXT_DB_CONNECT_BTN_LABEL);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(URL_DB_CONNECT_IMG), QSize(), QIcon::Normal, QIcon::On);
    sidePanelButtons[0]->setIcon(icon1);
    //sidePanelButtons[0]->setIconSize(QSize(20, 20));

}

void MGASidePanelView::IntializeButtonsStyles()
{
    QIcon icons[6];
    icons[0].addFile(QString::fromUtf8(URL_DB_CONNECT_IMG), QSize(), QIcon::Normal, QIcon::On);
    icons[1].addFile(QString::fromUtf8(URL_USERS_LIST_IMG), QSize(), QIcon::Normal, QIcon::On);
    icons[2].addFile(QString::fromUtf8(URL_MEMBERS_LIST_IMG), QSize(), QIcon::Normal, QIcon::On);
    icons[3].addFile(QString::fromUtf8(URL_EXP_LIST_IMG), QSize(), QIcon::Normal, QIcon::On);
    icons[4].addFile(QString::fromUtf8(URL_APPOINTS_LIST_IMG), QSize(), QIcon::Normal, QIcon::On);
    icons[5].addFile(QString::fromUtf8(URL_GROUPS_LIST_IMG), QSize(), QIcon::Normal, QIcon::On);

    sidePanelButtons[0]->setObjectName(QString::fromUtf8("dbConnectBtn"));
    sidePanelButtons[0]->setText(TXT_DB_CONNECT_BTN_LABEL);
    sidePanelButtons[0]->setIcon(icons[0]);

    sidePanelButtons[1]->setObjectName(QString::fromUtf8("showUsersButton"));
    sidePanelButtons[1]->setText(TXT_SHOW_USER_BTN_LABEL);
    sidePanelButtons[1]->setIcon(icons[1]);

    sidePanelButtons[2]->setObjectName(QString::fromUtf8("showMemberListButton"));
    sidePanelButtons[2]->setText(TXT_SHOW_MEMBER_BTN_LABEL);
    sidePanelButtons[2]->setIcon(icons[2]);

    sidePanelButtons[3]->setObjectName(QString::fromUtf8("showExpButton"));
    sidePanelButtons[3]->setText(TXT_SHOW_EXP_BTN_LABEL);
    sidePanelButtons[3]->setIcon(icons[3]);

    sidePanelButtons[4]->setObjectName(QString::fromUtf8("showAppointmentsButton"));
    sidePanelButtons[4]->setText(TXT_SOWM_APPOINTMENTS_BTN_LABEL);
    sidePanelButtons[4]->setIcon(icons[4]);

    sidePanelButtons[5]->setObjectName(QString::fromUtf8("showGroupsButton"));
    sidePanelButtons[5]->setText(TXT_SOWM_GROUPS_BTN_LABEL);
    sidePanelButtons[5]->setIcon(icons[5]);
    ButtonsState(false);
}

void MGASidePanelView::ButtonsState(bool enabled)
{
    // db connect button is always enabled
    for (auto it = sidePanelButtons.begin() + 1 ; it != sidePanelButtons.end(); ++it)
    {
        (*it)->setEnabled(enabled);
    }
}

void MGASidePanelView::ResizeComponents(int w, int h)
{
    buttonsScrollArea->resize(w,h);
    for (auto it = sidePanelButtons.begin() ; it != sidePanelButtons.end(); ++it)
    {
        (*it)->setMinimumWidth(buttonsScrollArea->width() * 0.8 );
        (*it)->setMaximumWidth(buttonsScrollArea->width() * 0.8 );
        (*it)->setMinimumHeight((*it)->width() * 0.9 );
        int width=(*it)->height()*SIDE_PANEL_ICON_RATIO;
        (*it)->setIconSize(QSize(width, width));
    }
}

