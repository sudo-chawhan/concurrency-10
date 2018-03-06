#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include "global.h"

class wall: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    wall();
};


#endif // WALL_H
