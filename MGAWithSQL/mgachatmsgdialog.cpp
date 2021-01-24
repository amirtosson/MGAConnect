#include "mgachatmsgdialog.h"
#include "ui_mgachatmsgdialog.h"
#include <QDebug>

MGAChatMSGDialog::MGAChatMSGDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MGAChatMSGDialog)
{
    ui->setupUi(this);

}

MGAChatMSGDialog::~MGAChatMSGDialog()
{
    delete ui;
}

void MGAChatMSGDialog::on_MGAChatMSGDialog_finished(int result)
{
    emit MSGBoxIsClosed();
}


void MGAChatMSGDialog::on_msgTextEditBox_textChanged()
{
    if(ui->msgTextEditBox->toPlainText().isEmpty())
    {
        ui->sendButton->setEnabled(false);
    }
    else
    {
        ui->sendButton->setEnabled(true);
    }
}

void MGAChatMSGDialog::on_sendButton_clicked()
{
    QString msg = ui->msgTextEditBox->toPlainText();
    msgHist += "\n";
    msgHist += "you: ";
    msgHist += msg;
    emit MSGHasBeenSent(msg);
    ui->msgBrowser->setText(msgHist);
    ui->msgTextEditBox->clear();
}

void MGAChatMSGDialog::OnMSGRecieved(QString chatMsg)
{
    msgHist += "\n";
    msgHist += "\n";
    msgHist += "MGA: ";
    msgHist += chatMsg;
    ui->msgBrowser->setText(msgHist);
}
