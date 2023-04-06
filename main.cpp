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
 * 6.实现检查用户名和密码登录
 *
 * 7.控制切换StackWidget
 *
 * 8.
 *
 *
 * todo:
 * //1.用户的注册
 * //2.多选框和删除的同时使用
 * //3.用户
 * //4.解决用户账号主键的问题
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
