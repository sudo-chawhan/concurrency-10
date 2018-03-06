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

class InputHandler : public QGraphicsView
{
private:
    GameState *gameState;
    Client *client;

public:
    InputHandler(Client *input_client, GameState *game_state);
    void setGameState(GameState *game_state);
    void keyPressEvent(QKeyEvent *event);
    int id;

};

#endif // INPUTHANDLER_H
