#include "dlg_addstu.h"
#include "ui_dlg_addstu.h"
#include "stusql.h"
#include <QMessageBox>
#include <QSqlQuery>

Dlg_AddStu::Dlg_AddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddStu)
{
    ui->setupUi(this);
}

Dlg_AddStu::~Dlg_AddStu()
{
    delete ui;
}


void Dlg_AddStu::on_btn_save_clicked()
{

    //先判断学生id是否重复

    int addId = ui->le_id->text().toUInt();

    auto sql = stuSql::getInstance();

    QSqlQuery q("",sql->m_db);
    QString str = QString("select * from student where stuId = %1").arg(addId);

    q.exec(str);

    int outcomeId {-1};

    while(q.next()){
        outcomeId = q.value(0).toUInt();
    }

    if(outcomeId >= 0){
        QMessageBox::information(nullptr,"信息","该学生已存在");
    }
    else{
    Student s(ui->le_id->text().toUInt(), ui->le_name->text(),
              ui->spx_age->text().toUInt(), ui->le_major->text(),
              ui->le_gender->text(), ui->le_tel->text());

        sql->addStu(s);

        QMessageBox::information(nullptr,"信息","数据添加成功");

        this->hide();
    }

}





void Dlg_AddStu::on_btn_cel_clicked()
{
    this->hide();
}

