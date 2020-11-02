#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    QPixmap g = QPixmap(":/new/logo/amg.jpg");
    splash->setPixmap(g.scaled(1000,400,Qt::IgnoreAspectRatio)); // splash picture
    //splash->setGeometry(10,10,1000,400);

    splash->show();
    MainWindow w;
    QTimer::singleShot(2000, splash,SLOT(close())); // Timer
    QTimer::singleShot(2000,&w,SLOT(show()));
    return a.exec();
}
