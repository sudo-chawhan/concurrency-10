#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include "bullet.h"


player::player(int id1, bool team1,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    id=id1;
    team = team1;

    // set graphic
    setPixmap(QPixmap(":/images/player.png"));
}

void player::moveLeft(){
    setPos(x()-10,y());
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            if(team) setPos(start_a); else setPos(start_b);
    }
}

void player::moveRight(){
    setPos(x()+10,y());
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            if(team) setPos(start_a); else setPos(start_b);
    }
}

void player::moveUp(){
    setPos(x(),y()-10);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            if(team) setPos(start_a); else setPos(start_b);

    }
}

void player::moveDown(){
    setPos(x(),y()+10);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            if(team) setPos(start_a); else setPos(start_b);
    }
}


