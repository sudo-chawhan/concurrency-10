#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QCoreApplication>
#include <QEvent>
#include <QKeyEvent>
#include <vector>
#include "gamestate.h"
#include "client.h"
#include "global.h"


/**
 * @brief The InputHandler class
 */
class InputHandler : public QGraphicsView
{
private:

    /**
     * @brief gameState
     */
    GameState *gameState;

    /**
     * @brief client
     */
    Client *client;

public:

    /**
     * @brief InputHandler
     * @param input_client
     * @param game_state
     */
    InputHandler(Client *input_client, GameState *game_state);

    /**
     * @brief setGameState
     * @param game_state
     */
    void setGameState(GameState *game_state);

    /**
     * @brief keyPressEvent
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief id
     */
    int id;

};

#endif // INPUTHANDLER_H
