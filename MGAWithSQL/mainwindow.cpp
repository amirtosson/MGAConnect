#include "mainwindow.h"
//#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    USE_STYLE(eCurrentStyle)

    SetCurrentMainWindowInstanceControls(this);
    if(!IntializeMGAServer() || !IntializeChatDialog(this) || !IntializeSidePanel(sideToolBoxWidget) || !IntializeChatbot()) return;
    serverDisconnectedButton = new QToolButton();
    QPixmap pixmap(QPixmap(ICON_DISCONNECTED_URL).scaledToHeight(MGAMainWindowView::statusBar->height()));
    serverDisconnectedButton->setIcon(pixmap);
    serverDisconnectedButton->setIconSize(QSize(30, 30));

    MGAMainWindowView::statusBar->addWidget(serverDisconnectedButton);
    menuStart = _mgaServer->GetDisconnectecdPopubServerMenu(serverDisconnectedButton);
    connect(serverDisconnectedButton,SIGNAL(clicked(bool)),menuStart,SLOT(show()));


    connect(this, SIGNAL(SizeChanged(int,int)),_sidePanal ,SLOT(OnSizeChange(const int, const int)));
    connect(sideToolBoxWidget ,SIGNAL(mouseIsOver()), this, SLOT(ShowSidePanel()));
    connect(sideToolBoxWidget ,SIGNAL(mouseIsLeft()), this, SLOT(HideSidePanel()));

    sidePanelStatuscheckBox->setText(TXT_SIDEPANEL_STATUS_CHECK_BOX);
    MGAMainWindowView::statusBar->showMessage(TXT_NOT_CONNECTED);

    defaultGeometry = this->geometry();
    UpdateSizes(defaultGeometry.width(),defaultGeometry.height());
    this->showNormal();

    if(_mgaServer->ServerParametersAreSaved())
    {
        ServerSetupChanged(false);
    }
    else
    {
        if (!IntializeSetupDialog(this)) return;
    }

    menuStart->popup(mapToGlobal(MGAMainWindowView::centralWidget->geometry().bottomRight()
                                 - QPoint(menuStart->width(),0)
                                 - QPoint(serverDisconnectedButton->width(),serverDisconnectedButton->height())
                                 ));
    menuStart->hide();
}

MainWindow::~MainWindow()
{
    //delete ui;
    Clean();

}


void MainWindow::DBConnectionSetUpClicked()
{
    HideAll();
    if(!hasDBForm)
    {
        IntializeDBConnectionForm(mainWidget);
        emit SizeChanged(this->size().width(),this->size().height());
    }
    widget->hide();
    _dbForm->show();
}

void MainWindow::ShowMemberListClicked()
{
    HideAll();
    if(!hasMembersListForm)
    {
        IntializeMembersListForm(mainWidget);
        emit SizeChanged(this->size().width(),this->size().height());
    }
    widget->hide();
    ShowMembersList();
}

void MainWindow::ShowDatabasesListClicked()
{
    HideAll();
    if(!hasDatabasesListForm)
    {
        IntializeDatabasesListForm(mainWidget);
    }
     widget->hide();
    ShowDatabasesList();
}

void MainWindow::ShowUserListClicked()
{
    HideAll();
    if(!hasUsersListForm)
    {
        IntializeUsersListForm(mainWidget);
        emit SizeChanged(this->size().width(),this->size().height());
    }
    widget->hide();
    ShowUsersList();
}

void MainWindow::ShowExperimentsListClicked()
{
    HideAll();
    if(!hasExpListForm)
    {
        IntializeExperimentsListForm(mainWidget);
        emit SizeChanged(this->size().width(),this->size().height());
    }
    widget->hide();
    ShowExperimentsList();
}

void MainWindow::ShowAppointmentsListClicked()
{
    HideAll();
    if(!hasAppointListForm)
    {
        IntializeAppointmentsListForm(mainWidget);
        emit SizeChanged(this->size().width(),this->size().height());
    }
    widget->hide();
    ShowAppointmentsList();
}

void MainWindow::ShowGroupsListClicked()
{
    HideAll();
    if(!hasGroupsListForm)
    {
        IntializeGroupsListForm(mainWidget);
        emit SizeChanged(this->size().width(),this->size().height());
    }
    widget->hide();
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
    MGAMainWindowView::statusBar->showMessage(TXT_CONNECTED);
    SetLoginUserRole();
    //TODO: check
    QMessageBox::information(this, tr(TXT_INFORMATION),QString(TXT_CONNECTED_PRIV).arg( _dbForm->GetCurrentUserRoleName()));
}

void MainWindow::DatabaseNotConnected()
{
    MGAMainWindowView::statusBar->showMessage(TXT_NOT_CONNECTED);
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

void MainWindow::ServerSetupChanged(bool bSaving)
{
    if (bSaving)SaveServerParametersAsSetting();


    if (IntializeSeverConnections())
    {
        QMessageBox::information(this, TXT_SERVER_MSG_BOX_LABEL, TXT_MSG_BOX_SERVER_IS_CONNECTED,
                                                  QMessageBox::Ok);
        MGAMainWindowView::statusBar->showMessage(TXT_CONNECTED);
        serverDisconnectedButton->hide();
        label2 = new QToolButton();
        QPixmap pixmap(QPixmap(ICON_CONNECTED_URL).scaledToHeight(MGAMainWindowView::statusBar->height()));
        label2->setIcon(pixmap);
        label2->setIconSize(QSize(30, 30));
        MGAMainWindowView::statusBar->addWidget(label2);
        label2->show();
        menuStart = _mgaServer->GetConnectecdPopubServerMenu(label2);

        connect(label2,SIGNAL(clicked(bool)),menuStart,SLOT(show()));
        menuStart->popup(mapToGlobal(MGAMainWindowView::centralWidget->geometry().bottomRight()
                                     - QPoint(menuStart->width(),0)
                                     - QPoint(label2->width(),label2->height())
                                     ));
        menuStart->hide();

    }
    else
    {
        QMessageBox::warning(this, TXT_SERVER_MSG_BOX_LABEL, TXT_MSG_BOX_SERVER_NO_CONNECTIONS,
                                                  QMessageBox::Ok);
    }
    if (bSaving)_setupForm->close();
}


void MainWindow::on_actionOptions_triggered()
{
    HideAll();
    if(!hasOptionForm)
    {
        hasOptionForm = IntializeOptionsForm(mainWidget);
    }
    widget->hide();
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
    actionResetSize->setEnabled(true);
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
    actionResetSize->setEnabled(false);
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
    mainWidget->setGeometry(0.14*w, 10 , MAIN_WIDGET_WIDTH_RATIO*w , MAIN_WIDGET_HEIGHT_RATIO*h);
    sideToolBoxWidget->setGeometry(10,10,0.12*w,0.8*h);
    sidePanelStatuscheckBox->setGeometry(10,0.8*h,250,40);
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
        actionChat->setIcon(icon);
        HasChatWindow = !HasChatWindow;
        ShowChatWindow();
    }
    else
    {
        QIcon icon;
        icon.addFile(QString::fromUtf8(ICON_CHAT_URL), QSize(), QIcon::Normal, QIcon::Off);
        actionChat->setIcon(icon);
        HasChatWindow = !HasChatWindow;
        HideChatWindow();
    }

}


void MainWindow::on_OpenWebSiteButton_clicked()
{
    QString link = "https://www.tosson.net";
    QDesktopServices::openUrl(QUrl(link));
}
