#include "mgamember.h"


MGAMember::MGAMember()
{


}

bool MGAMember::ShowInQTalbeRow(QTableWidget *table, int row)
{
    QTableWidgetItem *firstNameItem = new QTableWidgetItem();
    *firstNameItem =  sFirstName.GetAsQTableWidgitItem();
    table->setItem(row,0, firstNameItem);
    QTableWidgetItem *lastNameItem = new QTableWidgetItem();;
    *lastNameItem =  sLastName.GetAsQTableWidgitItem();
    table->setItem(row,1, lastNameItem);
    QTableWidgetItem *universityNameItem = new QTableWidgetItem();
    *universityNameItem =  sUniversityName.GetAsQTableWidgitItem();
    table->setItem(row,2,  universityNameItem);
    QTableWidgetItem *eMailItem =  new QTableWidgetItem();
    *eMailItem =  sEMail.GetAsQTableWidgitItem();
    table->setItem(row,3,  eMailItem);
    return true;
}

void MGAMember::SetFirstName(std::string &firstname)
{
    sFirstName.SetFromSTDString(firstname);
}

void MGAMember::SetLastName(std::string &lastname)
{
    sLastName.SetFromSTDString(lastname);
}

void MGAMember::SetUsnivesityName(std::string &university)
{
    sUniversityName.SetFromSTDString(university);
}

void MGAMember::SetEMail(std::string &email)
{
    sEMail.SetFromSTDString(email);
}

void MGAMember::Print()
{
    sEMail.PrintString();
    sUniversityName.PrintString();
    sLastName.PrintString();
    sFirstName.PrintString();
}


