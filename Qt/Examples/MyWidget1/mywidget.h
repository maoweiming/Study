#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>



class MyWidget:public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *patent=nullptr);
    ~MyWidget();
};

#endif // MYWIDGET_H
