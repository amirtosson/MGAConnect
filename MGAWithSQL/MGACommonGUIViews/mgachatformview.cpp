#include "mgachatformview.h"



MGAChatFormView::MGAChatFormView()
{

}

void MGAChatFormView::setupUi(QWidget *ChatForm)
{
    try
    {
        resizeBtn = new QToolButton(ChatForm);
        minimizeBtn = new QToolButton(ChatForm);
        closeBtn = new QToolButton(ChatForm);
        scrollArea = new QScrollArea(ChatForm);
        scrollAreaWidgetContents = new QWidget();
        chatBotMGAChat = new QCommandLinkButton(scrollAreaWidgetContents);

    }
    catch (...)
    {

    }


    if (ChatForm->objectName().isEmpty())
    {
        ChatForm->setObjectName(QString::fromUtf8("MGAChatForm"));
    }
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
    resizeBtn->setObjectName(QString::fromUtf8("resizeBtn"));
    minimizeBtn->setObjectName(QString::fromUtf8("minimizeBtn"));


    ChatForm->resize(304, 273);
    ChatForm->setCursor(QCursor(Qt::OpenHandCursor));
    ChatForm->setStyleSheet(QString::fromUtf8(""));
    resizeBtn->setGeometry(QRect(20, 20, 51, 50));
    resizeBtn->setStyleSheet(QString::fromUtf8(COMMAND_LINK_BUTTON_STYLE));
    closeBtn->setStyleSheet(QString::fromUtf8(COMMAND_LINK_BUTTON_STYLE));
    minimizeBtn->setStyleSheet(QString::fromUtf8(COMMAND_LINK_BUTTON_STYLE));

    scrollArea->setGeometry(QRect(10, 100, 281, 161));
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 279, 159));
    chatBotMGAChat->setObjectName(QString::fromUtf8("chatBotMGAChat"));
    chatBotMGAChat->setGeometry(QRect(0, 0, 279, 36));
    chatBotMGAChat->setLayoutDirection(Qt::LeftToRight);
    scrollArea->setWidget(scrollAreaWidgetContents);
    minimizeBtn->setGeometry(QRect(100, 20, 51, 50));

    closeBtn->setGeometry(QRect(180, 20, 51, 50));



    QIcon icon1;
    icon1.addFile(QString::fromUtf8(URL_EXPAND_ICON), QSize(), QIcon::Normal, QIcon::On);
    resizeBtn->setIcon(icon1);

    QMetaObject::connectSlotsByName(ChatForm);

}

void MGAChatFormView::IntializeChatCommandLinkButtons(const unsigned int chatswindows)
{
    MGAChat.resize(chatswindows);
    for (auto it = MGAChat.begin(); it != MGAChat.end(); ++it)
    {
        *it =   new QCommandLinkButton(scrollAreaWidgetContents);
    }
}
