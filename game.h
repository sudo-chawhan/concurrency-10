#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
//#include "Score.h"
//#include "Health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    player * team1;
    player * team2;
    //Score * score;
    //Health * health;

};

#endif // GAME_H
