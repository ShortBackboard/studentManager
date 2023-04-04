QT       += core gui
QT += sql   #使用数据库

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_addstu.cpp \
    dlg_updatestu.cpp \
    main.cpp \
    mainwindow.cpp \
    page_login.cpp \
    student.cpp \
    stusql.cpp \
    user.cpp


HEADERS += \
    dlg_addstu.h \
    dlg_updatestu.h \
    mainwindow.h \
    page_login.h \
    student.h \
    stusql.h \
    user.h


FORMS += \
    dlg_addstu.ui \
    dlg_updatestu.ui \
    mainwindow.ui \
    page_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

