#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT
    QCheckBox *checkBoxUnderLine;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBoxBlod;
    QRadioButton *radioButtonRed;
    QRadioButton *radioButtonBlue;
    QRadioButton *radioButtonBlack;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancle;
    QPushButton *pushButtonExit;
    void setupUi();
    void setupSlots();
private slots:
    void setColor();
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
