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
    player(int id,bool team_a,QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    bool find_a();
    bool find_b();
    int get_id();
private:
    int id;
};

#endif // PLAYER_H
