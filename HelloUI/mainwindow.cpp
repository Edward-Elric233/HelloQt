#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , subWin(new SubWin(nullptr))
{
    ui->setupUi(this);
    ui->pushButton->setText("子窗口");
    connect(ui->pushButton, &QPushButton::clicked, [this](){
        this->hide();
        subWin->show();
    });
    connect(subWin, &SubWin::isClicked, [this](){
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

