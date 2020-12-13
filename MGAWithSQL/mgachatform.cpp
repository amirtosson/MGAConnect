#include "mgachatform.h"
#include "ui_mgachatform.h"

MGAChatForm::MGAChatForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MGAChatForm),
    _mousePressed(false),
    _mousePosition(QPoint())
{
    ui->setupUi(this);
    ui->toolButton->setCursor(QCursor(Qt::ArrowCursor));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->setGeometry(screenGeometry.bottomRight().x() - 195,screenGeometry.bottomRight().y() - 115, 190,80);
    closedRect = this->geometry();

    openedRect.setRect(closedRect.bottomRight().x() - 300, closedRect.bottomRight().y()- 420, 300,400);

}

MGAChatForm::~MGAChatForm()
{
    delete ui;
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
    ui->toolButton->setCursor(QCursor(Qt::ArrowCursor));
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = false;
        _mousePosition = QPoint();
    }
    //closedRect.setBottomRight(this->geometry().bottomRight());
    //openedRect.setBottomRight(this->geometry().bottomRight());
}

void MGAChatForm::on_toolButton_clicked()
{
    if(this->height()<100)
    {
        this->setGeometry(openedRect);
    }
    else
    {
        this->setGeometry(closedRect);
    }


}
