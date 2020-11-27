#include "mgaappointment.h"

MGAAppointment::MGAAppointment()
{

}

bool MGAAppointment::ShowInQTalbeRow(QTableWidget *table, int row)
{

    QTableWidgetItem *StartTimeItem = new QTableWidgetItem();
    *StartTimeItem =  sStartTime.GetAsQTableWidgitItem();
    table->setItem(row,0,  StartTimeItem);
    QTableWidgetItem *EndTimeItem = new QTableWidgetItem();
    *EndTimeItem =  sEndTime.GetAsQTableWidgitItem();
    table->setItem(row,1,  EndTimeItem);
    QTableWidgetItem *GuestsItem = new QTableWidgetItem();
    *GuestsItem =  sGuests.GetAsQTableWidgitItem();
    table->setItem(row,2, GuestsItem);
    QTableWidgetItem *DescriptionItem = new QTableWidgetItem();;
    *DescriptionItem =  sDescription.GetAsQTableWidgitItem();
    table->setItem(row,3, DescriptionItem);

    return true;
}

void MGAAppointment::SetGuests(std::string &guests)
{
    sGuests.SetFromSTDString(guests);

}

void MGAAppointment::SetDescription(std::string &description)
{
    sDescription.SetFromSTDString(description);

}

void MGAAppointment::SetStartTime(std::string &starttime)
{
    sStartTime.SetFromSTDString(starttime);
}

void MGAAppointment::SetAppointID(unsigned int &id)
{
    appointID =  id;

}

void MGAAppointment::SetEndTime(std::string &endtime)
{
    sEndTime.SetFromSTDString(endtime);

}
