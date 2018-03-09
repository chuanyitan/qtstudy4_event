#include "mylabel.h"

mylabel::mylabel(QWidget *parent) : QLabel(parent)//这是直接重写的一个label的专门事件类的显示
{//对比和直接写在主函数中的按键事件类的对比
   this->setMouseTracking(true);
}


void mylabel::mousePressEvent(QMouseEvent *ev)
{
  int i= ev->x();
  int j= ev->y();
  if(ev->button() == Qt::LeftButton)
  {
      qDebug()<<"left";
  }
  else if(ev->button() == Qt::RightButton)
  {
      qDebug()<<"right";
  }
  else if(ev->button() == Qt::MidButton)
  {
      qDebug()<<"mid";
  }
  this->setText(QString("<center><h1>mousePress %1 ,%2</h1></center>").arg(i).arg(j));
}

void mylabel::mouseReleaseEvent(QMouseEvent *ev)
{

    int i= ev->x();
    int j= ev->y();
    this->setText(QString("<center><h1>mouseRelease %1 ,%2</h1></center>").arg(i).arg(j));
}

void mylabel::mouseMoveEvent(QMouseEvent *ev)
{

    int i= ev->x();
    int j= ev->y();
    //this->setText(QString("<center><h1>mouseMove %1 ,%2</h1></center>").arg(i).arg(j));

}

void mylabel::enterEvent(QEvent *)
{
    this->setText(QString("<center><h1>mouseEnter </h1></center>"));
}

void mylabel::leaveEvent(QEvent *)
{
    this->setText(QString("<center><h1>mouseLeave </h1></center>"));
}
