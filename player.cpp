#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "bullet.h"


player::player(int id1, bool team1,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    id=id1;
    team = team1;

    // set graphic
    setPixmap(QPixmap(":/images/player.png"));
}

void player::moveLeft(){
    setPos(x()-10,y());
}

void player::moveRight(){
    setPos(x()+10,y());
}


