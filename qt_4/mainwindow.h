#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "single_include/nlohmann/json.hpp"
#include "gistwidget.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

#include <vector>
#include <fstream>
#include <filesystem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read_json(std::string&);
    void read_json(QString&);

public slots:
    void print_textedit(std::vector<int>&);
signals:
    void print();
    void pushnum(int);
    void erasenum(int);
    void get_filename(QString&);
private slots:
    void on_openAction_triggered();

    void on_saveHowAction_triggered();

    void on_addButton_clicked();

    void on_eraseButton_clicked();

private:
    Ui::MainWindow *ui;
    GistWidget* gistwidget;
};

bool is_number(const std::string& s);

#endif
