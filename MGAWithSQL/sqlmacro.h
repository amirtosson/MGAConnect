#ifndef SQLMACRO_H
#define SQLMACRO_H

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "cppconn/sqlstring.h"
#include "cppconn/exception.h"
#include "cppconn/prepared_statement.h"
#include <QString>
#include <QDebug>


#define SQLQUERY std::string
#define SQLSTRING sql::SQLString

#define MGA_DATABASE_NAME "MGA_DataBase"

//the same alias as in sql DB
#define TXT_ROLE          "role"
#define ADMIN_ROLE        "admin"
#define USER_ROLE         "user"
#define GUEST_ROLE        "guest"
#define STUDENT_ROLE      "student"
#define UNKNOWN_ROLE      "unknown"

//====================================

#define SERIALIZE_USER_ROLE\
    START_GETTING_DATA\
        sCurrentUserRoleName = GET_COLOUMN_BY_ALIAS_AS_QSTRING(TXT_ROLE);\
    END_GETTING_DATA\
    if(sCurrentUserRoleName == ADMIN_ROLE) eCurrentUserRole = eAdmin;\
    else if (sCurrentUserRoleName == USER_ROLE) eCurrentUserRole = eUser;\
    else if (sCurrentUserRoleName == GUEST_ROLE) eCurrentUserRole = eGuest;\
    else if (sCurrentUserRoleName == STUDENT_ROLE) eCurrentUserRole = eStudent;\
    else eCurrentUserRole = eUNKNOWN;

#define SQL_ERROR_HANDEL(V)\
    try{\
        V\
    } catch(...){\
    qDebug() << "UNKNOWN ERROR" << endl;\
    }

#define DECLAIR_SQL_REQUIRED_MEMBERS\
    sql::Driver *driver;\
    sql::Connection *con;\
    sql::Statement *stmt;\
    sql::PreparedStatement *pstmt;\
    sql::ResultSet *res;

#define CLEAN_SQL_MEMORY\
    if(res  !=NULL) delete res;\
    if(stmt !=NULL) delete stmt;\
    if(con  !=NULL) delete con;\
    if(pstmt!=NULL) delete pstmt;

#define CONNECT_TO_SQL_DRIVER(DBtcp,UserName,Pwd)\
    driver = get_driver_instance();\
    con = driver->connect(DBtcp,UserName,Pwd);\
    CREATE_STATMENT\
    GET_USER_ROLE(UserName)
//con->setSchema(MGA_DATABASE_NAME);
//"tcp://127.0.0.1:3306"

#define GET_MEMEBR_WITH_COLNAME(V)\
        SQLQUERY("SELECT * FROM mga_members WHERE ") +SQLQUERY(V) + SQLQUERY(" = ?");

#define GET_MEMEBRS_COUNTS\
        con->setSchema(MGA_DATABASE_NAME);\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT count(*) FROM mga_members")));\
        START_GETTING_DATA\
        nMemberCount = res->getInt(1);\
        END_GETTING_DATA

#define GET_MGA_MEMEBRS\
        con->setSchema(MGA_DATABASE_NAME);\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT lastName, firstName, eMail, universityName FROM mga_members")));\

#define GET_USERS_COUNTS\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT count(*) FROM mysql.user")));\
        START_GETTING_DATA\
        nUserCount = res->getInt(1);\
        END_GETTING_DATA

#define ADD_NEW_USER(N,H,P,R)\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("CREATE User '") + SQLQUERY(N)+ SQLQUERY("'@'")+ SQLQUERY(H)+ SQLQUERY("' IDENTIFIEd BY '")+ SQLQUERY(P) + SQLQUERY("'; ")));\



#define GET_DATABASES\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT SHOW databases")));\

#define GET_USERS\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT user, host, role FROM mysql.user")));\

#define GET_USER_ROLE(U)\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT role FROM mysql.user WHERE user = '") + SQLQUERY(U) + SQLQUERY("' ")));

#define PREPARED_STATMENT(stmt)\
        pstmt = con->prepareStatement(stmt);

#define SET_VARIABLE(V)\
        pstmt->setString(1,SQLQUERY(V));

#define CREATE_STATMENT\
        stmt = con->createStatement();

#define SQL_EXECUTE_QUERY\
        res = pstmt->executeQuery();

#define SQL_DIRECT_EXECUTE_QUERY(col,V)\
        res = stmt->executeQuery(SQLSTRING(SQLQUERY("SELECT * FROM mga_members WHERE ") +SQLQUERY(col) + SQLQUERY(" =  '") + SQLQUERY(V) + SQLQUERY("' ")));

#define SECURED_SQL_DIRECT_EXECUTE_QUERY(col,V)\
        SQL_ERROR_HANDEL(SQL_DIRECT_EXECUTE_QUERY(col,V))\

#define GET_COLOUMN_BY_ALIAS_AS_STRING(col)\
        res->getString(SQLQUERY(col)).asStdString()

#define GET_COLOUMN_BY_ALIAS_AS_QSTRING(col)\
        QString::fromStdString(GET_COLOUMN_BY_ALIAS_AS_STRING(col));

#define GET_COLOUMN_BY_NUMERIC_OFFSET_AS_STRING(col)\
        res->getString(col).asStdString()

#define GET_COLOUMN_BY_NUMERIC_OFFSET_AS_QSTRING(col)\
        QString::fromStdString(GET_COLOUMN_BY_NUMERIC_OFFSET_AS_STRING(col));


#define START_GETTING_DATA\
        if(res->rowsCount() > 0){\
            while (res->next()) {

#define END_GETTING_DATA\
        }};

#define INSERT_NEW_MGA_MEMBER\
        SQLQUERY("INSERT INTO mga_members(lastName, firstName, eMail, universityName, passWord)\
                VALUES( ?,?,?,?,?)");

#define SET_MEMBER_VALUES(lastName, firstName, eMail, universityName,passWord)\
        pstmt->setString(1, SQLQUERY(lastName));\
        pstmt->setString(2, SQLQUERY(firstName));\
        pstmt->setString(3, SQLQUERY(eMail));\
        pstmt->setString(4, SQLQUERY(universityName));\
        pstmt->setString(5, SQLQUERY(passWord));

#define SQL_EXCUTE_UPDATE\
        pstmt->executeUpdate();


#define UPDATE_USER_ROLE(R,U)\
        SQLQUERY("UPDATE mysql.user SET role =")+SQLQUERY(R)+ SQLQUERY("WHERE user =")+ SQLQUERY(U);


#endif // SQLMACRO_H
