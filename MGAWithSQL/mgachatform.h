#ifndef MGACHATFORM_H
#define MGACHATFORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QScreen>
#include <QApplication>
#include "mgachatformview.h"
#include "mgachatmsgdialog.h"


namespace Ui {
class MGAChatForm;
}

class MGAChatForm : public QWidget, private MGAChatFormView
{
    Q_OBJECT

public:
    explicit MGAChatForm(QWidget *parent = nullptr);
    ~MGAChatForm();

private:
    //Ui::MGAChatForm *ui;

protected:
    virtual void mousePressEvent( QMouseEvent *e );
    virtual void mouseMoveEvent( QMouseEvent *e );
    virtual void mouseReleaseEvent( QMouseEvent *e );

private slots:
    void on_resizeBtn_clicked();
    void on_chatBotMGAChat_clicked();
    void on_minimizeBtn_clicked();
    void on_closeBtn_clicked();

    void NoMSGBoxIsOpened();

private:
    void HideBtns();
    void ShowBtns();

private:
    bool _mousePressed;
    QPoint _mousePosition;
    QRect closedRect;
    QRect openedRect;
    //TODO: make it unique. only one chat form dialog is allowed (for now)
    MGAChatMSGDialog *_chatForm;
};

#endif // MGACHATFORM_H
