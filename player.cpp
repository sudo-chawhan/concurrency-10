#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include "bullet.h"
#include "server.h"
#include "dialog.h"
#include "flag.h"

extern Server *server;
extern bool isFlagATaken;
extern bool isFlagBTaken;
extern int takersIDA;
extern int takersIDB;

player::player(int id1, bool team1,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    id=id1;
    team = team1;
    //setTransformOriginPoint(x()+25,y()+25);
    // set graphic
    if(team) setPixmap(QPixmap(":/images/space_shipA.png"));
    else setPixmap(QPixmap(":/images/space_shipB.png"));
}

bool player::moveLeft(){
    bool to_return=false;
    setPos(x()-10,y());
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem)){
            if(team) setPos(start_a); else setPos(start_b);
        }
        if(typeid(*colliding_items[i])==typeid(Flag) && team!=dynamic_cast<Flag*>(colliding_items[i])->team){
            isFlagATaken=true;
            to_return=true;
        }
    }

    return to_return;
}

bool player::moveRight(){
    bool to_return=false;

    setPos(x()+10,y());
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            if(team) setPos(start_a); else setPos(start_b);
        if(typeid(*colliding_items[i])==typeid(Flag) && team!=dynamic_cast<Flag*>(colliding_items[i])->team)
            to_return=true;
    }
    return to_return;

}

bool player::moveUp(){
    bool to_return=false;

    setPos(x(),y()-10);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            respawn();
        if(typeid(*colliding_items[i])==typeid(Flag) && team!=dynamic_cast<Flag*>(colliding_items[i])->team)
            to_return=true;

    }
    return to_return;

}

bool player::moveDown(){
    bool to_return=false;

    setPos(x(),y()+10);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem))
            if(team) setPos(start_a); else setPos(start_b);
        if(typeid(*colliding_items[i])==typeid(Flag) && team!=dynamic_cast<Flag*>(colliding_items[i])->team)
            to_return=true;
    }
    return to_return;

}

void player::respawn()
{
    if(team){
        setPos(start_a);
        if(takersIDB==id && isFlagBTaken){
            server->onFlagDropped_B();
            setPixmap(QPixmap(":images/space_shipA.png"));
        }
    }
    else{
        setPos(start_b);
        if(takersIDA==id && isFlagATaken){
            server->onFlagDropped_A();
            setPixmap(QPixmap(":images/space_shipB.png"));
        }
    }
}


