#include "diagram.h"

Diagram::Diagram(QWidget* parent) : QWidget(parent)
{
    pen = new QPen();
}

std::istream& operator>>(std::istream& in, Diagram& diagram) {
    diagram.points.clear();
    int height{};
    diagram.max_height = 0;
    while (in >> height) {
        diagram.points.push_back(height);
        diagram.max_height = std::max(diagram.max_height, height);
    }
    diagram.update();
    return in;
}

void Diagram::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.begin(this);

    double diagram_width = this->width();
    double diagram_height = this->height();
    double interval = diagram_height / (points.size() + 1);
    double position_y = interval;


    pen->setColor(Qt::red);
    pen->setWidth(interval / 4);
    painter.setPen(*pen);

    for (auto i : points) {
        double width = (static_cast<double>(i) / max_height) * (diagram_width - 40);
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

