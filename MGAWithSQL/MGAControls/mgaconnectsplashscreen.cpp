#include "mgaconnectsplashscreen.h"


MGAConnectSplashScreen::MGAConnectSplashScreen(ESplashScreenType eSplashScreen)
    :eCurrentSplash(eSplashScreen)
{
    try
    {
        progressBar = new QProgressBar(&splash);
        bSplashScreenReady = true;
    }
    catch (...)
    {
        return;
    }


}

void MGAConnectSplashScreen::ShowSplash(int time)
{

    progressBar->setGeometry(10, 350, 600, 20); // puts it at bottom
    progressBar->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    progressBar->setStyleSheet(PROGRESSBAB_STYLE);

    progressBar->setValue(0);
    progressBar->setMaximum(100);
    progressBar->setEnabled(true);
    QPixmap SplashImg;
    QPixmap SplashImg2;
    QPixmap SplashImg3;
    std::vector<QPixmap*>imgvec;


    switch (eCurrentSplash)
    {
        case eStartingApp:
            {
              SplashImg = QPixmap(IMG_LOGO_1);
              SplashImg2 = QPixmap(IMG_LOGO_2);
              SplashImg3 = QPixmap(IMG_LOGO_3);
              imgvec.push_back(&SplashImg);
              imgvec.push_back(&SplashImg2);
              imgvec.push_back(&SplashImg3);
              //splash.setPixmap(SplashImg.scaled(1000,400,Qt::IgnoreAspectRatio));
            }
            break;
        default:
            break;
    }
    splash.setCursor(Qt::BusyCursor);
    splash.setGeometry(500,500,1000,400);
    splash.setStyleSheet(SPLASH_SCREEN_STYLE);
    //splash.showMessage(MSG_LOADING, Qt::AlignBottom);

    splash.show();
    Animation(imgvec, 1);
    UpdateProgressBar(10,MSG_GUI_LOADING);
    //QThread::sleep(1);
    Animation(imgvec, 1);
    //QThread::sleep(1);
    UpdateProgressBar(50,MSG_APIS_INIT);
    //QThread::sleep(1);
    Animation(imgvec, 1);
    UpdateProgressBar(90,MSG_FINALIZING);
    //QThread::sleep(1);
    UpdateProgressBar(100,MSG_READY);
    //QThread::sleep(1);
    //QTimer::singleShot(6, &splash,SLOT(close())); // Timer
}

void MGAConnectSplashScreen::DeleteSplash()
{
    //if (bSplashScreenReady) delete splash;
}

void MGAConnectSplashScreen::UpdateProgressBar(int value, QString msg)
{
    if(eCurrentSplash != eStartingApp) return;
    splash.showMessage(msg, Qt::AlignBottom);
    progressBar->setValue(value);
}

void MGAConnectSplashScreen::Animation(std::vector<QPixmap*>SplashImgsVector, int timeInterval)
{
    for (auto it = SplashImgsVector.begin() ; it != SplashImgsVector.end(); ++it)
    {
        splash.setPixmap((*it)->scaled(1000,400,Qt::IgnoreAspectRatio));
        QThread::sleep(timeInterval);
    }
}
