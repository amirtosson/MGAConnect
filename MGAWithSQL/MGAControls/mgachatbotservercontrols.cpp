#include "mgachatbotservercontrols.h"
#include <QDebug>
#include <QByteArray>


MGAChatBotServerControls::MGAChatBotServerControls(QTcpSocket *socketptr)
    :socket(socketptr)
{

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));


    socket->connectToHost("127.0.0.1", 65432);
    if(socket->waitForConnected(5000))
    {
        qDebug() <<"connected to the chatbot";
        QString str = "Hallo from QT";
        socket->write(str.toLatin1());
    }
    else
    {

    }
}

void MGAChatBotServerControls::BroadcastResponse(QString msg)
{
    emit MSGRecieved(msg, -1);
}

void MGAChatBotServerControls::UserToChatBotMSGHasBeenSent(QString msg)
{
    socket->write(msg.toLatin1());
    //BroadcastResponse();
}

void MGAChatBotServerControls::readyRead()
{
    QByteArray res = socket->readAll();
    BroadcastResponse(QString::fromStdString(res.toStdString()));


}
