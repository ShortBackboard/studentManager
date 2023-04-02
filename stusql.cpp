#include "stusql.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>


//初始化
stuSql* stuSql::ptrStuSql = nullptr;

stuSql *stuSql::getInstance()
{
    if(nullptr == ptrStuSql){//规范化
        ptrStuSql = new stuSql;
    }

    return ptrStuSql;
}

stuSql::stuSql(QObject *parent)
    : QObject{parent}
{
    initDatabase();

    //测试SQL语句

    //Student s1(1,"Tom",18,"SCI","Man","123");
    //Student s2(2,"Tom",18,"SCI","Man","123");
    //Student s3(3,"Tom",18,"SCI","Man","123");
    //addStu(s1);
    //addStu(s2);
    //addStu(s3);
    //getPageStu(1,1);
    //delStu(1);
    //updateStu(s1,2);
    //bool a = isUserExist(1);
    //User u(1,"123","a");
    //addUser(u);
    //updateUserRights(1,"b");
    //delUser(1);


}


void stuSql::initDatabase()
{
    //加载驱动
    if (QSqlDatabase::drivers().isEmpty())
        QMessageBox::information(nullptr, tr("No database drivers found"),
                                 tr("This demo requires at least one Qt database driver. Please check the documentation how to build the Qt SQL plugins."));


    //建立连接
    //QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/run/media/root/work/my_Projects/studentManager/stuManager.db");//path

    if (!m_db.open()){
        QMessageBox::warning(nullptr, tr("Unable to open database"), tr("An error occurred while opening the connection: ") + m_db.lastError().text());
    }else{
        qDebug() << "database open successfully!";
    }

    //执行SQL语句
    //创建学生表和用户表


    QSqlQuery q("",m_db);
    //q.exec("DROP TABLE IF EXISTS student");
    q.exec("CREATE TABLE IF NOT EXISTS student (stuId integer not null primary key, "
           "name text, "
           "age integer,"
           "major text, "
           "gender text, "
           "tel text)");

    //q.exec("INSERT INTO student VALUES(001,'张三',"
    //       "18,'软件工程','男','17388208702')");

    //q.exec("DROP TABLE IF EXISTS user");
    q.exec("CREATE TABLE IF NOT EXISTS user (userId integer,"
            "password text,"
            "rights text)");


    //q.exec("INSERT INTO user VALUES(1,'a','a')");
}



int  stuSql::getStuNums()
{
    QSqlQuery q("",m_db);
    q.exec("select count(stuId) from student");

    int nums{0};
    while(q.next()){
        nums = q.value(0).toUInt();
    }

    return nums;
}


//把所有数据分成多少页，每页显示多少数据，页数从0开始数
QList<Student> stuSql::getPageStu(quint32 page, quint32 nums)
{
    QList<Student> l;
    QSqlQuery q("",m_db);

    //offset 代表从第几条记录“之后”开始查询，limit 代表查询多少条
    QString strSql = QString("select * from student order by stuId limit %1 "
                          "offset %2;").arg(nums).arg(page*nums);
    q.exec(strSql);

    while(q.next()){

        int stuId = q.value(0).toUInt();
        QString name = q.value(1).toString();
        int age = q.value(2).toUInt();
        QString major = q.value(3).toString();
        QString gender = q.value(4).toString();
        QString tel = q.value(5).toString();
        Student s(stuId,name,age,major,gender,tel);

        l.push_back(s);
    }


    return l;
}



void stuSql::addStu(Student s)
{
    //注意：字符要加单引号

    QSqlQuery q("",m_db);
    QString strSql = QString("INSERT INTO student"
                             " VALUES(%1,'%2',%3,'%4','%5','%6')")
                         .arg(s.m_stuId)
                         .arg(s.m_name)
                         .arg(s.m_age)
                         .arg(s.m_major)
                         .arg(s.m_gender)
                         .arg(s.m_tel);

    //执行sql语句
    if(q.exec(strSql))  qDebug() << "addStu successfully";

}

void stuSql::delStu(int id)
{
    QSqlQuery q("",m_db);
    QString strSql = QString("delete from student where stuId = %1").arg(id);
    //执行sql语句
    if(q.exec(strSql))  qDebug() << "deleteStu successfully";
}


void stuSql::clearStuTable()
{
    QSqlQuery q("",m_db);
    QString strSql = QString("delete from student");

    //执行sql语句
    if(q.exec(strSql))  qDebug() << "clearStuTable successfully";
}


void stuSql::updateStu(Student s,int Id)
{
    QSqlQuery q("",m_db);
    QString strSql = QString("update student  set stuId = %1,  name = '%2', "
                             "age = %3, major = '%4', gender = '%5', tel = '%6'"
                             "where stuId = %7")
                         .arg(s.m_stuId)
                         .arg(s.m_name)
                         .arg(s.m_age)
                         .arg(s.m_major)
                         .arg(s.m_gender)
                         .arg(s.m_tel)
                         .arg(Id);



    //执行sql语句
    if(q.exec(strSql))  qDebug() << "updateStu successfully";
}



QList<User> stuSql::getAllUsersInfo()
{
    QList<User> l;
    QSqlQuery q("",m_db);


    QString strSql = QString("select * from user");

    q.exec(strSql);

    while(q.next()){
        int Id = q.value(0).toUInt();
        QString password = q.value(1).toString();
        QString right = q.value(5).toString();
        User u(Id,password,right);

        l.push_back(u);
    }


    return l;
}


bool stuSql::isUserExist(int userId)
{
    QSqlQuery q("",m_db);
    QString strSql = QString("select * from user where userId = %1").arg(userId);
    q.exec(strSql);

    if(!q.next()) qDebug() << "User NotExist";

    return q.next();
}


void stuSql::updateUserRights(int Id, QString right)
{
    QSqlQuery q("",m_db);
    QString strSql = QString("update user set rights = '%1' "
                             "where userId = %2")
                            .arg(right)
                            .arg(Id);

    if(q.exec(strSql)) qDebug() << "updateUserRights successfully";


}


void stuSql::addUser(User u)
{
    //注意：字符要加单引号

    QSqlQuery q("",m_db);
    QString strSql = QString("INSERT INTO user"
                             " VALUES(%1,'%2','%3')")
                         .arg(u.m_userId)
                         .arg(u.m_password)
                         .arg(u.m_rights);

    //执行sql语句
    if(q.exec(strSql))  qDebug() << "addUser successfully";
}


void stuSql::delUser(int id)
{
    QSqlQuery q("",m_db);
    QString strSql = QString("delete from user where userId = %1").arg(id);
    //执行sql语句
    if(q.exec(strSql))  qDebug() << "deleteUser successfully";
}



















