#include "mgauser.h"


MGAUser::MGAUser()
{


}

bool MGAUser::ShowInQTalbeRow(QTableWidget *table, int row)
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

void MGAUser::SetFirstName(std::string &firstname)
{
    sFirstName.SetFromSTDString(firstname);
}

void MGAUser::SetLastName(std::string &lastname)
{
    sLastName.SetFromSTDString(lastname);
}

void MGAUser::SetUsnivesityName(std::string &university)
{
    sUniversityName.SetFromSTDString(university);
}

void MGAUser::SetEMail(std::__cxx11::string &email)
{
    sEMail.SetFromSTDString(email);
}

void MGAUser::Print()
{
    sEMail.PrintString();
    sUniversityName.PrintString();
    sLastName.PrintString();
    sFirstName.PrintString();
}


