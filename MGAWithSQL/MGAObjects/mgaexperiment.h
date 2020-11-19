#ifndef MGAEXPERIMENT_H
#define MGAEXPERIMENT_H
#include "mgastring.h"

class MGAExperiment
{
public:
    MGAExperiment();
    bool ShowInQTalbeRow(QTableWidget *table, int row);
    //Setter
    void SetFaciltyName(std::string &faciltyname);
    void SetDescription(std::string &description);
    void SetStartTime(std::string &starttime);
    void SetExpID(unsigned int &id);
    void SetEndTime(std::string &endtime);


private:
    unsigned int expID;
    MGAString sFaciltyName;
    MGAString sDescription;
    //TODO: implement data class
    MGAString sStartTime;
    MGAString sEndTime;

};

#endif // MGAEXPERIMENT_H
