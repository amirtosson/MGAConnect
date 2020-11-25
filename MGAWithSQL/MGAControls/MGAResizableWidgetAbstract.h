#ifndef MGARESIZABLEWIDGETABSTRACT_H
#define MGARESIZABLEWIDGETABSTRACT_H
#include <QWidget>

// GUI Components size ratio
//Side panel
#define SIDE_PANEL_WIDTH_RATIO                  0.111
#define SIDE_PANEL_HEIGHT_RATIO                 0.571
#define SIDE_PANEL_BUTTON_HEIGHT_RATIO          0.2
#define SIDE_PANEL_ICON_RATIO                   0.1


// Main widget
#define MAIN_WIDGET_WIDTH_RATIO                 0.6
#define MAIN_WIDGET_HEIGHT_RATIO                0.7

// DBFormWidGet
#define DB_FORM_BUTTON_WIDTH_RATIO              0.43
#define DB_FORM_BUTTON_HEIGHT_RATIO             0.1
#define DB_FORM_ENTRIES_WIDTH_RATIO             0.80
#define DB_FORM_ENTRIES_HEIGHT_RATIO            0.5
#define DB_FORM_DB_ICON_WIDTH_RATIO             0.16
#define DB_FORM_DB_ICON_HEIGHT_RATIO            0.19
#define DB_FORM_ICON_RATIO                      0.06
#define DB_FORM_60PX_MARGIN                     60


// list form WidGet
#define TABLE_VIEW_WIDTH_RATIO                  0.78
#define TABLE_VIEW_ICON_RATIO                   0.05

class MGAResizableWidget
{

public:
    virtual void UpdateSizes(int w, int h)=0;
    virtual void SetIconSize(int h)=0;

public slots:
    virtual void OnSizeChange(int w, int h)=0;
};


#endif // MGARESIZABLEWIDGETABSTRACT_H
