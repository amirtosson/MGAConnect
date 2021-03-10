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
        listWidget = new QListWidget(widget);

        //gridLayoutWidget = new QWidget(widget);
        //gridLayout = new QGridLayout(gridLayoutWidget);
        //horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        //horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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
    sendButton->setText( "Send");

    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(30, 10, 591, 301));
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));

    listWidget->setSpacing(5);
    listWidget->setGeometry(QRect(10, 10, 571, 271));
    listWidget->setObjectName(QString::fromUtf8("listWidget"));
    listWidget->setSortingEnabled(false);

    //gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    //gridLayoutWidget->setGeometry(QRect(10, 10, 561, 300));
    //gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    //gridLayout->setContentsMargins(0, 0, 0, 0);


    listWidget->setFrameShadow(QFrame::Plain);
    listWidget->setLineWidth(0);
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    listWidget->setProperty("showDropIndicator", QVariant(true));
    listWidget->setTextElideMode(Qt::ElideRight);
    listWidget->setMovement(QListView::Snap);
    listWidget->setProperty("isWrapping", QVariant(false));
    listWidget->setResizeMode(QListView::Fixed);
    listWidget->setLayoutMode(QListView::SinglePass);
    listWidget->setSpacing(5);
    listWidget->setGridSize(QSize(100, 20));
    listWidget->setViewMode(QListView::ListMode);
    listWidget->setModelColumn(0);
    listWidget->setWordWrap(false);


    QMetaObject::connectSlotsByName(MGAChatMSGDialog);
}

void MGAChatMSGDialogView::AddSentMSG(QString msg)
{
    try
    {

        //msgBrowser = new QTextBrowser(widget);
        //QBrush brush(QColor(75, 75, 75, 255));
       // brush.setStyle(Qt::SolidPattern);
        //QFont font;
        //font.setKerning(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
       // __qlistwidgetitem->setFont(font);
        //__qlistwidgetitem->setBackground(brush);
        __qlistwidgetitem->setTextAlignment(Qt::AlignTrailing|Qt::AlignRight);
        __qlistwidgetitem->setFlags(Qt::ItemIsEnabled);
        __qlistwidgetitem->setText(msg);
        //listWidget->addItem("msg");
    }
    catch (...)
    {
        return;
    }
   // msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));
    //msgBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
                            //"color: rgb(9, 9, 9);"));
    //msgBrowser->setInputMethodHints(Qt::ImhMultiLine);
    //msgBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //msgBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //msgBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    //msgBrowser->setText(msg);
    //gridLayout->addWidget(msgBrowser, msgUserConter, 1, 1, 1);
    //msgUserConter +=2;
}

void MGAChatMSGDialogView::AddReceivedMSG(QString msg)
{
    try
    {
        QBrush brush(QColor(75, 75, 75, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setKerning(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush);
        __qlistwidgetitem->setFlags(Qt::ItemIsEnabled);
        __qlistwidgetitem->setText(msg);
    }
    catch (...)
    {
        return;
    }

    //msgBrowserMGA->setObjectName(QString::fromUtf8("msgBrowserMGA"));
    //msgBrowserMGA->setGeometry(QRect(320, 70, 251, 51));
    //msgBrowserMGA->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 135, 135);\n"
                                //"color: rgb(0, 0, 0);"));
    //msgBrowserMGA->setInputMethodHints(Qt::ImhMultiLine);
    //msgBrowserMGA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //msgBrowserMGA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //msgBrowserMGA->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    //msgBrowserMGA->setText(msg);
    //gridLayout->addWidget(msgBrowserMGA, msgMGAConter, 0, 1, 1);
    //msgMGAConter +=2;
}
