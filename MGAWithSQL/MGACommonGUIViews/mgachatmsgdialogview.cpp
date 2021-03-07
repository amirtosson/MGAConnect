#include "mgachatmsgdialogview.h"


void MGAChatMSGDialogView::setupUi(QDialog *MGAChatMSGDialog)
{
    if (MGAChatMSGDialog->objectName().isEmpty())
    {
        MGAChatMSGDialog->setObjectName(QString::fromUtf8("MGAChatMSGDialog"));
    }
    MGAChatMSGDialog->resize(643, 474);

    try
    {
        msgTextEditBox = new QTextEdit(MGAChatMSGDialog);
        sendButton = new QPushButton(MGAChatMSGDialog);
        widget = new QWidget(MGAChatMSGDialog);


        gridLayoutWidget = new QWidget(widget);
        gridLayout = new QGridLayout(gridLayoutWidget);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    }
    catch (...)
    {
        return;
    }




    msgTextEditBox->setObjectName(QString::fromUtf8("msgTextEditBox"));
    msgTextEditBox->setGeometry(QRect(30, 320, 601, 101));
    msgTextEditBox->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

    sendButton->setObjectName(QString::fromUtf8("sendButton"));
    sendButton->setEnabled(false);
    sendButton->setGeometry(QRect(520, 430, 89, 25));

    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(30, 10, 591, 301));
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 10, 561, 91));
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);


    QMetaObject::connectSlotsByName(MGAChatMSGDialog);
}

void MGAChatMSGDialogView::AddSentMSG(QString msg)
{
    try
    {
        msgBrowser = new QTextBrowser(widget);
    }
    catch (...)
    {
        return;
    }
    msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));
    msgBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
                            "color: rgb(9, 9, 9);"));
    msgBrowser->setInputMethodHints(Qt::ImhMultiLine);
    msgBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    msgBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    msgBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    msgBrowser->setText(msg);
    gridLayout->addWidget(msgBrowser, 1, 0, 1, 1);

}

void MGAChatMSGDialogView::AddReceivedMSG(QString msg)
{
    try
    {
        msgBrowserMGA = new QTextBrowser(widget);
    }
    catch (...)
    {
        return;
    }

    msgBrowserMGA->setObjectName(QString::fromUtf8("msgBrowserMGA"));
    //msgBrowserMGA->setGeometry(QRect(320, 70, 251, 51));
    msgBrowserMGA->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 135, 135);\n"
                                "color: rgb(0, 0, 0);"));
    msgBrowserMGA->setInputMethodHints(Qt::ImhMultiLine);
    msgBrowserMGA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    msgBrowserMGA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    msgBrowserMGA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    msgBrowserMGA->setText(msg);
    gridLayout->addWidget(msgBrowserMGA, 2, 1, 1, 1);

}
