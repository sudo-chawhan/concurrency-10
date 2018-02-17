#include "health.h"

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
    setPlainText(QString("Health: ")+QString::number(health));
}

int Health::getHealth(){
    return health;
}
