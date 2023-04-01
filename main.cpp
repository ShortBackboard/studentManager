/*
 * 1.简单设计登录界面和主界面
 *
 * 2.数据库逻辑设计
 *
 * 3.界面美化
 *
*/
#include "mainwindow.h"

#include <QApplication>
#include <memory>

#include "stusql.h"

using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto w = make_unique<MainWindow>();

    stuSql stusql;



    return a.exec();
}
