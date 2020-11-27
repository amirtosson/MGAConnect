#ifndef MGALISTFORMSETUPS_H
#define MGALISTFORMSETUPS_H

#define FIXED_SETUPS\
    userListFormUi->userListWidget->horizontalHeader()->setStretchLastSection(true);\
    userListFormUi->userListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);\
    userListFormUi->userListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);\
    userListFormUi->pageTitle->setAlignment(Qt::AlignCenter);\
    userListFormUi->pageTitle->setStyleSheet(STYLE_FONT_BOLD);\

#define BUTTONS_SETUP\
    SET_BTN_ICON(addUserButton,IMG_ADD_USER)\
    SET_BTN_ICON(editUserButton,IMG_CHANGE_USER)\
    SET_BTN_ICON(deleteUserButton,IMG_DELETE_USER)\
    DISABLE_BUTTONS

#define BUTTONS_SETUP_DEFAULT\
    SET_BTN_ICON(addUserButton,IMG_ADD_DEFAULT)\
    SET_BTN_ICON(editUserButton,IMG_CHANGE_DEFAULT)\
    SET_BTN_ICON(deleteUserButton,IMG_DELETE_DEFAULT)\
    DISABLE_BUTTONS

#define MEMBERS_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    userListFormUi->userListWidget->insertColumn(2);\
    userListFormUi->userListWidget->insertColumn(3);\
    userListFormUi->userListWidget->insertColumn(4);\
    QStringList q;\
    q.append(TXT_FIRST_NAME);\
    q.append(TXT_LAST_NAME);\
    q.append(TXT_WORKINGBY);\
    q.append(TXT_JOINED_AT);\
    q.append(TXT_EMAIL);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q);\
    userListFormUi->pageTitle->setText(TXT_MEMBER_LIST);\
    FIXED_SETUPS\




#define DISABLE_BUTTONS\
    userListFormUi->editUserButton->setEnabled(false);\
    userListFormUi->deleteUserButton->setEnabled(false);

#define ENABLE_BUTTONS\
    userListFormUi->editUserButton->setEnabled(true);\
    userListFormUi->deleteUserButton->setEnabled(true);

#define DATABASES_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    QStringList q2;\
    q2.append(TXT_DATABASE);\
    q2.append(TXT_HOST);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q2);\
    FIXED_SETUPS\


#define EXP_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    userListFormUi->userListWidget->insertColumn(2);\
    userListFormUi->userListWidget->insertColumn(3);\
    QStringList q2;\
    q2.append(TXT_FACILITY);\
    q2.append(TXT_STARTS_ON);\
    q2.append(TXT_ENDS_ON);\
    q2.append(TXT_DESCRIPTION);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q2);\
    userListFormUi->pageTitle->setText(TXT_EXP_LIST);\
    FIXED_SETUPS\

#define APPOINTS_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    userListFormUi->userListWidget->insertColumn(2);\
    userListFormUi->userListWidget->insertColumn(3);\
    QStringList q2;\
    q2.append(TXT_STARTS_ON);\
    q2.append(TXT_ENDS_ON);\
    q2.append(TXT_GUESTS);\
    q2.append(TXT_DESCRIPTION);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q2);\
    FIXED_SETUPS\
    userListFormUi->pageTitle->setText(TXT_APPOINTS_LIST);\


#define USERS_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    userListFormUi->userListWidget->insertColumn(2);\
    QStringList q3;\
    q3.append(TXT_USER_NAME);\
    q3.append(TXT_HOST);\
    q3.append(TXT_ROLE);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q3);\
    FIXED_SETUPS\
    userListFormUi->pageTitle->setText(TXT_USER_LIST);\

#define SET_BTN_ICON(btn,iconURI)\
    btnIcon = QIcon(iconURI);\
    userListFormUi->btn->setIcon(btnIcon);\
    userListFormUi->btn->setIconSize(QSize(40, 40));


#endif // MGALISTFORMSETUPS_H
