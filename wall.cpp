#include "wall.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int

#include <QDebug>

wall::wall()
{
    int random_number = rand() % 700;
    int yolo = rand() % 700;
    setPos(random_number,yolo);

    // drew the rect
    setRect(0,0,100,10);

}
