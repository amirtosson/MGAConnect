#include "mganewobjectformview.h"
#include <QDebug>

void MGANewObjectFormView::setupUi(QDialog *AddNewObjectForm, EListType eList)
{
    if (AddNewObjectForm->objectName().isEmpty())
    {
        AddNewObjectForm->setObjectName(QString::fromUtf8("AddNewObjectForm"));
    }
    // Common Components
    AddNewObjectForm->resize(400,300);
    try
    {

        gridLayoutWidget = new QWidget(AddNewObjectForm);
        gridLayout = new QGridLayout(gridLayoutWidget);
        okButton = new QPushButton(AddNewObjectForm);
        cancelButton = new QPushButton(AddNewObjectForm);
        errorText = new QLabel(AddNewObjectForm);

    }
    catch (...)
    {
        return;
    }

    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(20, 20, AddNewObjectForm->width() -40 ,AddNewObjectForm->height()*0.6));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(5);
    sizePolicy.setVerticalStretch(5);
    sizePolicy.setHeightForWidth(AddNewObjectForm->sizePolicy().hasHeightForWidth());
    AddNewObjectForm->setSizePolicy(sizePolicy);
    okButton->setObjectName(QString::fromUtf8("OkButton"));
    cancelButton->setObjectName(QString::fromUtf8("CancelButton"));

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
    okButton->setIcon(icon);
    okButton->setIconSize(QSize(20, 20));

    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/buttonIcons/Resources/Icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
    cancelButton->setIcon(icon1);
    cancelButton->setIconSize(QSize(20, 20));

    okButton->setText(QCoreApplication::translate("AddNewObjectForm", "OK", nullptr));
    cancelButton->setText(QCoreApplication::translate("AddNewObjectForm", "Cancel", nullptr));

    errorText->setObjectName(QString::fromUtf8("errorText"));

    QMetaObject::connectSlotsByName(AddNewObjectForm);

    //Special components
    componentsEditLines.clear();
    componentsLabels.clear();
    switch (eList) {
    case eUsersList:
        {
            IntializeUserGUIComponents(AddNewObjectForm);
        }
        break;
    case eMemberList:
        {
            IntializeMemberGUIComponents(AddNewObjectForm);
        }
        break;
    case eExperimentist:
        {
            IntializeExpGUIComponents(AddNewObjectForm);
        }
        break;
    case eAppointmentList:
        {
            IntializeAppointGUIComponents(AddNewObjectForm);
        }
        break;
    default:
        break;
    }
}

bool MGANewObjectFormView::IntializeUserGUIComponents(QWidget *widget)
{
    try
    {
        SetupLabelsAndEditLines(4,3);
        comboBox = new QComboBox(gridLayoutWidget);
    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }

    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);

    componentsLabels[0]->setText(TXT_NAME_LABEL);
    componentsLabels[1]->setText(TXT_HOST_LABEL);
    componentsLabels[2]->setText(TXT_PWD_LABEL);
    componentsLabels[3]->setText(TXT_ROLE_LABEL);

    componentsEditLines[0]->setPlaceholderText(TXT_NAME_PH);
    componentsEditLines[1]->setPlaceholderText(TXT_HOST_PH);
    componentsEditLines[2]->setPlaceholderText(TXT_PWD_PH);

    componentsEditLines[2]->setClearButtonEnabled(false);
    componentsEditLines[2]->setEchoMode(QLineEdit::Password);


    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    gridLayout->addWidget(comboBox, 3, 1, 1, 1);

    QStringList styleList;
    styleList.append(TXT_ADMIN_ROLE);
    styleList.append(TXT_USER_ROLE);
    styleList.append(TXT_GUEST_ROLE);
    styleList.append(TXT_STUDENT_ROLE);
    comboBox->clear();
    comboBox->addItems(styleList);
    comboBox->setCurrentIndex(-1);
    QWidget::setTabOrder(componentsEditLines[0], componentsEditLines[1]);
    widget->setWindowTitle(QCoreApplication::translate("AddNewObjectForm", "Add New User", nullptr));

    ResizeComponents(widget->width(),widget->height());
    QMetaObject::connectSlotsByName(widget);
    return true;
}

bool MGANewObjectFormView::IntializeMemberGUIComponents(QWidget *widget)
{

    try
    {
        SetupLabelsAndEditLines(5,5);
    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }

    componentsLabels[0]->setText(TXT_FIRST_NAME_LABEL);
    componentsLabels[1]->setText(TXT_LAST_NAME_LABEL);
    componentsLabels[2]->setText(TXT_EMAIL_LABEL);
    componentsLabels[3]->setText(TXT_WORKIN_BY_LABEL);
    componentsLabels[4]->setText(TXT_JOIN_AT_LABEL);

    componentsEditLines[0]->setPlaceholderText(TXT_FIRST_NAME_PH);
    componentsEditLines[1]->setPlaceholderText(TXT_LAST_NAME_PH);
    componentsEditLines[2]->setPlaceholderText(TXT_EMAIL_PH);
    componentsEditLines[3]->setPlaceholderText(TXT_WORKIN_BY_PH);
    componentsEditLines[4]->setPlaceholderText(TXT_DATE_PH);


    return true;
}

bool MGANewObjectFormView::IntializeExpGUIComponents(QWidget *widget)
{
    try
    {
        SetupLabelsAndEditLines(4,4);
    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }

    componentsLabels[0]->setText(TXT_FACILITY_LABEL);
    componentsLabels[1]->setText(TXT_START_AT_LABEL);
    componentsLabels[2]->setText(TXT_ENDS_AT_LABEL);
    componentsLabels[3]->setText(TXT_DESCRIPTION_LABEL);

    componentsEditLines[0]->setPlaceholderText(TXT_FACILITY_PH);
    componentsEditLines[1]->setPlaceholderText(TXT_DATE_PH);
    componentsEditLines[2]->setPlaceholderText(TXT_DATE_PH);
    componentsEditLines[3]->setPlaceholderText(TXT_DESCRIPTION_PH);
    return true;
}

bool MGANewObjectFormView::IntializeAppointGUIComponents(QWidget *widget)
{
    try
    {
        SetupLabelsAndEditLines(4,4);
    }
    catch(...)
    {
        //TODO: exception handling
        return false;
    }

    componentsLabels[0]->setText(TXT_START_AT_LABEL);
    componentsLabels[1]->setText(TXT_ENDS_AT_LABEL);
    componentsLabels[2]->setText(TXT_ENDS_GUESTS_LABEL);
    componentsLabels[3]->setText(TXT_DESCRIPTION_LABEL);

    componentsEditLines[0]->setPlaceholderText(TXT_DATE_PH);
    componentsEditLines[1]->setPlaceholderText(TXT_DATE_PH);
    componentsEditLines[2]->setPlaceholderText(TXT_GUESTS_PH);
    componentsEditLines[3]->setPlaceholderText(TXT_DESCRIPTION_PH);
    return true;
}

void MGANewObjectFormView::ResizeComponents(int w, int h)
{
     gridLayoutWidget->resize(w - 40, h * ENTRIES_GRID_HEIGHT_RATIO);

     for (auto it = componentsEditLines.begin() ; it != componentsEditLines.end(); ++it)
     {
         (*it)->setMinimumHeight(gridLayoutWidget->height() * ENTRIES_HEIGHT_RATIO);
     }

     if(comboBox != NULL)
     {
         comboBox->setMinimumHeight(gridLayoutWidget->height() * ENTRIES_HEIGHT_RATIO);
     }
     cancelButton->setGeometry(QRect(w * 0.5, gridLayoutWidget->height() + h * MARGIN_RATIO, w * EXTRA_COMPONENTS_WIDTH_RATIO, h * EXTRA_COMPONENTS_HEIGHT_RATIO));
     okButton->setGeometry(QRect(w * 0.5 + cancelButton->width() + 10, gridLayoutWidget->height() + h * MARGIN_RATIO, w * EXTRA_COMPONENTS_WIDTH_RATIO, h * EXTRA_COMPONENTS_HEIGHT_RATIO));
     errorText->setGeometry(QRect(20, gridLayoutWidget->height() + h * MARGIN_RATIO, w * EXTRA_COMPONENTS_WIDTH_RATIO, h * EXTRA_COMPONENTS_HEIGHT_RATIO));

     okButton->setIconSize(QSize(okButton->height() - 10, okButton->height() - 10));
     cancelButton->setIconSize(QSize(okButton->height() - 10, okButton->height() - 10));
}

QStringList MGANewObjectFormView::GetLinesFields()
{
    QStringList fields;
    for (unsigned int i = 0; i <componentsEditLines.size(); ++i)
    {
        fields.append(componentsEditLines[i]->text());
    }
    return fields;
}

int MGANewObjectFormView::GetComboBoxValue()
{
    return comboBox == NULL ? false : comboBox->currentIndex();
}

QString MGANewObjectFormView::GetUserName()
{
    return componentsEditLines[0]->text();
}

QString MGANewObjectFormView::GetUserHost()
{
    return componentsEditLines[1]->text();
}

QString MGANewObjectFormView::GetUserPWD()
{
    return componentsEditLines[2]->text();
}

QString MGANewObjectFormView::GetUserRole()
{
    switch (comboBox->currentIndex()) {
    case eAdmin:
        return ADMIN_ROLE;
        break;
    case eGuest:
        return GUEST_ROLE;
        break;
    case eStudent:
        return STUDENT_ROLE;
        break;
    case eUser:
        return USER_ROLE;
        break;
    default:
        break;
    }
    return 0;
}

void MGANewObjectFormView::SetupLabelsAndEditLines(const int labels, const int lines)
{
    componentsLabels.resize(labels);
    componentsEditLines.resize(lines);
    try
    {
        unsigned int counter = 0;
        for (auto it = componentsLabels.begin() ; it != componentsLabels.end(); ++it)
        {
            *it =   new QLabel(gridLayoutWidget);
            gridLayout->addWidget(*it, counter, 0, 1, 1);
            counter++;
        }
        counter = 0;
        for (auto it = componentsEditLines.begin() ; it != componentsEditLines.end(); ++it)
        {
            *it =   new QLineEdit(gridLayoutWidget);
            gridLayout->addWidget(*it, counter, 1, 1, 1);
            (*it)->setClearButtonEnabled(true);
            counter++;
        }

    }
    catch(...)
    {
        //TODO: exception handling
    }

}
