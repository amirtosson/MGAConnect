#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QApplication>
#include <QStyleFactory>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    IntializeSidePanel(ui->sideToolBoxWidget);
    connect(_sidePanal, SIGNAL(DBCOnnectionButtonClicked()),this ,SLOT(DBConnectionSetUpClicked()));
    connect(_sidePanal, SIGNAL(ShowMembersListButtonClicked()),this ,SLOT(ShowMemberListClicked()));
    connect(_sidePanal, SIGNAL(ShowDatabasesListButtonClicked()),this ,SLOT(ShowDatabasesListClicked()));
    connect(_sidePanal, SIGNAL(ShowUserListButtonIsClicked()),this ,SLOT(ShowUserListClicked()));
    connect(_sidePanal, SIGNAL(ShowExperimentsListButtonIsClicked()),this ,SLOT(ShowExperimentsListClicked()));
    connect(_sidePanal, SIGNAL(ShowAppointmentsListButtonClicked()),this ,SLOT(ShowAppointmentsListClicked()));
    connect(this, SIGNAL(SizeChanged(int,int)),_sidePanal ,SLOT(OnSizeChange(const int, const int)));


    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsOver()), this, SLOT(ShowSidePanel()));
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsLeft()), this, SLOT(HideSidePanel()));
    ui->sidePanelStatuscheckBox->setText(TXT_SIDEPANEL_STATUS_CHECK_BOX);
    this->statusBar()->showMessage(TXT_NOT_CONNECTED);
    USE_STYLE(eCurrentStyle)
    defaultGeometry = this->geometry();
    //ui->mainWidget->setStyleSheet("background-color: rgb(50, 50, 50);");
    //ui->sideToolBoxWidget->setStyleSheet("background-color: rgb(50, 50, 50);");

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::DBConnectionSetUpClicked()
{
    HideAll();
    if(!hasDBForm)
    {
        IntializeDBConnectionForm(ui->mainWidget);
        connect(_dbForm, SIGNAL(DatabaseIsconnected()),this ,SLOT(DatabaseHasConnection()));
        connect(_dbForm, SIGNAL(DatabaseIsDisconnected()),this ,SLOT(DatabaseNotConnected()));
        connect(_dbForm, SIGNAL(DatabaseIsconnected()),_sidePanal ,SLOT(DatabaseIsConnected()));
        connect(_dbForm, SIGNAL(DatabaseIsDisconnected()),_sidePanal ,SLOT(DatabaseIsDisconnected()));
        connect(this, SIGNAL(SizeChanged(int,int)),_dbForm ,SLOT(OnSizeChange(const int, const int)));
    }
    ui->widget->hide();
    _dbForm->show();
}

void MainWindow::ShowMemberListClicked()
{
    HideAll();
    if(!hasMembersListForm)
    {
        IntializeMembersListForm(ui->mainWidget);
    }
    ui->widget->hide();
    ShowMembersList();
}

void MainWindow::ShowDatabasesListClicked()
{
    HideAll();
    if(!hasDatabasesListForm)
    {
        IntializeDatabasesListForm(ui->mainWidget);
    }
    ui->widget->hide();
    ShowDatabasesList();
}

void MainWindow::ShowUserListClicked()
{
    HideAll();
    if(!hasUsersListForm)
    {
        IntializeUsersListForm(ui->mainWidget);
        connect(_usersListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),this ,SLOT(AddNewObjectClicked(const EListType)));
    }
    ui->widget->hide();
    ShowUsersList();
}

void MainWindow::ShowExperimentsListClicked()
{
    HideAll();
    if(!hasExpListForm)
    {
        IntializeExperimentsListForm(ui->mainWidget);
        connect(_experimentsListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),this ,SLOT(AddNewObjectClicked(const EListType)));
    }
    ui->widget->hide();
    ShowExperimentsList();
}

void MainWindow::ShowAppointmentsListClicked()
{
    HideAll();
    if(!hasAppointListForm)
    {
        IntializeAppointmentsListForm(ui->mainWidget);
        connect(_appointmentsListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),this ,SLOT(AddNewObjectClicked(const EListType)));
    }
    ui->widget->hide();
    ShowAppointmentsList();
}

void MainWindow::StyleHasBeenChanged()
{
    eCurrentStyle = _OptionForm->eCurrentStyle;
    USE_STYLE(eCurrentStyle)
    this->update();
}

void MainWindow::DatabaseHasConnection()
{
    this->statusBar()->showMessage(TXT_CONNECTED);
    SetLoginUserRole();
    //TODO: check
    QMessageBox::information(this, tr(TXT_INFORMATION),QString(TXT_CONNECTED_PRIV).arg( _dbForm->GetCurrentUserRoleName()));
}

void MainWindow::DatabaseNotConnected()
{
    this->statusBar()->showMessage(TXT_NOT_CONNECTED);
}

void MainWindow::ShowSidePanel()
{
    if(!sidePanelIsFixed)_sidePanal->show();
}

void MainWindow::HideSidePanel()
{
    if(!sidePanelIsFixed)_sidePanal->hide();
}

void MainWindow::AddNewUserClicked()
{
    AddNewMGAUserToDB();
}

void MainWindow::AddNewObjectClicked(EListType eList)
{
    switch (eList) {
    case eUsersList:
        AddNewMGAUserToDB();
        break;
    case eMemberList:
        AddNewMGAMemberToDB();
        break;
    case eAppointmentList:
        AddNewMGAAppointmentToDB();
        break;
    case eExperimentist:
        AddNewMGAExpToDB();
        break;
    default:
        break;
    }

}

void MainWindow::AddNewMemberClicked()
{

}

void MainWindow::AddNewExpClicked()
{

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
    ui->widget->hide();
    _OptionForm->show();
}


void MainWindow::on_sidePanelStatuscheckBox_stateChanged(int arg1)
{
    switch (arg1) {
    case 0:
        sidePanelIsFixed = false;
        _sidePanal->hide();
        break;
    case 2:
        sidePanelIsFixed = true;
        _sidePanal->show();
        break;
    default:
        break;
    }
}


void MainWindow::on_actionFullScreen_triggered()
{
    if (this->isFullScreen())
    {
        ResetToOriginalSize();
    }
    else
    {
        SetToFullScreen();
    }
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, TXT_WATNING, TXT_EXIT_CONFIRMATION,
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->close();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if ((this->isFullScreen())
        ||((event->size().width() == defaultGeometry.width())
           && (event->size().height() == defaultGeometry.height())))
    {
        return;
    }
    ui->actionResetSize->setEnabled(true);
    int height = event->size().height();
    int width = event->size().width();
    QString style = this->styleSheet();
    style += QString("QWidget {font: 75 %1pt  TeX Gyre Schola;}").arg(0.01*width);
    this->setStyleSheet(style);
    ui->mainWidget->setGeometry(0.14*width,10 , 0.6*width , 0.7*height);
    ui->sideToolBoxWidget->setGeometry(10,10,0.1*width,0.8*height);
    ui->sidePanelStatuscheckBox->setGeometry(10,0.8*height,250,40);
    emit SizeChanged(width,height);
}

void MainWindow::ResetToOriginalSize()
{
    this->showNormal();
    this->resize(defaultGeometry.width(),defaultGeometry.height());
    ui->mainWidget->setGeometry(130,10,640,450);
    ui->sideToolBoxWidget->setGeometry(10,10,100,400);
    ui->sidePanelStatuscheckBox->setGeometry(10,500,150,25);
    USE_STYLE(eCurrentStyle)
    emit SizeChanged(defaultGeometry.width(),defaultGeometry.height());
    ui->actionResetSize->setEnabled(false);
}

void MainWindow::SetToFullScreen()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    QString style = this->styleSheet();
    style += QString("QWidget {font: 75 %1pt  TeX Gyre Schola;}").arg(0.01*width);
    this->setStyleSheet(style);
    ui->mainWidget->setGeometry(260,10 , 0.6*width , 0.7*height);
    ui->sideToolBoxWidget->setGeometry(10,10,0.1*width,0.8*height);
    ui->sidePanelStatuscheckBox->setGeometry(10,0.8*height,250,40);
    emit SizeChanged(width,height);
    this->showFullScreen();
}

void MainWindow::on_actionResetSize_triggered()
{
    ResetToOriginalSize();
}
