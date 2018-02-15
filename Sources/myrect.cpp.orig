#include "myrect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"

bool boost = false;

void MyRect::keyPressEvent(QKeyEvent *keyEvent){
    if(keyEvent->key()==Qt::Key_Space){
        boost=!boost;
    }
    else if(keyEvent->key()==Qt::Key_Left){
        if(boost==false)
            setPos(x()-10,y());
        else
            setPos(x()-20,y());
    }
    else if(keyEvent->key()==Qt::Key_Right){
        if(boost==false)
            setPos(x()+10,y());
        else
            setPos(x()+20,y());
    }
    else if(keyEvent->key()==Qt::Key_Up){
        if(boost==false)
            setPos(x(),y()-10);
        else
            setPos(x(),y()-20);
    }
    else if(keyEvent->key()==Qt::Key_Down){
        if(boost==false)
            setPos(x(),y()+10);
        else
            setPos(x(),y()+20);
    }
    else if(keyEvent->key()==Qt::Key_Shift){
        Bullet *bullet = new Bullet(x(),y());
        scene()->addItem(bullet);
    }
}
