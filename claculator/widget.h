#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void opesi(int );//参数是和ope做对比

private slots:
    void addNum();
    void adddian();


    void opeadd();//加
    void opesub();//减
    void opemul();//乘
    void opediv();//除

    void opeeql();
    void opeclear();
    void opeRewrite();
    void opejianjian();

private:
    Ui::Widget *ui;
    double result;
    int ope; // 0 为初始值, 1 +,2 -,3 *,4 /,5 =
};

#endif // WIDGET_H
