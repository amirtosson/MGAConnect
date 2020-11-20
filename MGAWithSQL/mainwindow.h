#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QPushButton>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTcpSocket>

#include "mainwindowresources.h"
#include "dbmainwindowcontrols.h"
#include "mainwindowstyle.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, private DBMainWindowControls
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOptions_triggered();
    void DBConnectionSetUpClicked();
    void ShowMemberListClicked();
    void ShowDatabasesListClicked();
    void ShowUserListClicked();
    void ShowExperimentsListClicked();
    void StyleHasBeenChanged();
    void DatabaseHasConnection();
    void DatabaseNotConnected();
    void ShowSidePanel();
    void HideSidePanel();

    void AddNewUserClicked();
    void AddNewMemberClicked();
    void AddNewExpClicked();
    void on_sidePanelStatuscheckBox_stateChanged(int arg1);


    void on_actionFullScreen_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    bool sidePanelIsFixed =false;

};

#endif // MAINWINDOW_H
