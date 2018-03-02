#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QDebug>
#include <QImage>
#include "gamestate.h"
#include "inputhandler.h"

Game::Game(QWidget *parent){
    InputHandler *inputHandler = new InputHandler(NULL);
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    inputHandler->setBackgroundBrush(QBrush(QImage(":/images/ye.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    inputHandler->setScene(scene);
    inputHandler->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    inputHandler->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    inputHandler->setFixedSize(800,600);
    
    // create the player
    team1 = new player(0,true);
    qDebug()<<"new player added";
    team1->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    team1->setFlag(QGraphicsItem::ItemIsFocusable);
    team1->setFocus();
    // add the player to the scene
    scene->addItem(team1);
    team2 = new player(1,false);
    qDebug()<<"new player added";
    team2->setPos(400,100); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    team2->setFlag(QGraphicsItem::ItemIsFocusable);
    team2->setFocus();
    // add the player to the scene
    scene->addItem(team2);

    GameState *gamestate = new GameState();
    gamestate->addPlayer(team1);
    gamestate->addPlayer(team2);

    inputHandler->setGameState(gamestate);

    // create the score/health
   // score = new Score();
    //scene->addItem(score);
    //health = new Health();
    //health->setPos(health->x(),health->y()+25);
    //scene->addItem(health);

    inputHandler->show();
}

