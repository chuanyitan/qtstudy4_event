#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include <QDebug>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = 0);

signals:
protected:
    void mousePressEvent(QMouseEvent *e);

public slots:
};

#endif // MYBUTTON_H
