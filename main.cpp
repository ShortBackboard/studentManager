#include "mainwindow.h"

#include <QApplication>
#include <memory>

using std::make_unique;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto w = make_unique<MainWindow>();
    //w->show();
    return a.exec();
}
