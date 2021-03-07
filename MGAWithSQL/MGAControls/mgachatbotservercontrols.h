#ifndef MGACHATBOTSERVERCONTROLS_H
#define MGACHATBOTSERVERCONTROLS_H

#include <QString>
#include <QTcpSocket>
typedef void (*callback_function)(void); // type for conciseness



class MGAChatBotServerControls: public QObject
{
    Q_OBJECT
public:
    explicit MGAChatBotServerControls();

    void SendRequestMSG(QString *msg);
    void BroadcastResponse(QString msg);

public slots:
    void UserToChatBotMSGHasBeenSent(QString msg);
   // void connected();
   // void disconnected();
   // void bytesWritten(qint64 bytes);
   void readyRead();

signals:
     void MSGRecieved(QString chatMSG, int senderID);

private:
    bool ChatbotEstablishConnections();


private:
     QTcpSocket *socket;
};

#endif // MGACHATBOTSERVERCONTROLS_H
