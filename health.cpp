#include "health.h"
#include <QGraphicsView>

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    // initialise score
    health=3;
    // set postition
    setPos(x(),y()+25);
    // make text to put on screen
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::green);

}

void Health::decrement(){
    health--;
//    if(health==0){
//        view->hide();
//        QGraphicsView *gameover = new QGraphicsView(scene());
//        QGraphicsTextItem *gameover_text = new QGraphicsTextItem;
//        gameover_text->setPlainText(QString("Game Over"));
//        gameover_text->setDefaultTextColor(Qt::red);
//        scene()->addItem(gameover_text);
//        gameover->show();
//    }
    setPlainText(QString("Health: ")+QString::number(health));
}

int Health::getHealth(){
    return health;
}
