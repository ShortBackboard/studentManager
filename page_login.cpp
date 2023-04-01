#include "page_login.h"
#include "ui_page_login.h"
#include <QFile>

Page_login::Page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_login)
{
    ui->setupUi(this);
}

Page_login::~Page_login()
{
    delete ui;
}

void Page_login::keyPressEvent(QKeyEvent *event)
{
    //Fn + F5 刷新部件样式

    if(event->key() == Qt::Key_F5){
        QFile f;

        f.setFileName("../studentManager/css/loginQss.css");
        f.open(QIODevice::ReadOnly);

        //读取css文件
        QString strQss = f.readAll();
        qDebug() << strQss;
        setStyleSheet(strQss);

    }
}




void Page_login::on_btn_login_clicked()
{
    //数据库查找用户名和密码

    //失败就提示

    //成功就进入主页面

    //发送信号
    emit sendLoginSuccess();
}


void Page_login::on_btn_quit_clicked()
{
    exit(0);
}

