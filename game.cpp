#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QDebug>
#include <QImage>
#include <QUrl>
#include "gamestate.h"
#include "inputhandler.h"
#include "client.h"

Game::Game(QWidget *parent){
    qDebug()<<"setting up client...";
    Client *client = new Client(QUrl("ws://localhost:3000"));
    InputHandler *inputHandler = new InputHandler(client,NULL);
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

    inputHandler->setGameState(client->gameState);
    inputHandler->showFullScreen();

    inputHandler->show();
}

