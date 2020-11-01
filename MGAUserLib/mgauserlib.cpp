#include "mgauserlib.h"


MGAUser::MGAUser()
{


}

bool MGAUser::ShowInQTalbeRow(QTableWidget *table, int colNum, int row)
{
    for(int i = 0; i< colNum; ++i)
    {
        table->setItem(row,i,&item[i]);
    }
    return true;
}
