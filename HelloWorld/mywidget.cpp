#include "mywidget.h"

#include <QPushButton>
#include <QLabel>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton(this);
    button->setText("hello world");
//    QLabel *label = new QLabel(this);
//    label->setText("<h1><a href = \"https://www.baidu.com\">www.baidu.com</a></h1>");
    this->resize(500, 500);
    button->move(200, 200);
    connect(button, &QPushButton::clicked, [button](){
        button->setStyleSheet("QPushButton {color: red;}");
    });
}

MyWidget::~MyWidget()
{
}

