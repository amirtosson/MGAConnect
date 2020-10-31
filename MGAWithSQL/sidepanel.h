#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QWidget>
#include "mgasidepanelstyle.h"
#include "sidepanelsetups.h"
#include <QPixmap>
#include <QIcon>

namespace Ui {
class SidePanel;
}

class SidePanel : public QWidget
{
    Q_OBJECT

public:
    explicit SidePanel(QWidget *parent = 0);
    ~SidePanel();

private slots:
    void on_dbConnectBtn_clicked();
    void DatabaseIsConnected();
    void DatabaseIsDisconnected();

signals:
    void DBCOnnectionButtonClicked();

private:
    Ui::SidePanel *sidePanelUi;
};

#endif // SIDEPANEL_H
