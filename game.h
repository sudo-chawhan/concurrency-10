#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "inputhandler.h"
#include "gamestate.h"
#include "flag.h"
#include "global.h"

/**
 * @brief The Game class
 */
class Game{

public:

    /**
     * @brief Constructor
     * @param client:client instance
     * @param parent
     */
    Game(Client * client,QWidget * parent=0);

    /**
     * @brief scene:shows the screen
     */
    QGraphicsScene * scene;

    /**
     * @brief view:inputhandler instanace
     */
    InputHandler *view;

    /**
     * @brief team1:TEAM A
     */
    player * team1;

    /**
     * @brief team2:TEAM B
     */
    player * team2;

    /**
     * @brief gamestate:game
     */
    GameState *gamestate;

};

#endif // GAME_H
