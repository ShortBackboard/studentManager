#include "dlg_updatestu.h"
#include "ui_dlg_updatestu.h"
#include <QMessageBox>
#include <QSqlQuery>

Dlg_updateStu::Dlg_updateStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_updateStu)
{
    ui->setupUi(this);
}

Dlg_updateStu::~Dlg_updateStu()
{
    delete ui;
}

void Dlg_updateStu::on_btn_cel_clicked()
{
    this->hide();
}


void Dlg_updateStu::on_btn_save_clicked()
{
    int searchId = ui->le_id->text().toUInt();

    //先判断学生id是否存在
    auto sql = stuSql::getInstance();

    QSqlQuery q("",sql->m_db);
    QString str = QString("select * from student where stuId = %1").arg(searchId);

    q.exec(str);

    int outcomeId {-1};

    while(q.next()){
        outcomeId = q.value(0).toUInt();
    }

    if(outcomeId >= 0){
        int stuId = ui->le_id->text().toUInt();
        QString name = ui->le_name->text();
        int age = ui->spx_age->text().toUInt();
        QString major = ui->le_major->text();
        QString gender = ui->le_gender->text();
        QString tel = ui->le_tel->text();
        Student s(stuId,name,age,major,gender,tel);

        sql->updateStu(s,outcomeId);

        QMessageBox::information(nullptr,"信息","数据修改成功");
        this->hide();
    }
    else{
        QMessageBox::information(nullptr,"信息","不存在该学生");
    }


}

