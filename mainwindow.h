#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "page_login.h"

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

private:
    Ui::MainWindow *ui;
    Page_login mPageLogin;
};
#endif // MAINWINDOW_H
