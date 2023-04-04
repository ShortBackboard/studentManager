#ifndef DLG_UPDATESTU_H
#define DLG_UPDATESTU_H

#include <QDialog>
#include "stusql.h"

namespace Ui {
class Dlg_updateStu;
}

class Dlg_updateStu : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_updateStu(QWidget *parent = nullptr);
    ~Dlg_updateStu();

private slots:
    void on_btn_cel_clicked();

    void on_btn_save_clicked();

private:
    Ui::Dlg_updateStu *ui;
};

#endif // DLG_UPDATESTU_H
