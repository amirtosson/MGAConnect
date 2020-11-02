#ifndef MGALISTFORMSETUPS_H
#define MGALISTFORMSETUPS_H

#define USER_LIST_FORM_SETUP\
    userListFormUi->userListWidget->insertColumn(0);\
    userListFormUi->userListWidget->insertColumn(1);\
    userListFormUi->userListWidget->insertColumn(2);\
    userListFormUi->userListWidget->insertColumn(3);\
    QStringList q;\
    q.append(TXT_FIRST_NAME);\
    q.append(TXT_LAST_NAME);\
    q.append(TXT_UNIVERSITY_NAME);\
    q.append(TXT_EMAIL);\
    userListFormUi->userListWidget->setHorizontalHeaderLabels(q);\
    userListFormUi->userListWidget->horizontalHeader()->setStretchLastSection(true);\
    userListFormUi->userListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);\
    userListFormUi->userListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);\


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



#endif // MGALISTFORMSETUPS_H
