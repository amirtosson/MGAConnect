#ifndef MGACONNECTSPLASHSCREEN_H
#define MGACONNECTSPLASHSCREEN_H
#include <QSplashScreen>
#include <QTimer>
#include <QThread>
#include "mgaconnectsplashscreendefinations.h"
#include <QProgressBar>
#include <QDialog>
#include <vector>
#include <QMovie>


class MGAConnectSplashScreen: public QObject
{
public:
    MGAConnectSplashScreen(ESplashScreenType eSplashScreen);
    void ShowSplash(int time = 2000);
    void DeleteSplash();

public:
    void UpdateProgressBar(int value, QString msg);
private:
    QSplashScreen splash;
    QProgressBar *progressBar;
    ESplashScreenType eCurrentSplash;
    bool bSplashScreenReady = false;

private:
    void Animation(std::vector<QPixmap *> SplashImgsVector, int timeInterval = 1);
};

#endif // MGACONNECTSPLASHSCREEN_H



