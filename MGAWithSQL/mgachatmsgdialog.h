#ifndef MGACHATMSGDIALOG_H
#define MGACHATMSGDIALOG_H

#include <QDialog>

namespace Ui {
class MGAChatMSGDialog;
}

class MGAChatMSGDialog : public QDialog
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
    Ui::MGAChatMSGDialog *ui;
    QString msgHist;
};

#endif // MGACHATMSGDIALOG_H
