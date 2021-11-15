#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

void Dialog::setupUi()
{
    QHBoxLayout *hBoxLayout1 = new QHBoxLayout;
    hBoxLayout1->addWidget(checkBoxUnderLine);
    hBoxLayout1->addWidget(checkBoxItalic);
    hBoxLayout1->addWidget(checkBoxBlod);

    QHBoxLayout *hBoxLayout2 = new QHBoxLayout;
    hBoxLayout2->addWidget(radioButtonBlack);
    hBoxLayout2->addWidget(radioButtonBlue);
    hBoxLayout2->addWidget(radioButtonRed);

    QFont font = plainTextEdit->font();
    font.setPointSize(18);
    plainTextEdit->setFont(font);
    plainTextEdit->setPlainText(tr("Hello World!\n\nThis is a plainTextEdit!"));

    QHBoxLayout *hBoxLayout3 = new QHBoxLayout;
    hBoxLayout3->addStretch();	//在目前布局的末尾添加弹簧
    hBoxLayout3->addWidget(pushButtonOk);
    hBoxLayout3->addWidget(pushButtonCancle);
    hBoxLayout3->addStretch();
    hBoxLayout3->addWidget(pushButtonExit);

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    vBoxLayout->addLayout(hBoxLayout1);
    vBoxLayout->addLayout(hBoxLayout2);
    vBoxLayout->addWidget(plainTextEdit);
    vBoxLayout->addLayout(hBoxLayout3);
    setLayout(vBoxLayout);
}

void Dialog::setupSlots()
{
    QObject::connect(pushButtonOk, &QPushButton::clicked, this, &Dialog::accept);
    QObject::connect(pushButtonCancle, &QPushButton::clicked, this, &Dialog::reject);
    QObject::connect(pushButtonExit, &QPushButton::clicked, this, &Dialog::close);
    QObject::connect(checkBoxUnderLine, &QCheckBox::clicked, [this](bool checked){
        QFont font = this->plainTextEdit->font();
        font.setUnderline(checked);
        this->plainTextEdit->setFont(font);
    });
    QObject::connect(checkBoxItalic, &QCheckBox::clicked, [this](bool checked){
        QFont font = this->plainTextEdit->font();
        font.setItalic(checked);
        this->plainTextEdit->setFont(font);
    });
    QObject::connect(checkBoxBlod, &QCheckBox::clicked, [this](bool checked){
        QFont font = this->plainTextEdit->font();
        font.setBold(checked);
        this->plainTextEdit->setFont(font);
    });
    QObject::connect(radioButtonBlack, &QRadioButton::clicked, this, &Dialog::setColor);
    QObject::connect(radioButtonRed, &QRadioButton::clicked, this, &Dialog::setColor);
    QObject::connect(radioButtonBlue, &QRadioButton::clicked, this, &Dialog::setColor);
}

void Dialog::setColor()
{
    QPalette palette = plainTextEdit->palette();
    if (radioButtonBlue->isChecked()) {
        palette.setColor(QPalette::Text, Qt::blue);
    } else if (radioButtonRed->isChecked()){
        palette.setColor(QPalette::Text, Qt::red);
    } else {
        palette.setColor(QPalette::Text, Qt::black);
    }
    plainTextEdit->setPalette(palette);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , checkBoxUnderLine(new QCheckBox(tr("UnderLine")))
    , checkBoxBlod(new QCheckBox(tr("Blod")))
    , checkBoxItalic(new QCheckBox(tr("Italic")))
    , radioButtonBlack(new QRadioButton(tr("Black")))
    , radioButtonBlue(new QRadioButton(tr("Blue")))
    , radioButtonRed(new QRadioButton(tr("Red")))
    , plainTextEdit(new QPlainTextEdit)
    , pushButtonCancle(new QPushButton(tr("Cancle")))
    , pushButtonOk(new QPushButton(tr("Ok")))
    , pushButtonExit(new QPushButton(tr("Exit")))
{
    setupUi();
    setupSlots();
}

Dialog::~Dialog()
{
}

