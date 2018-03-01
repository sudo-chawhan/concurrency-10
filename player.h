#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QGraphicsRectItem>

class player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bool team_a,team_b;
    player(bool team_a,QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    bool find_a();
    bool find_b();
};

#endif // PLAYER_H
