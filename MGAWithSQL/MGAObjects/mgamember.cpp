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
    QTableWidgetItem *workingByItem = new QTableWidgetItem();
    *workingByItem =  sWorkingBy.GetAsQTableWidgitItem();
    table->setItem(row,2,  workingByItem);
    QTableWidgetItem *joinAtItem = new QTableWidgetItem();
    *joinAtItem =  sJoinAt.GetAsQTableWidgitItem();
    table->setItem(row,3,  joinAtItem);
    QTableWidgetItem *eMailItem =  new QTableWidgetItem();
    *eMailItem =  sEMail.GetAsQTableWidgitItem();
    table->setItem(row,4,  eMailItem);
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

void MGAMember::SetsWorkingBy(std::string &workingby)
{
    sWorkingBy.SetFromSTDString(workingby);
}

void MGAMember::SetID(unsigned int &id)
{
    memberID = id;
}


void MGAMember::SetEMail(std::string &email)
{
    sEMail.SetFromSTDString(email);
}

void MGAMember::SetJoinAt(std::string &joinat)
{
    sJoinAt.SetFromSTDString(joinat);
}

void MGAMember::Print()
{
    sEMail.PrintString();
    sWorkingBy.PrintString();
    sLastName.PrintString();
    sFirstName.PrintString();
}


