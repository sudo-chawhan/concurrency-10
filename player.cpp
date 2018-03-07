#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include <typeinfo>
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
    // set graphic
    if(team) setPixmap(QPixmap(":/images/red_player.png"));
    else setPixmap(QPixmap(":/images/blue_player.png"));
}

bool player::moveLeft(){


    bool to_return=false;
    setPos(x()-10,y());

    if(team){
        if(isFlagBTaken && takersIDB==id){
            if(pos().x()<200 && pos().y()>screen_height-250){
                server->onFlagScore_A();
                setPixmap(QPixmap(":images/red_player.png"));
            }
        }
    }else{
        if(isFlagATaken && takersIDA==id){
            if(pos().x()>screen_breadth-250 && pos().y()<200){
                server->onFlagScore_B();
                setPixmap(QPixmap(":images/blue_player.png"));
            }
        }
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug()<<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*colliding_items[i])==typeid(QGraphicsRectItem)){
            respawn();
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
    if(team){
        if(isFlagBTaken && takersIDB==id){
            if(pos().x()<200 && pos().y()>screen_height-250){
                server->onFlagScore_A();
                setPixmap(QPixmap(":images/red_player.png"));
            }
        }
    }else{
        if(isFlagATaken && takersIDA==id){
            if(pos().x()>screen_breadth-250 && pos().y()<200){
                server->onFlagScore_B();
                setPixmap(QPixmap(":images/blue_player.png"));
            }
        }
    }
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

bool player::moveUp(){
    bool to_return=false;

    setPos(x(),y()-10);
    if(team){
        if(isFlagBTaken && takersIDB==id){
            if(pos().x()<200 && pos().y()>screen_height-250){
                server->onFlagScore_A();
                setPixmap(QPixmap(":images/red_player.png"));
            }
        }
    }else{
        if(isFlagATaken && takersIDA==id){
            if(pos().x()>screen_breadth-250 && pos().y()<200){
                server->onFlagScore_B();
                setPixmap(QPixmap(":images/blue_player.png"));
            }
        }
    }
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
    if(team){
        if(isFlagBTaken && takersIDB==id){
            if(pos().x()<200 && pos().y()>screen_height-250){
                server->onFlagScore_A();
                setPixmap(QPixmap(":images/red_player.png"));
            }
        }
    }else{
        if(isFlagATaken && takersIDA==id){
            if(pos().x()>screen_breadth-250 && pos().y()<200){
                server->onFlagScore_B();
                setPixmap(QPixmap(":images/blue_player.png"));
            }
        }
    }
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

void player::respawn()
{
    if(team){
        setPos(start_a);
        if(takersIDB==id && isFlagBTaken){
            server->onFlagDropped_B();
            setPixmap(QPixmap(":images/red_player.png"));
        }
    }
    else{
        setPos(start_b);
        if(takersIDA==id && isFlagATaken){
            server->onFlagDropped_A();
            setPixmap(QPixmap(":images/blue_player.png"));
        }
    }
}


