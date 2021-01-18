#ifndef MGACHATFORMVIEW_H
#define MGACHATFORMVIEW_H
#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <vector>

#include "chatformresources.h"

class MGAChatFormView
{
public:
    MGAChatFormView();
    void setupUi(QWidget *ChatForm);
    void IntializeChatCommandLinkButtons(const unsigned int chatswindows);

private slots:
    virtual void on_resizeBtn_clicked()=0;
    virtual void on_chatBotMGAChat_clicked()=0;

protected:
    QToolButton *resizeBtn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QCommandLinkButton *chatBotMGAChat;
    QToolButton *minimizeBtn;
    QToolButton *closeBtn;

    std::vector<QCommandLinkButton *> MGAChat;
};

#endif // MGACHATFORMVIEW_H
