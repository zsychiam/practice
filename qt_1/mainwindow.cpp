#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openDiagramButton, &QPushButton::clicked, this, &MainWindow::OnOpenDiagramClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnOpenDiagramClick() {
    std::string path = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt").toStdString();
    std::ifstream fin(path);
    fin >> (*ui->diagram);
    this->update();
}

