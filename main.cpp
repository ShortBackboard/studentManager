/*
 * 1.简单设计登录界面和主界面
 *
 * 2.数据库逻辑设计
 *
 * 3.界面美化
 *
 * 4.模拟数据并显示到主窗口
 *
 * 5.实现按钮增删改查等功能
 *
 *
 * todo:
 * 6.实现用户登录相关逻辑问题
 * //todo:用户的注册     登录判断用户名密码是否存在
 * //权限问题
 * //多选框和删除的同时使用
 *
 * //rights:manager,user
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


    return a.exec();
}
