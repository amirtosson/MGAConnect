#ifndef MGANEWOBJECTFORMVIEW_H
#define MGANEWOBJECTFORMVIEW_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <vector>

#include "addnewobjectformresources.h"
#include "mgauserrolesenum.h"
#include "mgalistformtypesenum.h"

// GUI Components ration
#define ENTRIES_GRID_HEIGHT_RATIO               0.6
#define ENTRIES_WIDTH_RATIO                     0.80
#define ENTRIES_HEIGHT_RATIO                    0.15

#define EXTRA_COMPONENTS_HEIGHT_RATIO           0.1
#define EXTRA_COMPONENTS_WIDTH_RATIO            0.2

#define MARGIN_RATIO                            0.15





class MGANewObjectFormView
{

public:
    void setupUi(QDialog *AddNewObjectForm, EListType eList);
    //intialiyzation functions
    bool IntializeUserGUIComponents(QWidget *widget);
    bool IntializeMemberGUIComponents(QWidget *widget);
    bool IntializeExpGUIComponents(QWidget *widget);
    bool IntializeAppointGUIComponents(QWidget *widget);
    bool IntializeSetupGUIComponents(QWidget *widget);

    void ResizeComponents(int w, int h);
    QStringList GetLinesFields();
    int GetComboBoxValue();
    QString GetUserName();
    QString GetUserHost();
    QString GetUserPWD();
    QString GetUserRole();




public slots:
    virtual void on_OkButton_clicked() = 0;
    virtual void on_CancelButton_clicked() = 0;

protected:

    std::vector<QLabel*> componentsLabels;
    std::vector<QLineEdit*> componentsEditLines;
    QWidget *gridLayoutWidget = NULL;;
    QGridLayout *gridLayout = NULL;
    QComboBox *comboBox = NULL;
    QPushButton *okButton = NULL;
    QPushButton *cancelButton = NULL;
    QLabel *errorText = NULL;

protected:
    void SetupLabelsAndEditLines(const int labels, const int lines);


};



#endif // MGANEWOBJECTFORMVIEW_H
