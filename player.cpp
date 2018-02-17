#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include <QDebug>
#include "enemy.h"

bool boost_p = false;
//int count_p=10;

void Player::keyPressEvent(QKeyEvent *keyEvent){
//    qDebug()<<"player "<<count_p;
    if(keyEvent->key()==Qt::Key_Space){
        boost_p=!boost_p;
    }
    else if(keyEvent->key()==Qt::Key_Left && x()>0){
        if(boost_p==false)
            setPos(x()-10,y());
        else
            setPos(x()-20,y());
    }
    else if(keyEvent->key()==Qt::Key_Right && x()<750){
        if(boost_p==false)
            setPos(x()+10,y());
        else
            setPos(x()+20,y());
    }
    else if(keyEvent->key()==Qt::Key_Shift /*&& count_p>0*/){
        Bullet *bullet = new Bullet();
        scene()->addItem(bullet);
        bullet->setPos(x()+20,y());
//        count_p--;
    }
}

void Player::create_enemy(){
    Enemy *enemy=new Enemy();
    scene()->addItem(enemy);
}
