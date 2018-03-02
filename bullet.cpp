#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include<typeinfo>
#include "game.h"

extern Game * game; // there is an external global object called game

bullet::bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));


    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    bool type_finder=game->team1->find_a();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(player)){
            // increase the score
           // game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    if(this->a_finder==true){
        setPos(x(),y()-10);
        // if the bullet is off the screen, destroy it
        if (pos().y() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else{
        setPos(x(),y()+10);
        if (pos().y() > 600){
            scene()->removeItem(this);
            delete this;
    }

}
}

