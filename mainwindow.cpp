#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //显示登录界面
    mPageLogin.show();


    //登录成功进入主界面
    auto LoginSuccess = [&](){
        this->show();
    };

    connect(&mPageLogin, &Page_login::sendLoginSuccess,
            this, LoginSuccess);
}

MainWindow::~MainWindow()
{
    delete ui;
}

