#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include <typeinfo>
#include "bullet.h"


player::player(int id1, bool team1,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    id=id1;
    team = team1;
    //setTransformOriginPoint(x()+25,y()+25);
    // set graphic
    if(team) setPixmap(QPixmap(":/images/space_shipA.png"));
    else setPixmap(QPixmap(":/images/space_shipB.png"));


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


