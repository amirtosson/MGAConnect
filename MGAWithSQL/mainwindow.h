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
#include <QPainter>
#include <QScreen>
#include <QApplication>
#include <QStyleFactory>
#include <QPainter>
#include <QPainterPath>

#include "mainwindowresources.h"
#include "dbmainwindowcontrols.h"
#include "mainwindowstyle.h"
#include "QrCode.hpp"

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
    void ShowAppointmentsListClicked();
    void ShowGroupsListClicked();
    void StyleHasBeenChanged();
    void DatabaseHasConnection();
    void DatabaseNotConnected();
    void ShowSidePanel();
    void HideSidePanel();
    void AddNewUserClicked();
    void AddNewObjectClicked(EListType eList);
    void AddNewMemberClicked();
    void AddNewExpClicked();

    void on_sidePanelStatuscheckBox_stateChanged(int arg1);
    void on_actionFullScreen_triggered();
    void on_actionExit_triggered();
    void on_actionResetSize_triggered();
    virtual void paintEvent(QPaintEvent *event);
    void on_actionChat_triggered();



    void on_OpenWebSiteButton_clicked();

signals:
    void SizeChanged(int w, int h);
    void MSGRecieved(QString chatMSG, int senderID);


private:
    Ui::MainWindow *ui;
    bool sidePanelIsFixed =false;
    EMGAStyle eCurrentStyle = eDarkStyle;
    QRect defaultGeometry;
    QPainter *p;

protected:
    void resizeEvent(QResizeEvent* event);
    void ResetToOriginalSize();
    void SetToFullScreen();
    void UpdateSizes(int w, int h);



};

#endif // MAINWINDOW_H
