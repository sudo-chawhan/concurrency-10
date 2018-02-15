#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsItem>
#include <enemy.h>
Bullet::Bullet(){
   // rectangle is drawn
    setRect(0,0,1,10);
    // connect
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // add period time
    timer->start(50);

}

void Bullet::move()
{

    setPos(x(),y()-10);
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*colliding_items[i])==typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

//    qDebug()<<pos().y();
    if(pos().y()<0 || pos().y()>800){
        scene()->removeItem(this);
        delete this;
    }
}
