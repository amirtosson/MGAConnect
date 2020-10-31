#ifndef MGAOPTIONBUTTONEXTENSION_H
#define MGAOPTIONBUTTONEXTENSION_H

#include <QWidget>
#include <QPushButton>

class MGAOptionButtonExtension : public QWidget
{
    Q_OBJECT
public:
    explicit MGAOptionButtonExtension(QWidget *parent = 0);

signals:

public slots:
    void MouseIsOver(QPushButton *btn);
};

#endif // MGAOPTIONBUTTONEXTENSION_H
