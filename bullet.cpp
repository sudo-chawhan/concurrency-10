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

bullet::bullet(int id1,bool team1,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    is_server = isServer;
    id =id1;
    team = team1;
    // draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));


    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void bullet::move(){
    qDebug()<<"iterate move";
    if(team)
        setPos(x(),y()-10);
    else
        setPos(x(),y()+10);

// // // // // // // // IF SERVER

    ///if(is_server){

       /// qDebug()<<"is server!";

//        if(pos().y()<0 || pos().y()>600){
//            qDebug()<<"is out of bound";
//            // delete this bullet from bullets vector


//            // find the index of the bullet in bullets vector
//            std::vector<bullet*> ::iterator it=find((server->gameState->bullets).begin(),(server->gameState->bullets).end(),this);
//            auto pos_in_vec = std::distance((server->gameState->bullets).begin(), it);
//            qDebug()<<"bullets size before: "<<(server->gameState->bullets).size();
//            (server->gameState->bullets).erase((server->gameState->bullets).begin()+pos_in_vec);
//            qDebug()<<"bullets size after: "<<(server->gameState->bullets).size();
//            delete this;

//            return;
//        }

        // get a list of all the items currently colliding with this bullet
//        QList<QGraphicsItem *> colliding_items = collidingItems();

//        // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
//        for (int i = 0, n = colliding_items.size(); i < n; ++i){

//            // collided with an enemy team
//            if ((typeid(*(colliding_items[i])) == typeid(player_teama) && team==true)||(typeid(*(colliding_items[i])) == typeid(player_teamb) && team==false)){

//                // delete this bullet from bullets vector

//                // find the index of the bullet in bullets vector
//                std::vector<bullet*> ::iterator it=find((server->gameState->bullets).begin(),(server->gameState->bullets).end(),this);
//                auto pos_in_vec = std::distance((server->gameState->bullets).begin(), it);
//                (server->gameState->bullets).erase((server->gameState->bullets).begin()+pos_in_vec);
//                delete this;
//                // make colliding item's isDead=true
//                qDebug()<<"player is dead!";
//                // return (all code below refers to a non existint bullet)
//                return;
//            }
//        }

        // if there was no collision with an Enemy, move the bullet forward
        //    if(this->a_finder==true){
        //        setPos(x(),y()-10);
        //        // if the bullet is off the screen, destroy it
        //        if (pos().y() < 0){
        //            scene()->removeItem(this);
        //            (game->gamestate->bullets).erase((game->gamestate->bullets).begin()+pos_in_vec);
        //            qDebug()<<"position of this bullet is "<<pos_in_vec;
        //            delete this;
        //        }
        //    }
        //    else{
        //        setPos(x(),y()+10);
        //        if (pos().y() > 600){
        //            scene()->removeItem(this);
        //            (game->gamestate->bullets).erase((game->gamestate->bullets).begin()+pos_in_vec);
        //            qDebug()<<"position of this bullet is "<<pos_in_vec;
        //            delete this;
        //        }

        //    }
   /// }
}

