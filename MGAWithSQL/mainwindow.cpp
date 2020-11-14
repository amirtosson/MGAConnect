#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonObject>

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
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsOver()), this, SLOT(ShowSidePanel()));
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsLeft()), this, SLOT(HideSidePanel()));
    ui->sidePanelStatuscheckBox->setText(TXT_SIDEPANEL_STATUS_CHECK_BOX);
    this->statusBar()->showMessage(TXT_NOT_CONNECTED);
    USE_STYLE(eDarkStyle)
    //ui->mainWidget->setStyleSheet("background-color: rgb(50, 50, 50);");
    //ui->sideToolBoxWidget->setStyleSheet("background-color: rgb(50, 50, 50);");

    socket = new QTcpSocket();
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete socket;

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
        connect(_usersListForm, SIGNAL(NewUserIsReady()),this ,SLOT(AddNewUserClicked()));
    }
    ui->widget->hide();
    ShowUsersList();
}

void MainWindow::StyleHasBeenChanged()
{
    USE_STYLE(_OptionForm->eCurrentStyle)
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

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Connecting,..";

    if (!socket->isValid()) socket->connectToHost("localhost", 9999);
    socket->write("CTSQLD\r\nlocalhost\r\nroot\r\nrock255");
    socket->flush();
    //socket->waitForBytesWritten(3000);

    //socket->waitForBytesWritten(1000);

    //socket->waitForBytesWritten(3000);

}


void MainWindow::connected()
{

}

void MainWindow::disconnected()
{
    qDebug() << "Disconnected!";
}

void MainWindow::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
    socket->write("Hello Server");
    socket->flush();
    socket->waitForBytesWritten(3000);
}

void MainWindow::readyRead()
{
    qDebug() << "Reading...";
     QJsonDocument jsonResponse = QJsonDocument::fromJson(socket->readAll());
     MGAUser user;
    user.SerializeFromJSON(&jsonResponse);
     //QJsonArray jsonArray = jsonResponse.array();

//     qDebug()<<"name: " <<user.GetName()<<endl;
//     qDebug()<<"role: " <<user.GetRole()<<endl;
//     qDebug()<<"host: " <<user.GetHost()<<endl;


//     if(!jsonArray.isEmpty())
//     {
//         QJsonObject jsonObject = jsonArray.first().toObject();
//         qDebug()<< jsonObject.value("host").toString();
//    }

}
