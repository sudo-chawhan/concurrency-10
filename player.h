#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bool boost_p;
//    int count_p=10;
    void keyPressEvent(QKeyEvent *keyEvent);
public slots:
    void create_enemy();
};

#endif // MYRECT_H
