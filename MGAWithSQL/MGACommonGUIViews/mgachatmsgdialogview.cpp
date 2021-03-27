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

        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignTrailing|Qt::AlignRight);
        __qlistwidgetitem->setFlags(Qt::ItemIsEnabled);
        __qlistwidgetitem->setText(msg);
    }
    catch (...)
    {
        return;
    }
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

}
