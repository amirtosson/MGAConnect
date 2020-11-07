#ifndef MGAUSERROLESENUM_H
#define MGAUSERROLESENUM_H

extern "C" enum EUserRole
{
    eAdmin,
    eUser,
    eGuest,
    eStudent,
    eUNKNOWN
};

#define TXT_ADMIN_ROLE        "Admin"
#define TXT_USER_ROLE         "User"
#define TXT_GUEST_ROLE        "Guest"
#define TXT_STUDENT_ROLE      "Student"

//the same alias as in sql DB
#define ADMIN_ROLE        "admin"
#define USER_ROLE         "user"
#define GUEST_ROLE        "guest"
#define STUDENT_ROLE      "student"

#endif // MGAUSERROLESENUM_H
