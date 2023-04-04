//增加学生功能的对话框

#ifndef DLG_ADDSTU_H
#define DLG_ADDSTU_H

#include <QDialog>

namespace Ui {
class Dlg_AddStu;
}

class Dlg_AddStu : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddStu(QWidget *parent = nullptr);
    ~Dlg_AddStu();

private slots:
    void on_btn_save_clicked();


    void on_btn_cel_clicked();

private:
    Ui::Dlg_AddStu *ui;
};

#endif // DLG_ADDSTU_H
