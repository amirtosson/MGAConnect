#ifndef MGACHATMSGDIALOG_H
#define MGACHATMSGDIALOG_H

#include <QDialog>
#include "mgachatmsgdialogview.h"



class MGAChatMSGDialog : public QDialog, MGAChatMSGDialogView
{
    Q_OBJECT

public:
    explicit MGAChatMSGDialog(QWidget *parent = nullptr);
    ~MGAChatMSGDialog();

private slots:
    void on_MGAChatMSGDialog_finished(int result);
    void on_msgTextEditBox_textChanged();
    void on_sendButton_clicked();

    void OnMSGRecieved(QString chatMsg);

signals:
    void MSGBoxIsClosed();
    void MSGHasBeenSent(QString chatMsg);

private:
    QString msgHist;
};

#endif // MGACHATMSGDIALOG_H
