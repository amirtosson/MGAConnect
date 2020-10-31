#include "mgawidgetextension.h"

MGAWidgetExtension::MGAWidgetExtension(QWidget *parent) : QWidget(parent)
{

}

void MGAWidgetExtension::mouseMoveEvent(QMouseEvent *e)
{
    emit mouseIsOver();
}

void MGAWidgetExtension::leaveEvent(QEvent *)
{
    emit mouseIsLeft();
}


