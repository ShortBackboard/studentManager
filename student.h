//学生类

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <QObject>

class Student{
public:
    Student();

    Student(int stuId,QString name,quint16 age,QString major,
            QString gender,QString tel);

    int m_stuId;
    QString m_name;
    quint16 m_age;
    QString m_major;
    QString m_gender;
    QString m_tel;
};

#endif // STUDENT_H
