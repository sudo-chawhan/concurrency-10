#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy(){
   // rectangle is drawn
    setRect(0,0,50,10);

    //generate random pos
    int random_pos = rand()%750;
    // set random position
    setPos(random_pos,0);
    // connect
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // add period time
    timer->start(50);

}

void Enemy::move()
{
    setPos(x(),y()+5);

//    qDebug()<<pos().y();
    if(pos().y()<0 || pos().y()>600){
        scene()->removeItem(this);
        delete this;
    }
}
