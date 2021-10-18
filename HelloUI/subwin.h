#ifndef SUBWIN_H
#define SUBWIN_H

#include <QMainWindow>
#include <QPushButton>

class SubWin : public QMainWindow
{
    Q_OBJECT
public:
    explicit SubWin(QWidget *parent = nullptr);

private:
    QPushButton *button;

signals:
    void isClicked();

};

#endif // SUBWIN_H
