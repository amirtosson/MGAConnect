#ifndef MGAMAINWINDOWVIEW_H
#define MGAMAINWINDOWVIEW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QVariant>
#include <QIcon>
#include <QAction>
#include <QApplication>
#include <QCheckBox>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QToolButton>

#include "mgawidgetextension.h"

class MGAMainWindowView: public  QMainWindow
{

public:
    explicit MGAMainWindowView(QWidget *parent = nullptr);
    void setupUi(QMainWindow *MainWindow);
signals:


public:
    QAction *actionOptions;
    QAction *actionExit;
    QAction *actionFullScreen;
    QAction *actionResetSize;
    QAction *actionChat;
    QAction *actionserverAction;
    QWidget *centralWidget;
    QWidget *mainWidget;
    QWidget *widget;
    QToolButton *OpenWebSiteButton;
    QLabel *MGAWelcomeLabel;
    MGAWidgetExtension *sideToolBoxWidget;
    QCheckBox *sidePanelStatuscheckBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;


};

#endif // MGAMAINWINDOWVIEW_H
