#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1.登录界面和主界面的切换
    //显示登录界面
    mPageLogin.show();
    this->show();


    //登录成功进入主界面
    auto LoginSuccess = [&](){
        this->show();
    };

    connect(&mPageLogin, &Page_login::sendLoginSuccess,
            this, LoginSuccess);

    //2.添加设置treeWidget
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderHidden(true);

    QStringList l;
    l<<"学生信息管理系统";

    QTreeWidgetItem *p = new QTreeWidgetItem(ui->treeWidget,l);

    l.clear();
    l<<"管理员管理";
    QTreeWidgetItem *p1 = new QTreeWidgetItem(p,l);

    l.clear();
    l<<"学生管理";
    QTreeWidgetItem *p2 = new QTreeWidgetItem(p,l);

    p->addChild(p1);
    p->addChild(p2);

    ui->treeWidget->expandAll();
   // ui->stackedWidget->setCurrentIndex(0);//默认显示


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Fn + F5 刷新部件样式

    if(event->key() == Qt::Key_F5){
        QFile f;

        //获得的目录路径str是生成可执行文件所在目录
        //auto str = QCoreApplication::applicationDirPath();

        f.setFileName("../studentManager/css/mainQss.css");
        f.open(QIODevice::ReadOnly);

        //读取css文件
        QString strQss = f.readAll();
        qDebug() << strQss;
        this->setStyleSheet(strQss);
    }

}


void MainWindow::on_btn_quit_clicked()
{
    exit(0);
}

