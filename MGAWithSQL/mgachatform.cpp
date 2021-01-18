#include "mgachatform.h"
#include "ui_mgachatform.h"

MGAChatForm::MGAChatForm(QWidget *parent) :
    QWidget(parent),
    _mousePressed(false),
    _mousePosition(QPoint())
{
    setupUi(this);
    resizeBtn->setCursor(QCursor(Qt::ArrowCursor));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->setGeometry(screenGeometry.bottomRight().x() - 195,screenGeometry.bottomRight().y() - 115, 90,90);
    closedRect = this->geometry();
    openedRect.setRect(closedRect.bottomRight().x() - 300, closedRect.bottomRight().y()- 420, 305,400);
    HideBtns();
}

MGAChatForm::~MGAChatForm()
{
}

void MGAChatForm::mousePressEvent(QMouseEvent *e)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = true;
        _mousePosition = e->pos();
    }
}

void MGAChatForm::mouseMoveEvent(QMouseEvent *e)
{
    if ( _mousePressed ) {
        move( mapToParent( e->pos() - _mousePosition ) );
    }
}

void MGAChatForm::mouseReleaseEvent(QMouseEvent *e)
{
    this->setCursor(QCursor(Qt::OpenHandCursor));
    resizeBtn->setCursor(QCursor(Qt::ArrowCursor));
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = false;
        _mousePosition = QPoint();
    }
    // TODO: need to be adapted
    //closedRect.setBottomRight(this->geometry().bottomRight());
    //openedRect.setBottomRight(this->geometry().bottomRight());
}

void MGAChatForm::on_resizeBtn_clicked()
{
    if(this->height()<100)
    {
        this->setGeometry(openedRect);
        QIcon icon;
        icon.addFile(QString::fromUtf8(URL_COLLAPSE_ICON), QSize(), QIcon::Normal, QIcon::On);
        resizeBtn->setIcon(icon);
        ShowBtns();
    }
    else
    {
        this->resize(closedRect.width(),closedRect.height());
        QIcon icon;
        icon.addFile(QString::fromUtf8(URL_EXPAND_ICON), QSize(), QIcon::Normal, QIcon::On);
        resizeBtn->setIcon(icon);
        HideBtns();
        //this->showMinimized();
        //this->setGeometry(closedRect);
    }


}

void MGAChatForm::on_chatBotMGAChat_clicked()
{
    this->setWindowOpacity(0.5);
    this->setEnabled(false);
    _chatForm = new MGAChatMSGDialog();
    connect(_chatForm, SIGNAL(MSGBoxIsClosed()),this ,SLOT(NoMSGBoxIsOpened()));

    _chatForm->show();
}

void MGAChatForm::NoMSGBoxIsOpened()
{
    this->setEnabled(true);
    this->setWindowOpacity(1);
}

void MGAChatForm::HideBtns()
{
    closeBtn->setHidden(true);
    minimizeBtn->setHidden(true);
}

void MGAChatForm::ShowBtns()
{
    closeBtn->setHidden(false);
    minimizeBtn->setHidden(false);
}
