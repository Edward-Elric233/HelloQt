#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButtonBlack, &QRadioButton::clicked, this, &Dialog::setTextColor);
    QObject::connect(ui->radioButtonRed, &QRadioButton::clicked, this, &Dialog::setTextColor);
    QObject::connect(ui->radioButtonBlue, &QRadioButton::clicked, this, &Dialog::setTextColor);
}

Dialog::~Dialog()
{
    delete ui;
}


/*!
 * \brief Dialog::on_checkBoxUnderLine_clicked，通过QMetaObject::connectSoltsByName函数进行信号和槽的绑定
 * \param checked 单选框有没有被点击
 */
void Dialog::on_checkBoxUnderLine_clicked(bool checked)
{
    //改变文本框中的字体有下划线
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::setTextColor()
{
    QPalette palette = ui->plainTextEdit->palette();	//获取调色板
    if (ui->radioButtonRed->isChecked()) {
        palette.setColor(QPalette::Text, Qt::red);
    } else if (ui->radioButtonBlue->isChecked()) {
        palette.setColor(QPalette::Text, Qt::blue);
    } else {
        palette.setColor(QPalette::Text, Qt::black);
    }
    ui->plainTextEdit->setPalette(palette);
}
