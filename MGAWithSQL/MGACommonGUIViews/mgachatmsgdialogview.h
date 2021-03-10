#ifndef MGACHATMSGDIALOGVIEW_H
#define MGACHATMSGDIALOGVIEW_H

#include <QWidget>
#include <QToolButton>
#include <QVariant>
#include <QApplication>
#include <QGridLayout>
#include <QScrollArea>
#include <QSpacerItem>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include <QListWidget>


#include <vector>

class MGAChatMSGDialogView
{
public:
    void setupUi(QDialog *MGAChatMSGDialog);
    void AddSentMSG(QString msg);
    void AddReceivedMSG(QString msg);

public slots:
    virtual void on_MGAChatMSGDialog_finished(int result) = 0;
    virtual void on_msgTextEditBox_textChanged() = 0;
    virtual void on_sendButton_clicked() = 0;
protected:
    QTextEdit *msgTextEditBox;
    QPushButton *sendButton;
    QWidget *widget;
    QListWidget *listWidget;





};

#endif // MGACHATMSGDIALOGVIEW_H
