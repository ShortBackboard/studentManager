#include "page_login.h"
#include "ui_page_login.h"
#include <QFile>

Page_login::Page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_login)
{
    ui->setupUi(this);
    m_ptrStuSql = stuSql::getInstance();
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
    int curId = ui->le_username->text().toUInt();
    QString curPass = ui->le_password->text();

    //数据库查找用户名和密码
    QList<User> l = m_ptrStuSql->getAllUsersInfo();

    int flag = 1;
    for(int i = 0; i < l.size(); i++){
        if( curId == l[i].m_userId && l[i].m_password == curPass){
            //成功就发送信号,进入到主窗口界面
            flag = 0;
            emit sendLoginSuccess();
        }
    }

    if(flag ==1) QMessageBox::information(nullptr,"信息","账号密码错误");

}


void Page_login::on_btn_quit_clicked()
{
    exit(0);
}

