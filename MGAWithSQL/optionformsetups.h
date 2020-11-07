#ifndef OPTIONFORMSETUPS_H
#define OPTIONFORMSETUPS_H
#include "optionformresources.h"
#include <QRect>
#include <QRegion>



#define SET_OPTION_FORM_STYLE\
        this->setStyleSheet("");\
        this->setStyleSheet(BUTTON_ROUNDED_EDGES);\
        ui->StylegroupBox->setHidden(true);\
        FIRST_BUTTON_SETUP

#define BACK_TO_DEFAULT\
        ui->StylegroupBox->setHidden(true);\
        ui->firstButton->setGeometry(30,100,90,70);\
        ui->secondButton->setGeometry(30,100,90,70);\
        ui->thirdButton->setGeometry(30,100,90,70);\

#define BUTTON_ROUNDED_EDGES\
        "QPushButton { border-radius:10px;}"

#define FIRST_BUTTON_SETUP\
        ui->firstButton->setStyleSheet(IMG_THEME);


#define MOUSE_ON_OPTION_BUTTON(V)\
        if(ui->StylegroupBox->isHidden())\
        {V->setGeometry(30,100,110,100);}

#define MOUSE_LEFT_OPTION_BUTTON(V)\
        if(ui->StylegroupBox->isHidden())\
        {V->setGeometry(30,100,90,70);}

#define SETUP_CONNECTIONS\
        connect(ui->firstWidget ,SIGNAL(mouseIsOver()), this, SLOT(MouseOnFirstBtn()));\
        connect(ui->firstWidget ,SIGNAL(mouseIsLeft()), this, SLOT(MouseLeftFirstBtn()));\
        connect(ui->secondWidget,SIGNAL(mouseIsOver()), this, SLOT(MouseOnSecondBtn()));\
        connect(ui->secondWidget,SIGNAL(mouseIsLeft()), this, SLOT(MouseLeftSecondBtn()));\
        connect(ui->thirdWidget ,SIGNAL(mouseIsOver()), this, SLOT(MouseOnThirdBtn()));\
        connect(ui->thirdWidget ,SIGNAL(mouseIsLeft()), this, SLOT(MouseLeftThirdBtn()));


#define SET_STYLE_CHANGING_GROUP\
        ui->StylegroupBox->setVisible(true);\
        QStringList styleList;\
        styleList.append(TXT_DARK_STYLE);\
        styleList.append(TXT_BRIGHT_STYLE);\
        styleList.append(TXT_DEFAULT_STYLE);\
        ui->styleComboBox->clear();\
        ui->styleComboBox->addItems(styleList);


#endif // OPTIONFORMSETUPS_H
