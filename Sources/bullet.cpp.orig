#include "bullet.h"
#include <QTimer>

Bullet::Bullet(qreal x, qreal y){
   // rectangle is drawn
    setRect(x,y,1,10);
    // connect
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // add period time
    timer->start(50);

}

void Bullet::move()
{
    setPos(x(),y()-10);
}
