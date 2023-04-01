#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Page_login;
}

class Page_login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_login(QWidget *parent = nullptr);
    ~Page_login();

    //按F5键刷新界面部件样式表
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_login_clicked();

    void on_btn_quit_clicked();

signals:
    //登录成功发送信号
    void sendLoginSuccess();

private:
    Ui::Page_login *ui;
};

#endif // PAGE_LOGIN_H
