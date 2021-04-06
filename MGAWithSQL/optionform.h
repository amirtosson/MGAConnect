#ifndef OPTIONFORM_H
#define OPTIONFORM_H

#include <QWidget>
#include "optionformsetups.h"
#include "mgastyleenum.h"

namespace Ui {
class OptionForm;
}

class OptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit OptionForm(QWidget *parent = 0);
    ~OptionForm();

    EMGAStyle eCurrentStyle = eDarkStyle;

private slots:
    void MouseOnFirstBtn();
    void MouseLeftFirstBtn();
    void MouseOnSecondBtn();
    void MouseLeftSecondBtn();
    void MouseOnThirdBtn();
    void MouseLeftThirdBtn();
    void on_firstButton_clicked();
    void on_changingButtonBox_accepted();
    void on_changingButtonBox_rejected();

    void on_secondButton_clicked();

signals:
    void StyleIsChanged();

private:
    Ui::OptionForm *ui;
};

#endif // OPTIONFORM_H
