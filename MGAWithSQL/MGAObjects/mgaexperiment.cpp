#include "mgaexperiment.h"

MGAExperiment::MGAExperiment()
{

}

bool MGAExperiment::ShowInQTalbeRow(QTableWidget *table, int row)
{
    QTableWidgetItem *FaciltyNameItem = new QTableWidgetItem();
    *FaciltyNameItem =  sFaciltyName.GetAsQTableWidgitItem();
    table->setItem(row,0, FaciltyNameItem);
    QTableWidgetItem *StartTimeItem = new QTableWidgetItem();
    *StartTimeItem =  sStartTime.GetAsQTableWidgitItem();
    table->setItem(row,1,  StartTimeItem);
    QTableWidgetItem *EndTimeItem = new QTableWidgetItem();
    *EndTimeItem =  sEndTime.GetAsQTableWidgitItem();
    table->setItem(row,2,  EndTimeItem);
    QTableWidgetItem *DescriptionItem = new QTableWidgetItem();;
    *DescriptionItem =  sDescription.GetAsQTableWidgitItem();
    table->setItem(row,3, DescriptionItem);
    return true;
}

void MGAExperiment::SetFaciltyName(std::string &faciltyname)
{
    sFaciltyName.SetFromSTDString(faciltyname);
}

void MGAExperiment::SetDescription(std::string &description)
{
    sDescription.SetFromSTDString(description);
}

void MGAExperiment::SetStartTime(std::string &starttime)
{
    sStartTime.SetFromSTDString(starttime);
}

void MGAExperiment::SetExpID(unsigned int &id)
{
   expID =  id;
}

void MGAExperiment::SetEndTime(std::string &endtime)
{
    sEndTime.SetFromSTDString(endtime);
}
