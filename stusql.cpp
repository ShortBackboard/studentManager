#include "stusql.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>



stuSql::stuSql(QObject *parent)
    : QObject{parent}
{
    initDatabase();
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
        qDebug() << "database open success";
    }

    //执行SQL语句
    //创建学生表和用户表


    QSqlQuery q("",m_db);
    q.exec("DROP TABLE IF EXISTS student");
    q.exec("CREATE TABLE student (stuId integer not null primary key, "
           "name text, age integer,"
           "major text, gender text, tel text)");

    //q.exec("INSERT INTO student VALUES(001,'张三',"
    //       "18,'软件工程','男','17388208702')");

    q.exec("DROP TABLE IF EXISTS user");
    q.exec("CREATE TABLE user (userId integer,"
            "password text,"
            "rights text)");


    //q.exec("INSERT INTO user VALUES(1,'a','a')");
}



int  stuSql::getStuNums()
{

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
    qDebug() << q.exec(strSql);

}







