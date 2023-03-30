#include "user.h"

User::User(int userId, QString password, QString rights):
    m_userId{userId},m_password{password},m_rights{rights}
{}
