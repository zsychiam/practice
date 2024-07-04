#include "mainwindow.h"

#include <QApplication>
#include "single_include/nlohmann/json.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
