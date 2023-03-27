#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class Page_login;
}

class Page_login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_login(QWidget *parent = nullptr);
    ~Page_login();

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
