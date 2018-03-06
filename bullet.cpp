#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <vector>
#include <QDebug>
#include <iterator>
#include<typeinfo>
#include "enums.h"
#include "server.h"
#include "player.h"
#include "player_teama.h"
#include "player_teamb.h"

#include "game.h"

extern Game * game; // there is an external global object called game
extern bool isServer;
extern Server *server;

void bullet::delete_bullet()
{
    scene()->removeItem(this);

}

bullet::bullet(enums::direc dirc,int id1,bool team1,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    dir = dirc;
    is_server = isServer;
    id =id1;
    team = team1;
    // draw graphics
    if(team)
        setPixmap(QPixmap(":/images/bullet_red.png"));
    else
        setPixmap(QPixmap(":/images/bullet_blue.png"));
    if(dirc==enums::direc::DOWN){
        setTransformOriginPoint(0,0);
        setRotation(-90);
    }
    if(dirc==enums::direc::UP){
        setTransformOriginPoint(0,0);
        setRotation(90);
    }



    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void bullet::move(){
    //qDebug()<<"iterate move";


    //qDebug()<<"colliding items in client:";
    //QList<QGraphicsItem *> colliding_items = collidingItems();
    //qDebug()<<colliding_items.size();

// // // // // // // // IF SERVER

    if(is_server){

        switch(dir){
            case enums::direc::DOWN:setPos(x(),y()+20);
                        break;
            case enums::direc::UP:setPos(x(),y()-20);
                        break;
            case enums::direc::LEFT:setPos(x()-20,y());
                        break;
            case enums::direc::RIGHT:setPos(x()+20,y());
                        break;
        }

       /// qDebug()<<"is server!";

//        if(pos().y()<0 || pos().y()>screen_height){
//            qDebug()<<"is out of bound";
//            // delete this bullet from bullets vector


//            // find the index of the bullet in bullets vector
//            std::vector<bullet*> ::iterator it=find((server->gameState->bullets).begin(),(server->gameState->bullets).end(),this);
//            auto pos_in_vec = std::distance((server->gameState->bullets).begin(), it);
//            qDebug()<<"bullets size before: "<<(server->gameState->bullets).size();
//            (server->gameState->bullets).erase((server->gameState->bullets).begin()+pos_in_vec);
//            qDebug()<<"bullets size after: "<<(server->gameState->bullets).size();
//            scene()->removeItem(this);
//            delete this;

//            return;
//        }

        // get a list of all the items currently colliding with this bullet
        QList<QGraphicsItem *> colliding_items = collidingItems();
        qDebug()<<colliding_items.size();
//        // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            qDebug()<<"entered colliding items";

//            // collided with an enemy team
            if ((typeid(*(colliding_items[i])) == typeid(player) && team!=dynamic_cast<player*>(colliding_items[i])->team)/*||(typeid(*(colliding_items[i])) == typeid(player) && team==false)*/){

                // delete this bullet from bullets vector

                // find the index of the bullet in bullets vector
                std::vector<bullet*> ::iterator it=find((server->gameState->bullets).begin(),(server->gameState->bullets).end(),this);
                auto pos_in_vec = std::distance((server->gameState->bullets).begin(), it);
                (server->gameState->bullets).erase((server->gameState->bullets).begin()+pos_in_vec);
                scene()->removeItem(this);

                // make colliding item dead
                if(team==true){
                    // player is of team false
                    dynamic_cast<player*>(colliding_items[i])->setPos(start_b);
                }else{
                    // player is of team true
                    dynamic_cast<player*>(colliding_items[i])->setPos(start_a);
                }
                delete this;

                qDebug()<<"player is dead!";
                // return (all code below refers to a non existint bullet)
                return;
            }
            if(typeid(*(colliding_items[i])) == typeid(QGraphicsRectItem)){
                // delete this bullet from bullets vector

                // find the index of the bullet in bullets vector
                std::vector<bullet*> ::iterator it=find((server->gameState->bullets).begin(),(server->gameState->bullets).end(),this);
                auto pos_in_vec = std::distance((server->gameState->bullets).begin(), it);
                (server->gameState->bullets).erase((server->gameState->bullets).begin()+pos_in_vec);
                scene()->removeItem(this);

                // return (all code below refers to a non existint bullet)
                return;
            }
        }
    }
}

