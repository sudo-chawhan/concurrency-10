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
    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();
    void respawn();
};

#endif // PLAYER_H
