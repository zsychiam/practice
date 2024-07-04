#include "gistwidget.h"

GistWidget::GistWidget()
{
    pen = new QPen();
    color = Qt::black;
    pen_pos = new QPoint(0,0);
    pen->setColor(color);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

GistWidget::~GistWidget()
{
    delete pen;
    delete pen_pos;
}

void GistWidget::paintEvent(QPaintEvent *)
{
    if(this->data.empty())
        return;

    double y0;
    double k = (double)(this->width())/(*std::max_element(this->data.begin(),this->data.end()));
    int penWidth = (this->height())/(this->data.size());
    pen->setWidth(penWidth);

    QPainter painter(this);
    painter.begin(this);
    painter.setPen(*pen);

    y0 = penWidth / 2;
    for(int i = 0; i < this->data.size();++i){
        painter.drawLine(0,y0,this->data[i]*k,y0);
        y0 += penWidth;
    }

    painter.end();
}

void GistWidget::givedata()
{
    emit give_vector(data);
}

void GistWidget::erasenum(int index)
{
    if(index >= 0 and index < this->data.size()){
        this->data.erase(this->data.begin() + index);
        this->update();
        emit give_vector(this->data);
    }
    else
        QMessageBox::information(nullptr, "error", "Bad index!");
}

void readfile(std::vector<int>& data_,const std::string& filename)
{
    std::ifstream fin(filename);
    int temp;
    while(fin >> temp)
        data_.push_back(temp);
}

void GistWidget::setdata(std::vector<int>& data_)
{
    this->data = data_;
    this->update();
}

void GistWidget::setdata_json(std::string& filename)
{
    nlohmann::json file = make_json(filename);
    if(!file.empty())
    {
        this->data.clear();
        for (nlohmann::json::iterator it = file.begin(); it != file.end(); ++it)
            this->data.push_back(*it);
        this->update();
    }
    else
        QMessageBox::information(nullptr, "error", "File error!");

}

void GistWidget::savefile(QString& filename)
{
    std::ofstream out(filename.toStdString());
    out << "[";
    for (int i = 0; i < this->data.size(); ++i)
        if(i != this->data.size() - 1)
            out << this->data[i] <<", ";
        else
            out << this->data[i];
    out << "]";
    out.close();
}

void GistWidget::addnum(int num)
{
    this->data.push_back(num);
    this->update();
    emit give_vector(this->data);
}
