#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "page_login.h"
#include "stusql.h"

#include "dlg_addstu.h"//添加学生信息对话框
#include "dlg_updatestu.h"

#include <QDebug>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //按键刷新界面部件样式表
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_quit_clicked();

    void on_btu_simulation_clicked();

    void on_btn_add_clicked();

    void on_btn_clear_clicked();

    void on_btu_del_clicked();

    void on_btu_update_clicked();

    void on_btn_search_clicked();

    //QTreeWidget与QStackedWidget的关联操作
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

public:
    //更新显示数据
    void updateDisplay();

private:
    Ui::MainWindow *ui;
    Page_login mPageLogin;
    stuSql* m_ptrStuSql;
    Dlg_AddStu m_dialogAddStu;
    Dlg_updateStu m_dialogUpdateStu;
};
#endif // MAINWINDOW_H
