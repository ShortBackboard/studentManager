#include "student.h"

Student::Student(int stuId, QString name, quint16 age, QString major, QString gender, QString tel):
    m_stuId{stuId},m_name{name},m_age{age},
    m_major{major},m_gender{gender},m_tel{tel}
{}
