#ifndef MGALISTFORMSETUPS_H
#define MGALISTFORMSETUPS_H

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
    userListFormUi->userListWidget->horizontalHeader()->setStretchLastSection(true);\
    userListFormUi->userListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);\
    userListFormUi->userListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);\
    userListFormUi->pageTitle->setAlignment(Qt::AlignCenter);\
    userListFormUi->pageTitle->setText(TXT_MEMBER_LIST);\
    userListFormUi->pageTitle->setStyleSheet(STYLE_FONT_24PIX_BOLD);\

#define BUTTONS_SETUP\
    SET_BTN_ICON(addUserButton,IMG_ADD_USER)\
    SET_BTN_ICON(editUserButton,IMG_CHANGE_USER)\
    SET_BTN_ICON(deleteUserButton,IMG_DELETE_USER)\
    DISABLE_BUTTONS

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
    userListFormUi->userListWidget->horizontalHeader()->setStretchLastSection(true);\
    userListFormUi->userListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);\
    userListFormUi->userListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);\

#define USERS_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    userListFormUi->userListWidget->insertColumn(2);\
    QStringList q3;\
    q3.append(TXT_USER_NAME);\
    q3.append(TXT_HOST);\
    q3.append(TXT_ROLE);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q3);\
    userListFormUi->userListWidget->horizontalHeader()->setStretchLastSection(true);\
    userListFormUi->userListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);\
    userListFormUi->userListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);\
    userListFormUi->pageTitle->setStyleSheet(STYLE_FONT_24PIX_BOLD);\
    userListFormUi->pageTitle->setAlignment(Qt::AlignCenter);\
    userListFormUi->pageTitle->setText(TXT_USER_LIST);\

#define SET_BTN_ICON(btn,iconURI)\
    btnIcon = QIcon(iconURI);\
    userListFormUi->btn->setIcon(btnIcon);\
    userListFormUi->btn->setIconSize(QSize(40, 40));


#endif // MGALISTFORMSETUPS_H
