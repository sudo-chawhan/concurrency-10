#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "inputhandler.h"
#include "gamestate.h"
#include "flag.h"
//#include "Score.h"
//#include "Health.h"
#include "global.h"

class Game{
public:
    Game(Client * client,QWidget * parent=0);
    QGraphicsScene * scene;
    InputHandler *view;
    player * team1;
    player * team2;
    GameState *gamestate;
    //Score * score;
    //Health * health;

};

#endif // GAME_H
