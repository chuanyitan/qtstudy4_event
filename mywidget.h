#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QDebug>
#include <QEvent>
#include <QMessageBox>


namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

protected:
//    void mouseMoveEvent(QMouseEvent *);
//    void mousePressEvent(QMouseEvent *);
   void keyPressEvent(QKeyEvent *e);
   void timerEvent(QTimerEvent *);
    void closeEvent(QCloseEvent *e);
   void mousePressEvent(QMouseEvent *e);
   bool event(QEvent *);

   //事件过滤去
   bool eventFilter(QObject *obj, QEvent *e);//第一个为要过滤哪个控件，第二个为要过滤哪个事件

private:
    Ui::MyWidget *ui;
    int timerID1;
    int timerID2;
};

#endif // MYWIDGET_H
