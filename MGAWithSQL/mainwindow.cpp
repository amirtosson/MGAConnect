#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    _sidePanal = new SidePanel(ui->sideToolBoxWidget);
    connect(_sidePanal, SIGNAL(DBCOnnectionButtonClicked()),this ,SLOT(DBConnectionSetUpClicked()));
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsOver()), this, SLOT(ShowSidePanel()));
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsLeft()), this, SLOT(HideSidePanel()));
    _sidePanal->hide();
    ui->sidePanelStatuscheckBox->setText(TXT_SIDEPANEL_STATUS_CHECK_BOX);
    this->statusBar()->showMessage(TXT_NOT_CONNECTED);
    USE_STYLE(eDarkStyle)
}

MainWindow::~MainWindow()
{
    delete ui;
    if(hasDBForm)delete _dbForm;
    if(hasOptionForm)delete _OptionForm;
}

void MainWindow::DBConnectionSetUpClicked()
{
    HideAll();
    if(!hasDBForm)
    {
        _dbForm = new DBConnectForm(ui->mainWidget);
        connect(_dbForm, SIGNAL(DatabaseIsconnected()),this ,SLOT(DatabaseHasConnection()));
        connect(_dbForm, SIGNAL(DatabaseIsDisconnected()),this ,SLOT(DatabaseNotConnected()));
        connect(_dbForm, SIGNAL(DatabaseIsconnected()),_sidePanal ,SLOT(DatabaseIsConnected()));
        connect(_dbForm, SIGNAL(DatabaseIsDisconnected()),_sidePanal ,SLOT(DatabaseIsDisconnected()));
        hasDBForm = true;
    }
    _dbForm->show();
}

void MainWindow::StyleHasBeenChanged()
{
    USE_STYLE(_OptionForm->eCurrentStyle)
    this->update();
}

void MainWindow::DatabaseHasConnection()
{
    this->statusBar()->showMessage(TXT_CONNECTED);
    QMessageBox::information(this, tr("Information"),QString("You are connected as %1").arg(_dbForm->GetCurrentUserRoleName()));
}

void MainWindow::DatabaseNotConnected()
{
    this->statusBar()->showMessage(TXT_NOT_CONNECTED);
}

void MainWindow::ShowSidePanel()
{
    if(!sidePanelIsFixwd)_sidePanal->show();
}

void MainWindow::HideSidePanel()
{
   if(!sidePanelIsFixwd)_sidePanal->hide();
}

void MainWindow::on_actionOptions_triggered()
{
    HideAll();
    if(!hasOptionForm)
    {
        _OptionForm = new OptionForm(ui->mainWidget);
        connect(_OptionForm, SIGNAL(StyleIsChanged()),this ,SLOT(StyleHasBeenChanged()));
        hasOptionForm = true;
    }
    _OptionForm->show();
}

void MainWindow::HideAll()
{
    if(hasDBForm)_dbForm->hide();
    if(hasOptionForm)_OptionForm->hide();
}

void MainWindow::on_sidePanelStatuscheckBox_stateChanged(int arg1)
{
    switch (arg1) {
    case 0:
        sidePanelIsFixwd = false;
        _sidePanal->hide();
        break;
    case 2:
        sidePanelIsFixwd = true;
        _sidePanal->show();
        break;
    default:
        break;
    }
}
