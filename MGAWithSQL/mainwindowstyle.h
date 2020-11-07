
#include <QString>


#define USE_STYLE(e)\
        this->setStyleSheet("");\
        if(e == eDarkStyle){USE_DARK_THEME};\
        if (e == eBrightStyle){USE_BRIGHT_THEME}


#define USE_DARK_THEME\
        QString style = WIDGET_DARK_STYLE\
        TOOLBAR_DARK_STYLE\
        TABLE_DARK_STYLE\
        CHECKBOX_DARK_STYLE\
        TOOLBAR_DARK_STYLE\
        COMBOBOX_DARK_STYLE\
        DIALOG_DARK_STYLE\
        TOOL_BUTTON_DARK_STYLE\
        PUSH_BUTTON_DARK_STYLE;\
        this->setStyleSheet(style);\
        ui->mainWidget->setStyleSheet(QString("QWidget { background-color: rgb(50,50, 50); color: white; selection-background-color: transparent;} QPushButton:focus {outline: none;}") PUSH_BUTTON_DARK_STYLE);

#define USE_BRIGHT_THEME\
        QString str = QString(WIDGET_BRIGHT_STYLE)\
        + QString(PUSH_BUTTON_BRIGHT_STYLE)\
        + QString(TOOLBAR_BRIGHT_STYLE) ;\
        this->setStyleSheet(str);


#define WIDGET_DARK_STYLE\
          QString( "QWidget { background-color: rgb(30 , 30, 30); color: white; selection-background-color: transparent;} ")\

#define DIALOG_DARK_STYLE\
        + QString( "QDialod { background-color: rgb(30 , 30, 30); color: white; selection-background-color: transparent;} ")\


#define PUSH_BUTTON_DARK_STYLE\
        + QString(" QPushButton {font: 75 12pt  TeX Gyre Schola ; background-color:rgb(40, 40, 40); color: white; text-align: center; selection-background-color: transparent;} ")\
        + QString(" QPushButton:pressed {color: grey; background-color: rgb(50, 50, 50);}")\
        + QString(" QPushButton:disabled { color:rgb(118, 118, 118);} ")\
        + QString(" QPushButton:focus {outline: none;}")\
        + QString(" QPushButton:hover {border: 2px solid black; background-color: rgb(80, 80, 80);} ")\

#define TOOLBAR_DARK_STYLE\
        + QString( "QToolBar:active {background-color: rgb(30, 30, 30); border: 1px solid rgb(50, 50, 50);} ")\
        + QString( "QToolButton:hover { background-color: rgb(80, 80, 80);} ")\

#define COMBOBOX_DARK_STYLE\
        + QString( " QComboBox {color: white;} " ) \
        + QString( " QComboBox:focus {border: none; outline: none;} ")

#define CHECKBOX_DARK_STYLE\
        + QString( " QCheckBox:focus {border: none; outline: none;} ")

#define TABLE_DARK_STYLE\
        + QString( " QHeaderView::section { background-color:black; } ")\
        + QString( " QTableWidget::item:selected { background-color:black; } ")

#define TOOL_BUTTON_DARK_STYLE\
        + QString(" QToolButton {font: 75 12pt  TeX Gyre Schola ; background-color:rgb(40, 40, 40); color: white; text-align: center; selection-background-color: transparent;} ")\
        + QString(" QToolButton:pressed {color: grey; background-color: rgb(50, 50, 50);}")\
        + QString(" QToolButton:disabled { color:rgb(118, 118, 118);} ")\
        + QString(" QToolButton:focus {outline: none;}")\
        + QString(" QToolButton:hover {border: 2px solid black; background-color: rgb(80, 80, 80);} ")\


    //TODO: make the design

#define WIDGET_BRIGHT_STYLE\
        "QWidget { background-color: rgb(65, 65, 65);\
        color: white;}"

#define PUSH_BUTTON_BRIGHT_STYLE\
        "QPushButton:active {font: 75 12pt  TeX Gyre Schola ;\
        background-color: rgb(0, 0, 0);\
        color: white;\
        text-align: center;}\
        QPushButton:pressed {background-color: blue;}"\

#define TOOLBAR_BRIGHT_STYLE\
    "QToolBar:active {background-color: rgb(0, 0, 103);}"\


