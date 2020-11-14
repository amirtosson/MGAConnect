#include "mgastring.h"


MGAString::MGAString()
{
}

MGAString::MGAString(QString *qStr)
{
    sMainString = qStr->toStdString();
}

void MGAString::operator=(QString *qStr)
{
    sMainString = qStr->toStdString();
}

void MGAString::operator=(std::string *str)
{
    sMainString = *str;
}

MGAString::MGAString(std::string str)
{

}

void MGAString::PrintString()
{
    qDebug()<< sMainString.c_str()<<endl;
}

void MGAString::SetFromQString(QString *qStr)
{
    sMainString = qStr->toStdString();
}

void MGAString::SetFromSTDString(std::string str)
{
    sMainString = str;
}

bool MGAString::IsValidPwd()
{
    bool bIsValid = false;
    bIsValid = sMainString.size() > 0
               &HasNumbers();
    return bIsValid;
}

bool MGAString::IsValidDBName()
{
    return HasNumbers() ? false : true;
}

bool MGAString::IsValidUserName()
{
    bool bIsValidUN = true;
    if(HasNumbers() | HasSpecialChar())bIsValidUN= false;
    return bIsValidUN;
}

bool MGAString::HasNumbers()
{
    return (sMainString.find('0') != std::string::npos ||
        sMainString.find('1') != std::string::npos ||
        sMainString.find('2') != std::string::npos ||
        sMainString.find('3') != std::string::npos ||
        sMainString.find('4') != std::string::npos ||
        sMainString.find('5') != std::string::npos ||
        sMainString.find('6') != std::string::npos ||
        sMainString.find('7') != std::string::npos ||
        sMainString.find('8') != std::string::npos ||
            sMainString.find('9') != std::string::npos);
}

bool MGAString::HasSpecialChar()
{
    char cSC[6] ={'!','?','@','&','#','%'};
    bool bHasSC = false;
    for(int i = 0; i < 6; i++)
    {
       bHasSC |= sMainString.find(cSC[i]) != std::string::npos;
    }
    return bHasSC;
}

bool MGAString::IsEmpty()
{
    return (sMainString.size() > 0);
}

std::string MGAString::GetAsStdSting()
{
    return sMainString.c_str();
}

QString MGAString::GetAsQString()
{
    return QString(sMainString.c_str());
}

QTableWidgetItem MGAString::GetAsQTableWidgitItem()
{
    QTableWidgetItem item;
    item.setText(QString(sMainString.c_str()));
    return item;
}

