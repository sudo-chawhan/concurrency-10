#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "bullet.h"


player::player(bool team_a,QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    if(team_a==true){
        this->team_b=false;
        this->team_a=true;
    }
    else{
        this->team_a=false;
        this->team_b=true;
    }

    // set graphic
    setPixmap(QPixmap(":/images/download.jpeg"));
}

void player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
         //create a bullet
        bullet * bull = new bullet();
        bull->a_finder=this->find_a();
        bull->setPos(x()+45,y());
        scene()->addItem(bull);
    }
}

bool player:: find_a(){
    if(this->team_a==true)
        return true;
    else
        return false;
}

bool player::find_b(){
    if(this->team_b==true)
        return true;
    else
        return false;
}


