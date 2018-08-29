#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("计算器");
    this->result = 0;
    this->ope = 0;
    ui->wenben->setText("0");
    connect(ui->num0, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num1, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num2, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num3, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num4, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num5, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num6, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num7, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num8, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->num9, SIGNAL(clicked()), this, SLOT(addNum()));
    connect(ui->ope_dian, SIGNAL(clicked()), this, SLOT(adddian()));
    connect(ui->ope_jia, SIGNAL(clicked()), this, SLOT(opeadd()));
    connect(ui->ope_jian, SIGNAL(clicked()), this, SLOT(opesub()));
    connect(ui->ope_cheng, SIGNAL(clicked()), this, SLOT(opemul()));
    connect(ui->ope_chu, SIGNAL(clicked()), this, SLOT(opediv()));
    connect(ui->ope_deng, SIGNAL(clicked()), this, SLOT(opeeql()));
    connect(ui->ope_qingchu, SIGNAL(clicked()), this, SLOT(opeclear()));
    connect(ui->ope_chongxie, SIGNAL(clicked()), this, SLOT(opeRewrite()));
    connect(ui->ope_xiaoqu, SIGNAL(clicked()), this, SLOT(opejianjian()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addNum()
{
    if (ui->wenben->text().compare("0") == 0)
    {
        ui->wenben->setText(static_cast<QPushButton *>(sender())->text());
        return;
    }
    ui->wenben->insert(static_cast<QPushButton *>(sender())->text());
}

void Widget::adddian()
{
    ui->wenben->insert(static_cast<QPushButton *>(sender())->text());
}

void Widget::opesi(int a)
{
    if (ui->wenben->text().isEmpty())
    {
        this->ope = a;
        return;
    }
    switch (this->ope) {
    case 0:
        this->result = ui->wenben->text().toDouble();
        break;
    case 1:
        this->result += ui->wenben->text().toDouble();
        break;
    case 2:
        this->result -= ui->wenben->text().toDouble();
        break;
    case 3:
        this->result *= ui->wenben->text().toDouble();
        break;
    case 4:
        this->result /= ui->wenben->text().toDouble();
        break;
    case 5:

    default:
        break;
    }
    this->ope = a;
}

void Widget::opeadd()
{
    opesi(1);
    ui->wenben2->setText(QString::number(this->result) + "+");
    ui->wenben->clear();
}
void Widget::opesub()
{
    opesi(2);
    ui->wenben2->setText(QString::number(this->result) + "-");
    ui->wenben->clear();
}
void Widget::opemul()
{
    opesi(3);
    ui->wenben2->setText(QString::number(this->result) + "×");
    ui->wenben->clear();
}
void Widget::opediv()
{
    opesi(4);
    ui->wenben2->setText(QString::number(this->result) + "÷");
    ui->wenben->clear();
}

void Widget::opeeql()
{
    opesi(5);
    ui->wenben2->setText(QString::number(this->result));
    ui->wenben->clear();
}

void Widget::opeclear()
{
    ui->wenben->setText("0");
    ui->wenben2->clear();
    this->result = 0;
    this->ope = 0;
}

void Widget::opeRewrite()
{
    ui->wenben->clear();
}

void Widget::opejianjian()
{
    QString a = ui->wenben->text();
    a.chop(1);
    ui->wenben->setText(a);
}
