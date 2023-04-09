# studentManager

学生信息管理系统

使用的数据库为sqlite3,辅助工具navicat16-sqlite-cs
下载地址:https://www.navicat.com.cn/download/navicat-for-sqlite#lin

构建工具为qmake


项目开发大致流程及说明:

1.简单设计登录界面和主界面,通过登录界面的登录按钮进入到学生信息管理界面;


2.数据库逻辑设计;

2.1 数据库连接大致顺序:
2.1.1 在pro文件中添加 QT += sql
2.1.2 加载驱动
2.1.3 建立连接
2.1.4 执行SQL语句

2.2 学生信息表相关信息:
(           stuId integer not null primary key,
            name text,
            age integer,
            major text,
            gender text,
            tel text
);

2.3 用户信息表相关信息:
(           userId integer not null primary key,
            password text,
            rights text
);


2.4 相关API: 声明在 stusql.h 文件中


3.界面的美化

通过按键F5事件,读取已经写好的css文件,改变窗口组件的样式表;


4.模拟数据生成

4.1 使用QRandomGenerator,生成随机数


5.实现按钮增删改查等功能


6.实现检查用户名和密码登录


7.控制切换StackWidget组件,分别显示学生信息管理和用户信息管理;

8.todo next:

8.1 登录用户的注册功能
8.2 复选框和删除的共同使用
8.3 关于用户信息界面的按钮增删改查等功能
8.4 解决用户信息表主键不唯一的问题
 
 
 
 
 
 
 
 
 
 
 
 
 


