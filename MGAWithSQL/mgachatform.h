#ifndef MGACHATFORM_H
#define MGACHATFORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QScreen>
#include <QApplication>


namespace Ui {
class MGAChatForm;
}

class MGAChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit MGAChatForm(QWidget *parent = nullptr);
    ~MGAChatForm();

private:
    Ui::MGAChatForm *ui;

protected:
    virtual void mousePressEvent( QMouseEvent *e );
    virtual void mouseMoveEvent( QMouseEvent *e );
    virtual void mouseReleaseEvent( QMouseEvent *e );

private slots:
    void on_toolButton_clicked();


private:
    bool _mousePressed;
    QPoint _mousePosition;
    QRect closedRect;
    QRect openedRect;
};

#endif // MGACHATFORM_H
