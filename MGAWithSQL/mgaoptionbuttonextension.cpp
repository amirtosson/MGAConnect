#include "mgaoptionbuttonextension.h"

MGAOptionButtonExtension::MGAOptionButtonExtension(QWidget *parent) : QWidget(parent)
{

}

void MGAOptionButtonExtension::MouseIsOver(QPushButton *btn)
{
    btn->setGeometry(30,100,100,150);
}
