#ifndef MGASTRING_H
#define MGASTRING_H

#include <QString>
#include <QDebug>
#include <QTableWidget>

class MGAString
{

public:
    //constructors
    MGAString();
    MGAString(QString *qStr);
    MGAString(std::string str);

    //public functions
    void PrintString();
    bool IsValidPwd();
    bool IsValidDBName();
    bool IsValidUserName();
    bool HasNumbers();
    bool HasSpecialChar();

    //getters
    std::string GetAsStdSting();
    QString GetAsQString();
    QTableWidgetItem GetAsQTableWidgitItem();


    // setter
    void SetFromQString(QString *qStr);
    void SetFromSTDString(std::string str);


    //operators overloading
public:
    void operator=(QString *qStr);
    void operator=(std::string *str);


private:
    std::string sMainString;
};

#endif // MGASTRINGLIB_H
