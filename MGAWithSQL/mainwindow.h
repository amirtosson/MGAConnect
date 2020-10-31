#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QPushButton>
#include <QMessageBox>

#include "dbconnectform.h"
#include "sidepanel.h"
#include "mainwindowstyle.h"
#include "optionform.h"
#include "mainwindowresources.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOptions_triggered();
    void DBConnectionSetUpClicked();
    void StyleHasBeenChanged();
    void DatabaseHasConnection();
    void DatabaseNotConnected();
    void ShowSidePanel();
    void HideSidePanel();


    void on_sidePanelStatuscheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    DBConnectForm *_dbForm;
    SidePanel *_sidePanal;
    OptionForm *_OptionForm;

    bool hasDBForm = false;
    bool hasOptionForm = false;
    bool sidePanelIsFixwd =false;

private:
    void HideAll();

};

#endif // MAINWINDOW_H
