#include "mainwindow.h"
#include "mgaconnectsplashscreendefinations.h"
#include "mgaconnectsplashscreen.h"
#include <QApplication>
#include <QMovie>

#include "SmtpMime"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MGAConnectSplashScreen *splash = new MGAConnectSplashScreen(eStartingApp);
    //splash->ShowSplash(3000);
    qApp->setApplicationName("MGAConnect");
    qApp->setOrganizationName("MGA");
    QSettings::setDefaultFormat(QSettings::IniFormat);
    MainWindow w;
    //w.showNormal();
    //QTimer::singleShot(10,&w, SLOT(showNormal()));
    //delete splash;
    return a.exec();
}
