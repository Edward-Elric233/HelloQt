#include "subwin.h"

SubWin::SubWin(QWidget *parent) : QMainWindow(parent)
  , button(new QPushButton(this))
{
    button->setText("主窗口");
    resize(300, 300);
    button->move(100, 100);
    connect(button, &QPushButton::clicked, [this](){
        this->hide();
        emit isClicked();
    });
}
