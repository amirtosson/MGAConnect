#ifndef MGASIDEPANELVIEW_H
#define MGASIDEPANELVIEW_H


#include <QWidget>
#include <QToolButton>
#include <QVariant>
#include <QApplication>
#include <QGridLayout>
#include <QScrollArea>
#include <QSpacerItem>
#include <QWidget>
#include <vector>
#include "MGAResizableWidgetAbstract.h"
#include "mgauserrolesenum.h"
#include "sidepanelresources.h"



class MGASidePanelView
{

public:
    void setupUi(QWidget *sidePanel, EUserRole eRole);
    void ResizeComponents(int w, int h);
    void ButtonsState(bool enabled);



public slots:
    virtual void on_dbConnectBtn_clicked() = 0;
    virtual void on_showMemberListButton_clicked() = 0;
    virtual void on_showUsersButton_clicked() = 0;
    virtual void on_showExpButton_clicked() = 0;
    virtual void on_showAppointmentsButton_clicked() = 0;
    virtual void on_showGroupsButton_clicked() = 0;



protected:
    std::vector<QToolButton *> sidePanelButtons;
    QGridLayout *parentGridLayout;
    QGridLayout *contentsGridLayout;
    QScrollArea *buttonsScrollArea;
    QWidget *scrollAreaWidgetContents;
    QSpacerItem *verticalSpacer;

private:
    void ToolButtonsIntialization(QWidget *buttonsArea);
    void IntializeAdminButtons(QWidget *buttonsArea);
    void IntializeDBConnectButton();
    void IntializeButtonsStyles();



};

#endif // MGASIDEPANELVIEW_H
