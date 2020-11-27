#ifndef MGAAPPOINTMENT_H
#define MGAAPPOINTMENT_H
#include "mgastring.h"


class MGAAppointment
{
public:
    MGAAppointment();
    bool ShowInQTalbeRow(QTableWidget *table, int row);
    //Setter
    void SetGuests(std::string &guests);
    void SetDescription(std::string &description);
    void SetStartTime(std::string &starttime);
    void SetAppointID(unsigned int &id);
    void SetEndTime(std::string &endtime);


private:
    unsigned int appointID;
    MGAString sGuests;
    MGAString sDescription;
    //TODO: implement date class
    MGAString sStartTime;
    MGAString sEndTime;

};


#endif // MGAAPPOINTMENT_H
