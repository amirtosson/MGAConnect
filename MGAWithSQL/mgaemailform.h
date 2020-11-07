#ifndef MGAEMAILFORM_H
#define MGAEMAILFORM_H

#include <QWidget>
#include "SmtpMime"

namespace Ui {
class MGAEmailForm;
}

class MGAEmailForm : public QWidget
{
    Q_OBJECT

public:
    explicit MGAEmailForm(QWidget *parent = 0);
    ~MGAEmailForm();

    bool SendEmail();

private:
    Ui::MGAEmailForm *ui;
};

#endif // MGAEMAILFORM_H
