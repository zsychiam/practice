#ifndef GISTWIDGET_H
#define GISTWIDGET_H

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "single_include/nlohmann/json.hpp"
#include "json.h"

#include <QTimer>
#include <QPainter>
#include <QLineF>
#include <QString>
#include <QWidget>
#include <QObject>

#include <QObject>
#include <QWidget>
#include <QMessageBox>

class GistWidget : public QWidget
{
    Q_OBJECT
public:
    GistWidget();
    ~GistWidget();
    void setdata(std::vector<int>&);
    void setdata_json(std::string&);
public slots:
    void givedata();
    void savefile(QString&);
    void addnum(int);
    void erasenum(int);
signals:
    void give_vector(std::vector<int>&);
protected:
    void paintEvent(QPaintEvent* event);
private:
    std::vector<int> data;
    QPen* pen;
    QColor color;
    QPoint* pen_pos;
};

void readfile(std::vector<int>&,const std::string&);
#endif
