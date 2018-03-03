#include"player.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "bullet.h"


player::player(int id1, bool team_a,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    id=id1;

    if(team_a==true){
        this->team_b=false;
        this->team_a=true;
    }
    else{
        this->team_a=false;
        this->team_b=true;
    }

    // set graphic
    setPixmap(QPixmap(":/images/player.png"));
}

void player::moveLeft(){
    setPos(x()-10,y());
}

void player::moveRight(){
    setPos(x()+10,y());
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

int player::get_id()
{
    return id;
}


