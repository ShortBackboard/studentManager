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
    explicit stuSql(QObject *parent = nullptr);

    //初始化数据库
    void initDatabase();

    //查询所有学生数量
    int  getStuNums();

    //查询第几页的学生数据
    //第几页，每页显示多少数据
    QList<Student> getPageStu(quint32 page, quint32 nums);

    //添加学生
    void addStu(Student s);

    //删除学生
    void delStu(int id);

    //清空学生
    void clearStuTable();

    //修改学生
    void updateStu(Student s);

    //查询所有用户
    QList<User> getAllUsersInfo();

    //查询用户是否存在
    bool isUserExist(QString userName);

    //修改用户权限
    void updateUserRights(QString userName,QString right);

    //添加单个用户
    void addUser(User u);

    //删除单个用户
    void delUser(QString userName);

private:
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");

};

#endif // STUSQL_H
