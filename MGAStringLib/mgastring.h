#ifndef MGASTRING_H
#define MGASTRING_H

#include <QString>
#include <QDebug>

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

    // setter
    void SetFromQString(QString *qStr);

    //operators overloading
public:
    void operator=(QString *qStr);
    void operator=(std::string *str);


private:
    std::string sMainString;
};

#endif // MGASTRINGLIB_H
