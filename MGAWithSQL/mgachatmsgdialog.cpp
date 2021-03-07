#include "mgachatmsgdialog.h"
#include <QDebug>

MGAChatMSGDialog::MGAChatMSGDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

MGAChatMSGDialog::~MGAChatMSGDialog()
{

}

void MGAChatMSGDialog::on_MGAChatMSGDialog_finished(int result)
{
    emit MSGBoxIsClosed();
}


void MGAChatMSGDialog::on_msgTextEditBox_textChanged()
{
    if(msgTextEditBox->toPlainText().isEmpty())
    {
        sendButton->setEnabled(false);
    }
    else
    {
        sendButton->setEnabled(true);
    }
}

void MGAChatMSGDialog::on_sendButton_clicked()
{
    QString msg = msgTextEditBox->toPlainText();
    msgHist += msg;
    emit MSGHasBeenSent(msg);
    AddSentMSG(msg);
    msgTextEditBox->clear();
}

void MGAChatMSGDialog::OnMSGRecieved(QString chatMsg)
{
    AddReceivedMSG(chatMsg);
}
