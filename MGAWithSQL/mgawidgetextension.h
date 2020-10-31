#ifndef MGAWIDGETEXTENSION_H
#define MGAWIDGETEXTENSION_H

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QPushButton>

class MGAWidgetExtension : public QWidget
{
    Q_OBJECT
public:
    explicit MGAWidgetExtension(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *e);
    void leaveEvent(QEvent *);

signals:
    void mouseIsOver();
    void mouseIsLeft();

public slots:

};

#endif // MGAWIDGETEXTENSION_H
