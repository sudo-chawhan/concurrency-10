#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "global.h"
#include "enums.h"

class bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bool team;
    enums::direc dir;
    void delete_bullet();
    int id;
    bool is_server;
    bullet(enums::direc dirc,int id,bool team1,QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif
