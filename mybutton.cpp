#include "mybutton.h"

mybutton::mybutton(QWidget *parent) : QPushButton(parent)
{

}


void mybutton::mousePressEvent(QMouseEvent *e)
{
   if(e->button() == Qt::RightButton)
   {
       //若果是左键按下，会触发
        qDebug()<<"右键按键被按下";//这里接收到信号后，就不会再往下传

       // e->ignore();//忽略，事件继续往下传递信号。会继续往下传递，到父主件当中，即为主窗口
        //不是给基类，即会给到Qwiget
        //ignore()和accept()一般不是用在这的，一般是用在closeEvent()，具体去主函数中看
   }
   else
  {
       //不做处理的写法//每个空间下都有相应的鼠标事件
       QPushButton::mousePressEvent(e);
       //忽略。继续往下传递
   }
}
