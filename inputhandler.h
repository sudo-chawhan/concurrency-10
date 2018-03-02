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

class InputHandler : public QGraphicsView
{
private:
    GameState *gameState;
public:
    InputHandler(GameState *game_state);
    void setGameState(GameState *game_state);
    void keyPressEvent(QKeyEvent *event);

};

#endif // INPUTHANDLER_H
