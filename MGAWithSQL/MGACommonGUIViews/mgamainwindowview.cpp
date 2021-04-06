#include "mgamainwindowview.h"

MGAMainWindowView::MGAMainWindowView(QWidget *parent)
{

}

void MGAMainWindowView::setupUi(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->setEnabled(true);
    MainWindow->resize(900, 700);
    MainWindow->setMinimumSize(QSize(900, 700));
    QPalette palette;
    QBrush brush(QColor(88, 88, 88, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
    MainWindow->setPalette(palette);
    MainWindow->setMouseTracking(true);
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/logos/Resources/Images/connectIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    MainWindow->setWindowIcon(icon);
    MainWindow->setWindowOpacity(1.000000000000000);
    MainWindow->setStyleSheet(QString::fromUtf8(""));
    MainWindow->setUnifiedTitleAndToolBarOnMac(true);
    actionOptions = new QAction(MainWindow);
    actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionOptions->setIcon(icon1);
    actionExit = new QAction(MainWindow);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionExit->setIcon(icon2);
    actionFullScreen = new QAction(MainWindow);
    actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
    QIcon icon3;
    icon3.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/fit.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionFullScreen->setIcon(icon3);
    actionResetSize = new QAction(MainWindow);
    actionResetSize->setObjectName(QString::fromUtf8("actionResetSize"));
    actionResetSize->setEnabled(false);
    QIcon icon4;
    icon4.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/resetsize.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionResetSize->setIcon(icon4);
    actionChat = new QAction(MainWindow);
    actionChat->setObjectName(QString::fromUtf8("actionChat"));
    QIcon icon5;
    icon5.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/nochat.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionChat->setIcon(icon5);
    actionserverAction = new QAction(MainWindow);
    actionserverAction->setObjectName(QString::fromUtf8("actionserverAction"));
    QIcon icon6;
    icon6.addFile(QString::fromUtf8(":/server/Resources/Icons/serverdisconnected.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionserverAction->setIcon(icon6);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    centralWidget->setLayoutDirection(Qt::LeftToRight);
    mainWidget = new QWidget(centralWidget);
    mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
    mainWidget->setGeometry(QRect(130, 10, 640, 551));
    mainWidget->setMinimumSize(QSize(640, 450));
    mainWidget->setStyleSheet(QString::fromUtf8(""));
    widget = new QWidget(mainWidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(9, 9, 622, 451));
    widget->setStyleSheet(QString::fromUtf8(""));
    OpenWebSiteButton = new QToolButton(widget);
    OpenWebSiteButton->setObjectName(QString::fromUtf8("OpenWebSiteButton"));
    OpenWebSiteButton->setGeometry(QRect(170, 220, 100, 100));
    OpenWebSiteButton->setMinimumSize(QSize(100, 100));
    OpenWebSiteButton->setCursor(QCursor(Qt::PointingHandCursor));
#if QT_CONFIG(tooltip)
    OpenWebSiteButton->setToolTip(QString::fromUtf8("Go To Website"));
#endif // QT_CONFIG(tooltip)
    OpenWebSiteButton->setToolTipDuration(5);
    OpenWebSiteButton->setStyleSheet(QString::fromUtf8(""));
    MGAWelcomeLabel = new QLabel(widget);
    MGAWelcomeLabel->setObjectName(QString::fromUtf8("MGAWelcomeLabel"));
    MGAWelcomeLabel->setGeometry(QRect(290, 260, 201, 41));
    QFont font;
    font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
    font.setPointSize(14);
    font.setBold(false);
    font.setItalic(false);
    font.setUnderline(false);
    font.setWeight(9);
    font.setStrikeOut(false);
    font.setKerning(true);
    MGAWelcomeLabel->setFont(font);
    MGAWelcomeLabel->setContextMenuPolicy(Qt::DefaultContextMenu);
    MGAWelcomeLabel->setLayoutDirection(Qt::RightToLeft);
    MGAWelcomeLabel->setStyleSheet(QString::fromUtf8("font: 75 14pt \"MS Shell Dlg 2\";"));
    MGAWelcomeLabel->setTextFormat(Qt::AutoText);
    MGAWelcomeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
    MGAWelcomeLabel->setWordWrap(true);
    MGAWelcomeLabel->setMargin(3);
    MGAWelcomeLabel->setIndent(8);
    MGAWelcomeLabel->setOpenExternalLinks(false);
    MGAWelcomeLabel->setTextInteractionFlags(Qt::NoTextInteraction);
    sideToolBoxWidget = new MGAWidgetExtension(centralWidget);
    sideToolBoxWidget->setObjectName(QString::fromUtf8("sideToolBoxWidget"));
    sideToolBoxWidget->setGeometry(QRect(10, 10, 120, 551));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(sideToolBoxWidget->sizePolicy().hasHeightForWidth());
    sideToolBoxWidget->setSizePolicy(sizePolicy);
    sideToolBoxWidget->setBaseSize(QSize(10, 10));
    QPalette palette1;
    QBrush brush1(QColor(81, 81, 81, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    sideToolBoxWidget->setPalette(palette1);
    sideToolBoxWidget->setMouseTracking(true);
    sideToolBoxWidget->setAutoFillBackground(true);
    sideToolBoxWidget->setStyleSheet(QString::fromUtf8(""));
    sidePanelStatuscheckBox = new QCheckBox(centralWidget);
    sidePanelStatuscheckBox->setObjectName(QString::fromUtf8("sidePanelStatuscheckBox"));
    sidePanelStatuscheckBox->setGeometry(QRect(20, 580, 151, 23));
    sidePanelStatuscheckBox->setTristate(false);
    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 900, 20));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    mainToolBar->setEnabled(true);
    mainToolBar->setLayoutDirection(Qt::RightToLeft);
    mainToolBar->setStyleSheet(QString::fromUtf8(""));
    mainToolBar->setMovable(true);
    mainToolBar->setAllowedAreas(Qt::RightToolBarArea|Qt::TopToolBarArea);
    mainToolBar->setFloatable(false);
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    statusBar->setLayoutDirection(Qt::RightToLeft);
    MainWindow->setStatusBar(statusBar);

    mainToolBar->addAction(actionFullScreen);
    mainToolBar->addAction(actionOptions);
    mainToolBar->addAction(actionExit);
    mainToolBar->addAction(actionChat);
    mainToolBar->addAction(actionResetSize);

    MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MGAConnect", nullptr));
#if QT_CONFIG(tooltip)
    MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
    actionOptions->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    actionFullScreen->setText(QCoreApplication::translate("MainWindow", "FullScreen", nullptr));
    actionResetSize->setText(QCoreApplication::translate("MainWindow", "ResetSize", nullptr));
#if QT_CONFIG(tooltip)
    actionResetSize->setToolTip(QCoreApplication::translate("MainWindow", "Back to the original size", nullptr));
#endif // QT_CONFIG(tooltip)
    actionChat->setText(QCoreApplication::translate("MainWindow", "Chat", nullptr));
    actionserverAction->setText(QCoreApplication::translate("MainWindow", "serverAction", nullptr));
#if QT_CONFIG(whatsthis)
    OpenWebSiteButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
    OpenWebSiteButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    MGAWelcomeLabel->setText(QCoreApplication::translate("MainWindow", " TossonLab production", nullptr));
    sidePanelStatuscheckBox->setText(QString());

    QMetaObject::connectSlotsByName(MainWindow);
}

