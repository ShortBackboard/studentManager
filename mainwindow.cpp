#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QCoreApplication>
#include <QRandomGenerator>
#include <QStringList>
#include <QMessageBox>
#include <QSqlQuery>




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


    //第一次初始化加载时
    m_ptrStuSql = stuSql::getInstance();
    auto count =  m_ptrStuSql->getStuNums();

    QList<Student> lStudents = m_ptrStuSql->getPageStu(0,count);


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
        QString str = f.readAll();
        qDebug() << str;
        this->setStyleSheet(str);
    }

}


void MainWindow::on_btn_quit_clicked()
{
    exit(0);
}


void MainWindow::updateDisplay()
{
    //设置表格第一行的内容
    ui->tableWidget->setColumnCount(6);
    QStringList l;
    l<<"学号"<<"姓名"<<"年龄"<<"专业"<<"性别"<<"电话号码";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    //设置只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置只能选择单行
    //ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //设置文本不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);



    //获得所有学生信息,并显示在MainWindow
    auto count =  m_ptrStuSql->getStuNums();
    QList<Student> lStudents = m_ptrStuSql->getPageStu(0,count);

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


void MainWindow::on_btu_simulation_clicked()
{
    //模拟制作学生数据
    //随机生成年龄和电话
    QRandomGenerator age;
    age.seed(0);

    for(int i = 0; i< 20; i++){
        auto ranAge = age.bounded(18,25);//随机数范围,左闭右开
        Student s(i+10,"Tom",ranAge,"C++","Man","133");
        m_ptrStuSql->addStu(s);
    }

    updateDisplay();

}




void MainWindow::on_btn_add_clicked()
{
    //模态对话框（Modal Dialogue Box，又叫做模式对话框），是指在用户想要对对话框以外的应用程序进行操作时，必须首先对该对话框进行响应。
    m_dialogAddStu.exec();


    //添加数据以后重新更新数据
    updateDisplay();
}




void MainWindow::on_btn_clear_clicked()
{
    auto sql = stuSql::getInstance();
    sql->clearStuTable();

    //清空数据
    ui->tableWidget->clear();

    updateDisplay();
}




void MainWindow::on_btu_del_clicked()
{
    //row是行(横为行),column是列(竖为列),cell是单元格,即行和列交叉的部分。

    //获得当前行
    int i = ui->tableWidget->currentRow();

    if(i >= 0){
        int id = ui->tableWidget->item(i,0)->text().toUInt();
        m_ptrStuSql->delStu(id);
        updateDisplay();
        QMessageBox::information(nullptr,"信息","数据删除成功");
    }
}


void MainWindow::on_btu_update_clicked()
{
    //判断id是否存在，不存在就发出信息
    m_dialogUpdateStu.exec();

    //修改数据以后重新更新数据
    updateDisplay();

}


void MainWindow::on_btn_search_clicked()
{
    int searchId = ui->le_search->text().toUInt();

    auto sql = stuSql::getInstance();
    QSqlQuery q("",sql->m_db);
    QString str = QString("select * from student where stuId = %1").arg(searchId);

    q.exec(str);

    int outcomeId {-1};

    while(q.next()){
        outcomeId = q.value(0).toUInt();
    }

    if(outcomeId >= 0){
        QList<Student> lStudents = sql->selectStu(outcomeId);
        auto count =  m_ptrStuSql->getStuNums();

        //更新显示的数据
        //设置表格第一行的内容
        ui->tableWidget->setColumnCount(6);
        QStringList l;
        l<<"学号"<<"姓名"<<"年龄"<<"专业"<<"性别"<<"电话号码";
        ui->tableWidget->setHorizontalHeaderLabels(l);

        //设置只选中行
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        //设置只能选择单行
        //ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

        //设置文本不可编辑
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        //初始化行数为1
        ui->tableWidget->setRowCount(1);

        //2.显示查找出来的学生信息
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(lStudents[0].m_stuId)));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(lStudents[0].m_name));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QTableWidgetItem(QString::number(lStudents[0].m_age))));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(lStudents[0].m_major));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(lStudents[0].m_gender));
            ui->tableWidget->setItem(0,5,new QTableWidgetItem(lStudents[0].m_tel));

        ui->lb_count->setText(QString("学生总数:%1").arg(count));
    }
    else{
        QMessageBox::information(nullptr,"信息","该学生不存在");
    }

}

