#ifndef MAINWINDOWSTYLE_H
#define MAINWINDOWSTYLE_H
#include <QString>

enum EMGAStyle
{
    eDarkStyle,
    eBrightStyle,
    eDefaultStyle
};

#define USE_STYLE(e)\
        this->setStyleSheet("");\
        if(e == eDarkStyle){USE_DARK_THEME};\
        if (e == eBrightStyle){USE_BRIGHT_THEME}\


#define USE_DARK_THEME\
        QString style = QString(WIDGET_DARK_STYLE)\
        + QString(PUSH_BUTTON_DARK_STYLE)\
        + QString(TOOLBAR_DARK_STYLE)\
        + QString(CHECKBOX_DARK_STYLE)\
        + QString(TABLE_DARK_STYLE)\
        + QString(COMBOBOX_DARK_STYLE);\
        this->setStyleSheet(style);\

#define USE_BRIGHT_THEME\
        QString str = QString(WIDGET_BRIGHT_STYLE)\
        + QString(PUSH_BUTTON_BRIGHT_STYLE)\
        + QString(TOOLBAR_BRIGHT_STYLE) ;\
        this->setStyleSheet(str);\

#pragma region DARK_STYLE

#define WIDGET_DARK_STYLE\
        "QWidget { background-color: rgb(65, 65, 65);\
        color: white;\
        selection-background-color: transparent;}"\

#define PUSH_BUTTON_DARK_STYLE\
        "QPushButton {font: 75 12pt  TeX Gyre Schola ;\
        background-color: rgb(0, 0, 0);\
        color: white;\
        text-align: center;\
        selection-background-color: transparent;}\
        QPushButton:pressed {background-color: rgb(0, 0, 103);}\
        QPushButton:disabled {background-color:rgb(50, 50, 50);color:rgb(108, 108, 108);}\
        QPushButton:focus {border: none; outline: none;}"\

#define TOOLBAR_DARK_STYLE\
        "QToolBar:active {background-color: rgb(0, 0, 103);}"\

#define COMBOBOX_DARK_STYLE\
        "QComboBox {color: white;}\
        QComboBox:focus {border: none; outline: none;}"\

#define CHECKBOX_DARK_STYLE\
        "QCheckBox:indicator:checked {background-color: none;}\
        QCheckBox:focus {border: none; outline: none;}"\

#define TABLE_DARK_STYLE\
        "QHeaderView::section { background-color:black; }"

#pragma endregion


    //TODO: make the design
#pragma region Bright_STYLE

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

#pragma endregion


#endif // MAINWINDOWSTYLE_H
