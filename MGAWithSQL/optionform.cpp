#include "optionform.h"
#include "ui_optionform.h"
#include <QEvent>
#include <QMouseEvent>
#include <QRect>
#include <QRegion>
#include <QDebug>

OptionForm::OptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionForm)
{
    ui->setupUi(this);
    SETUP_CONNECTIONS

    SET_OPTION_FORM_STYLE
}

OptionForm::~OptionForm()
{
    delete ui;

}

void OptionForm::MouseOnFirstBtn()
{
    MOUSE_ON_OPTION_BUTTON(ui->firstButton)
}

void OptionForm::MouseLeftFirstBtn()
{
    MOUSE_LEFT_OPTION_BUTTON(ui->firstButton)
}

void OptionForm::MouseOnSecondBtn()
{
    MOUSE_ON_OPTION_BUTTON(ui->secondButton)
}

void OptionForm::MouseLeftSecondBtn()
{
    MOUSE_LEFT_OPTION_BUTTON(ui->secondButton)
}

void OptionForm::MouseOnThirdBtn()
{
    MOUSE_ON_OPTION_BUTTON(ui->thirdButton)
}

void OptionForm::MouseLeftThirdBtn()
{
    MOUSE_LEFT_OPTION_BUTTON(ui->thirdButton)
}

void OptionForm::on_firstButton_clicked()
{
    SET_STYLE_CHANGING_GROUP
}

void OptionForm::on_changingButtonBox_accepted()
{
    switch (ui->styleComboBox->currentIndex()) {
    case eDarkStyle:
        eCurrentStyle = eDarkStyle;
        break;
    case eDefaultStyle:
        eCurrentStyle = eDefaultStyle;
        break;
    case eBrightStyle:
        eCurrentStyle = eBrightStyle;
        break;
    default:
        break;
    }
    emit StyleIsChanged();
    BACK_TO_DEFAULT
}

void OptionForm::on_changingButtonBox_rejected()
{
    BACK_TO_DEFAULT
}
