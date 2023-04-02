#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QCoreApplication>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStuSql(nullptr)
{
    ui->setupUi(this);

    //1.登录界面和主界面的切换
    //显示登录界面
    mPageLogin.show();
    //this->show();


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

    m_ptrStuSql = stuSql::getInstance();

    //获得所有学生信息,并显示在MainWindow
    auto count =  m_ptrStuSql->getStuNums();
    QList<Student> lStudents = m_ptrStuSql->getPageStu(0,count);

    //ui->tableWidget->clear();

    //1.初始化行数，为数据库中学生的数量
    ui->tableWidget->setRowCount(count);


    //2.显示数据中的学生信息
    for(int i = 0; i < lStudents.size(); i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lStudents[i].m_stuId)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lStudents[i].m_name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QTableWidgetItem(QString::number(lStudents[i].m_age))));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lStudents[i].m_major));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(lStudents[i].m_gender));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(lStudents[i].m_tel));
    }


    ui->lb_count->setText(QString("学生总数:%1").arg(count));




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


void MainWindow::on_btu_simulation_clicked()
{
    //模拟制作学生数据
    //随机生成年龄和电话
    QRandomGenerator age;
    age.seed(0);

    for(int i = 0; i< 10; i++){
        auto ranAge = age.bounded(18,25);//左闭右开
        Student s(i+10,"Tom",ranAge,"C++","Man","133");
        m_ptrStuSql->addStu(s);
    }
}







