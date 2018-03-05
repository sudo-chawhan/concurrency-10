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
#include "game.h"

extern Game * game; // there is an external global object called game

void bullet::delete_bullet()
{
    scene()->removeItem(this);

}

bullet::bullet(int id1,bool team1,QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
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
    if(team)
        setPos(x(),y()-10);
    else
        setPos(x(),y()+10);
    // get a list of all the items currently colliding with this bullet
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    std::vector<bullet*> ::iterator it=find((game->gamestate->bullets).begin(),(game->gamestate->bullets).end(),this);
//    auto pos_in_vec = std::distance((game->gamestate->bullets).begin(), it);

//    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
//    for (int i = 0, n = colliding_items.size(); i < n; ++i){
//        if (typeid(*(colliding_items[i])) == typeid(player)){
//            // increase the score
//           // game->score->increase();

//            // remove them from the scene (still on the heap)
//            scene()->removeItem(colliding_items[i]);
//            scene()->removeItem(this);

//            // delete them from the heap to save memory
//            delete colliding_items[i];
//            delete this;

//            // return (all code below refers to a non existint bullet)
//            return;
//        }
//    }

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
}

