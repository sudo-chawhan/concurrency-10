#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "global.h"

class player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    player(int id,bool team1,QGraphicsItem * parent=0);
    bool team;
    int id;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

#endif // PLAYER_H
