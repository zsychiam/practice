#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->gistwidget = new GistWidget();
    this->ui->text_grid_layout->addWidget(this->gistwidget);
    connect(this,&MainWindow::print,this->gistwidget,&GistWidget::givedata);
    connect(this->gistwidget,&GistWidget::give_vector,this,&MainWindow::print_textedit);
    connect(this,&MainWindow::get_filename,this->gistwidget,&GistWidget::savefile);
    connect(this,&MainWindow::pushnum,this->gistwidget,&GistWidget::addnum);
    connect(this,&MainWindow::erasenum,this->gistwidget,&GistWidget::erasenum);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gistwidget;
}

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(),[](const char& c){return !std::isdigit(c);}) == s.end();
}


void MainWindow::read_json(std::string& filename)
{
    this->gistwidget->setdata_json(filename);
}

void MainWindow::read_json(QString& filename)
{
    std::string str = filename.toStdString();
    this->read_json(str);
}

void MainWindow::print_textedit(std::vector<int>& data)
{
    QString result = "";
    for(int i = 0;i < data.size(); ++i)
        result += QString::number(data[i]) + "\n";
    this->ui->output_textEdit->setText(result);
}

void MainWindow::on_openAction_triggered()
{
    QString filename = QFileDialog::getOpenFileName(0,"Open dialog","","*.json");
    this->read_json(filename);
    emit print();
}

void MainWindow::on_addButton_clicked()
{
    if(!(this->ui->addLineEdit->text() == "") ){
        if(is_number(this->ui->addLineEdit->text().toStdString()))
            emit pushnum(this->ui->addLineEdit->text().toInt());
        else
            QMessageBox::information(nullptr, "error", "Empty input or less than zero input!");
    }

    this->ui->addLineEdit->clear();
}

void MainWindow::on_saveHowAction_triggered()
{
    QString filename = QFileDialog::getSaveFileName(0,"Open dialog","","*.json");
    emit get_filename(filename);
}

void MainWindow::on_eraseButton_clicked()
{
    if(!(this->ui->eraseLineEdit->text() == ""))
        if(is_number(this->ui->eraseLineEdit->text().toStdString()))
            if(this->ui->eraseLineEdit->text().toInt() >= 0)
                emit SignalErasehNum(this->ui->eraseLineEdit->text().toInt());
            else
                QMessageBox::information(nullptr, "error", "Input less than zero!");
        else
            QMessageBox::information(nullptr, "Mistake", "Wrong input!");
    this->ui->eraseLineEdit->clear();
}