//用户类

#ifndef USER_H
#define USER_H
#include <iostream>
#include <QObject>

class User{
public:
    User(int userId,QString password,QString rights);
    int  m_userId;
    QString m_password;
    QString m_rights;

};

#endif // USER_H
