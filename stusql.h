/*
 * 学生表和用户表数据库相关操作
*/

#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QList>
#include <QSqlDatabase>

#include "student.h"
#include "user.h"

class stuSql : public QObject
{
    Q_OBJECT

public:
    //使用单例模式
    static stuSql* ptrStuSql;
    static stuSql* getInstance();


public:
    explicit stuSql(QObject *parent = nullptr);



    //初始化数据库
    void initDatabase();

    //查询所有学生数量
    int getStuNums();


    //把所有数据分成多少页，每页显示多少数据，页数从0开始数
    QList<Student> getPageStu(quint32 page, quint32 nums);

    //添加学生
    void addStu(Student s);

    //删除学生
    void delStu(int id);

    //清空学生
    void clearStuTable();

    //修改学号为id的学生信息
    void updateStu(Student s, int Id);

    //查找学号为id的学生
    QList<Student> selectStu(int id);

    //查询所有用户
    QList<User> getAllUsersInfo();

    //查询用户是否存在
    bool isUserExist(int userId);

    //修改用户权限
    void updateUserRights(int Id,QString right);

    //添加单个用户
    void addUser(User u);

    //删除单个用户
    void delUser(int id);


    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");

};

#endif // STUSQL_H
