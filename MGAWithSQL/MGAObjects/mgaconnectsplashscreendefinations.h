#ifndef MGACONNECTSPLASHSCREENTYPEENUM_H
#define MGACONNECTSPLASHSCREENTYPEENUM_H


extern "C" enum ESplashScreenType
{
    eStartingApp,
    eWaiting,
    eBlocked
};


#define MSG_LOADING                 "MGAConnect is loading ..."
#define MSG_GUI_LOADING             "GUI components are being loading ..."
#define MSG_APIS_INIT               "APIs and service are being intialized ..."
#define MSG_FINALIZING              "Finalizing ..."
#define MSG_READY                   "MGAConnect is ready ..."


// local styles
#define SPLASH_SCREEN_STYLE         "color: #ffffff; font: 15px; font-weight: bold; "
#define PROGRESSBAB_STYLE           "QProgressBar {color: black; font: 10px; font-weight: bold;}\
                                    QProgressBar:chunk {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \
                                    stop:0 rgba(4, 91, 172, 255), stop:1 rgba(190, 230, 250, 255));;}"

// img urls

#define IMG_LOGO_1                  ":/logos/Resources/Images/logofr1.jpg"
#define IMG_LOGO_2                  ":/logos/Resources/Images/logofr2.jpg"
#define IMG_LOGO_3                  ":/logos/Resources/Images/logofr3.jpg"
#define IMG_LOGO_GIF                ":/logos/Resources/Images/logoanimation.gif"


#endif // MGACONNECTSPLASHSCREENTYPEENUM_H
