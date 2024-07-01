#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pen = new QPen();
    pen_pos = new QPoint(0, 0);
    pen->setColor(Qt::blue);

    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pen;
    delete pen_pos;
}

void MainWindow::paintEvent(QPaintEvent * event) {
    if (stack.is_empty())
        return;

    QPainter painter(this);
    painter.begin(this);

    std::vector<int> points;
    stack.to_vec(points);

    double diagram_width = this->width();
    double diagram_height = this->height();
    double interval = diagram_height / (stack.get_size() + 1);
    double position_y = interval;
    int max_height = *std::max_element(points.begin(), points.end());

    pen->setColor(Qt::red);
    pen->setWidth(interval / 4);
    painter.setPen(*pen);

    for (auto i : points) {
        double width = (static_cast<double>(i) / max_height) * (diagram_width - 40) - diagram_width / 20;
        painter.drawLine(0, position_y, width, position_y);
        position_y += interval;
    }

    pen->setColor(Qt::black);
    pen->setWidth(3);
    painter.setPen(*pen);
    position_y = interval - 10;
    for (auto i : points) {
        double width = (static_cast<double>(i) / max_height) * (diagram_width - 40);
        painter.drawText(width + 10, position_y + pen->width() * 4, (new QString())->fromStdString(std::to_string(i)));
        position_y += interval;
    }

    painter.end();
}

void MainWindow::on_PopButton_clicked()
{
    stack.pop();
    this->update();
}


void MainWindow::on_PushButton_clicked()
{
    stack.push(ui->lineEdit->text().toInt());
    this->update();
}

