#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MGAObject.h"
#include <QDesktopServices>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!IntializeChatDialog(this) || !IntializeSidePanel(ui->sideToolBoxWidget) || !IntializeChatbot()) return;

    connect(_sidePanal, SIGNAL(DBCOnnectionButtonClicked()),this ,SLOT(DBConnectionSetUpClicked()));
    connect(_sidePanal, SIGNAL(ShowMembersListButtonClicked()),this ,SLOT(ShowMemberListClicked()));
    connect(_sidePanal, SIGNAL(ShowDatabasesListButtonClicked()),this ,SLOT(ShowDatabasesListClicked()));
    connect(_sidePanal, SIGNAL(ShowUserListButtonIsClicked()),this ,SLOT(ShowUserListClicked()));
    connect(_sidePanal, SIGNAL(ShowExperimentsListButtonIsClicked()),this ,SLOT(ShowExperimentsListClicked()));
    connect(_sidePanal, SIGNAL(ShowAppointmentsListButtonClicked()),this ,SLOT(ShowAppointmentsListClicked()));
    connect(_sidePanal, SIGNAL(ShowGroupsButtonClicked()),this ,SLOT(ShowGroupsListClicked()));

    connect(_chatForm, SIGNAL(ChatBotMSGHasBeenSent(QString)),_chatbotServer ,SLOT(UserToChatBotMSGHasBeenSent(QString)));
    connect(_chatbotServer, SIGNAL(MSGRecieved(QString, int)), _chatForm ,SLOT(OnMSGHasBeenRecieved(QString, int)));


    connect(this, SIGNAL(SizeChanged(int,int)),_sidePanal ,SLOT(OnSizeChange(const int, const int)));
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsOver()), this, SLOT(ShowSidePanel()));
    connect(ui->sideToolBoxWidget ,SIGNAL(mouseIsLeft()), this, SLOT(HideSidePanel()));

    ui->sidePanelStatuscheckBox->setText(TXT_SIDEPANEL_STATUS_CHECK_BOX);
    this->statusBar()->showMessage(TXT_NOT_CONNECTED);
    USE_STYLE(eCurrentStyle)
    defaultGeometry = this->geometry();
    UpdateSizes(defaultGeometry.width(),defaultGeometry.height());

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
        emit SizeChanged(this->size().width(),this->size().height());
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
        connect(_membersListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),this ,SLOT(AddNewObjectClicked(const EListType)));
        connect(this, SIGNAL(SizeChanged(int,int)),_membersListForm ,SLOT(OnSizeChange(const int, const int)));
        emit SizeChanged(this->size().width(),this->size().height());
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
        connect(this, SIGNAL(SizeChanged(int,int)),_usersListForm ,SLOT(OnSizeChange(const int, const int)));
        emit SizeChanged(this->size().width(),this->size().height());
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
        connect(this, SIGNAL(SizeChanged(int,int)),_experimentsListForm ,SLOT(OnSizeChange(const int, const int)));
        emit SizeChanged(this->size().width(),this->size().height());
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
        connect(this, SIGNAL(SizeChanged(int,int)),_appointmentsListForm ,SLOT(OnSizeChange(const int, const int)));
        emit SizeChanged(this->size().width(),this->size().height());
    }
    ui->widget->hide();
    ShowAppointmentsList();
}

void MainWindow::ShowGroupsListClicked()
{
    HideAll();
    if(!hasGroupsListForm)
    {
        IntializeGroupsListForm(ui->mainWidget);
        //connect(_appointmentsListForm, SIGNAL(NewObjectIsReadyToAdd(EListType)),this ,SLOT(AddNewObjectClicked(const EListType)));
        connect(this, SIGNAL(SizeChanged(int,int)),_groupsListForm ,SLOT(OnSizeChange(const int, const int)));
        emit SizeChanged(this->size().width(),this->size().height());
    }
    ui->widget->hide();
    ShowGroupsList();
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
    if ((this->isFullScreen()))
    {
        return;
    }
    ui->actionResetSize->setEnabled(true);
    int height = event->size().height();
    int width = event->size().width();
    UpdateSizes(width,height);
}

void MainWindow::ResetToOriginalSize()
{
    this->showNormal();
    int height = defaultGeometry.height();
    int width = defaultGeometry.width();
    this->resize(defaultGeometry.width(),defaultGeometry.height());
    UpdateSizes(width,height);
    ui->actionResetSize->setEnabled(false);
}

void MainWindow::SetToFullScreen()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    UpdateSizes(width,height);
    this->showFullScreen();
}

void MainWindow::UpdateSizes(int w, int h)
{
    QString style = this->styleSheet();
    style += QString("QWidget {font: 75 %1pt  TeX Gyre Schola;}").arg(0.01*w);
    this->setStyleSheet(style);
    ui->mainWidget->setGeometry(0.14*w, 10 , MAIN_WIDGET_WIDTH_RATIO*w , MAIN_WIDGET_HEIGHT_RATIO*h);
    ui->sideToolBoxWidget->setGeometry(10,10,0.12*w,0.8*h);
    ui->sidePanelStatuscheckBox->setGeometry(10,0.85*h,250,40);
    emit SizeChanged(w,h);
}

void MainWindow::on_actionResetSize_triggered()
{
    ResetToOriginalSize();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
//    QPixmap map(100,100);


//    QPainter Painter(this);

//    Painter.fillRect(event->rect(), QBrush(QColor(64, 32, 64)));
//    using namespace qrcodegen;
//    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText("https://google.com", qrcodegen::QrCode::Ecc::MEDIUM);

//    Painter.scale(5,5);
//Painter.setBackground(QBrush(Qt::white));
//    for (int y = 0; y < qr.getSize(); y++) {
//        for (int x = 0; x < qr.getSize(); x++) {
//            int color = qr.getModule(x, y);  // 0 for white, 1 for black
//            if (color == 1) {Painter.setPen(QPen(Qt::black));}
//            else {
//               Painter.setPen(QPen(Qt::white));
//            }

//            Painter.drawPoint(QPoint(x+130,y+100));
//        }
//    }


}



void MainWindow::on_actionChat_triggered()
{
    if(HasChatWindow)
    {
        QIcon icon;
        icon.addFile(QString::fromUtf8(ICON_NO_CHAT_URL), QSize(), QIcon::Normal, QIcon::Off);
        ui->actionChat->setIcon(icon);
        HasChatWindow = !HasChatWindow;
        ShowChatWindow();
    }
    else
    {
        QIcon icon;
        icon.addFile(QString::fromUtf8(ICON_CHAT_URL), QSize(), QIcon::Normal, QIcon::Off);
        ui->actionChat->setIcon(icon);
        HasChatWindow = !HasChatWindow;
        HideChatWindow();
    }

}


void MainWindow::on_OpenWebSiteButton_clicked()
{
    QString link = "https://www.tosson.net";
    QDesktopServices::openUrl(QUrl(link));
}
