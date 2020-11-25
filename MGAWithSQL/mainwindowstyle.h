
#include <QString>

#define USE_STYLE(e)\
        this->setStyleSheet("");\
        if(e == eDarkStyle)\
        {\
            QFile file(STYLE_DARK_FILE_URL);\
            file.open(QFile::ReadOnly | QFile::Text);\
            QTextStream stream(&file);\
            QString s = stream.readAll();\
            this->setStyleSheet(s);\
            ui->mainWidget->setStyleSheet(QString("QWidget { background-color: rgb(50,50, 50); color: white; selection-background-color: transparent;} QPushButton:focus {outline: none;}") );\
        }\
        else if (e == eBrightStyle)\
        {\
            QFile file(STYLE_BREEZE_FILE_URL);\
            file.open(QFile::ReadOnly | QFile::Text);\
            QTextStream stream(&file);\
            QString s = stream.readAll();\
            this->setStyleSheet(s);\
            ui->mainWidget->setStyleSheet(QString("QWidget { background-color: rgb(153, 153, 150); color: white; selection-background-color: transparent;} QPushButton:focus {outline: none;}") );\
        };
