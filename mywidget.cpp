#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
   timerID1= this->startTimer(1000);//后面初始化为毫秒为单位，这里给的是1秒.设置多个定时器同时工作
   timerID2= this->startTimer(1000);//后面初始化为毫秒为单位，这里给的是1秒
   connect(ui->pushButton,&mybutton::clicked,//使用链表表达式，lambad表达式，需要加入CONFG +=c++11
           [=]()
            {
               qDebug()<<"按键被按下";
            }
           );

   ui->label_2->installEventFilter(this);
   ui->label_2->setMouseTracking(true);//设置鼠标追踪
  // ui->pushButton->installEventFilter(true);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *e)//直接把按键的事件写到主函数中
{
  qDebug()<<e->key();//可以直接打印出按下的键的ascall对应的数字
   qDebug()<<(char)e->key();//可以直接打印出按下的键的键的大写
   if(e->key() == Qt::Key_A)
   {
       qDebug()<<"Qt::Key_A";
   }

}

void MyWidget::timerEvent(QTimerEvent *e)//定时器的事件的使用
{
if(e->timerId() == this->timerID1)
{
  static int sec=0;

  QString txt=QString("<center><h1>timerout %1 </h1></center>").arg(sec++);
  ui->label->setText(txt);
  if(sec ==5)
  {
      this->killTimer(timerID1);
  }
}
else if(e->timerId() == this->timerID2)
{
    static int sec=0;

    QString txt=QString("<center><h1>timerout %1 </h1></center>").arg(sec++);
    ui->label_2->setText(txt);
}

}


void MyWidget::mousePressEvent(QMouseEvent *e)//用来测试，最后忽略，继续往下传递会传到父主件中
{
    qDebug()<<"================";
}

 void  MyWidget::closeEvent(QCloseEvent *e)
 {
     int ret =QMessageBox::question(this,"question","是否关闭窗口");
     if(ret == QMessageBox::Yes)
     {
        //关闭窗口
         //处理关闭窗口的事件，接收事件，事件就不会再往下传第下去
         e->accept();//这个两个一般是这样的用的
     }
     else {
         //不管窗口
         //忽略事件，事件然后传第给父主件，然后最后关闭掉主窗口的界面
         e->ignore();
     }
 }

 bool MyWidget::event(QEvent *e)
 {
     //事件的分发，通过type()函数来进行识别


//     switch(e->type())
//     {
//       case QEvent::MouseMove:
//            {QMouseEvent *env =static_cast<QMouseEvent *>(e);
//            mousePressEvent(env);
//             }
//         break;

//       case QEvent::Close:
//            {QCloseEvent *env1 =static_cast<QCloseEvent *>(e);
//            closeEvent(env1);
//             }
//         break;
//         //....

//    }
     if(e->type() ==QEvent::Timer)//这里只是干掉了定时器，else中的其他的事件任然可以正常运作
     {
         //这里干掉定时器
//         QTimerEvent *env =static_cast<QTimerEvent *>(e);
//         timerEvent(env);//进行类型转化
         return true;//这里传入true时，就是传入的时间已被识别并处理,事件停止传播
     }
     else if(e->type() ==QEvent::KeyPress)
     {
         QKeyEvent *env = static_cast<QKeyEvent *>(e);
         if(env->key() == Qt::Key_B)
         {
             qDebug()<<"Qt::key_B";
         }
         else
         {
             return QWidget::event(e);//按下B是执行上面的操作，其余的都是安原样输出ascall
         }
         return true;
     }
     else
     {
         return QWidget::event(e);
         //return false;//不能写成
     }

 }


 bool MyWidget::eventFilter(QObject *obj, QEvent *e)//过滤器的创建，需要在构造函数中，安装
 {
     if(obj == ui->label_2)//判断是那个控件
     {
         QMouseEvent *env = static_cast<QMouseEvent *>(e);
         //然后判断事件
         if(e->type() == QEvent::MouseMove)
         {
           ui->label_2  ->setText(QString("<center><h1>mouseMove %1 ,%2</h1></center>").arg(env->x()).arg(env->y()));
         }


         else if(e->type() == QEvent::MouseButtonPress)
         {
             ui->label_2  ->setText(QString("<center><h1>mousePress %1 ,%2</h1></center>").arg(env->x()).arg(env->y()));

         }
         else if(e->type() == QEvent::MouseButtonRelease)
         {
             ui->label_2  ->setText(QString("<center><h1>mouseRelease %1 ,%2</h1></center>").arg(env->x()).arg(env->y()));

         }
         else
         {
             return QWidget::eventFilter(obj,e);
         }
     }

     else
     {
         return QWidget::eventFilter(obj,e);
     }

//         if(obj == pushbutton)
//         {

//         }
 }
