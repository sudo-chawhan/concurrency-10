#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include "game.h"

extern time_t start;
extern Game *game;

Enemy::Enemy(){
   // draw enemy
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(25,25);
    setRotation(180);

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
    if(5+((time(0)-start)/8)>=15)
        setPos(x(),y()+15);
    else
        setPos(x(),y()+5+((time(0)-start)/8));
    qDebug()<<5+((time(0)-start)/5);

//    qDebug()<<pos().y();
    if(pos().y()>600){
        game->health->decrement();
        scene()->removeItem(this);
        delete this;
    }
}
