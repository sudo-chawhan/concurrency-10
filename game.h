#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "inputhandler.h"
//#include "Score.h"
//#include "Health.h"

class Game{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    InputHandler *view;
    player * team1;
    player * team2;
    //Score * score;
    //Health * health;

};

#endif // GAME_H
