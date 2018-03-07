#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QDebug>
#include <QImage>
#include <QUrl>
#include <QGraphicsRectItem>
#include "gamestate.h"
#include "inputhandler.h"
#include "client.h"
#include "wall.h"

Game::Game(Client * client,QWidget *parent){
    //qDebug()<<"setting up client...";

    // create the scene
    scene = new QGraphicsScene();


    scene->setSceneRect(0,0,1280,850); // make the scene 800x600 instead of infinity by infinity (default)

    qDebug()<<"reached here";

    qDebug()<<"crossed";
    InputHandler *inputHandler = new InputHandler(client,NULL);
    inputHandler->setBackgroundBrush(QBrush(QImage(":/images/ye.png")));

    // madhur
    //For the out walls (will be use in all the gameplay windows)

    QGraphicsRectItem *wall1= new QGraphicsRectItem();
    QGraphicsRectItem *wall2= new QGraphicsRectItem();
    QGraphicsRectItem *wall3= new QGraphicsRectItem();
    QGraphicsRectItem *wall4= new QGraphicsRectItem();
    QGraphicsRectItem *wall = new QGraphicsRectItem();

    scene->addItem((wall1));
    scene->addItem((wall2));
    scene->addItem((wall3));
    scene->addItem((wall4));

    wall1->setRect(0,0,50,850);
    wall2->setRect(0,0,1280,50);
    wall3->setRect(0,0,50,850);
    wall4->setRect(0,0,1280,50);

    wall1->setPos(0,0);
    wall2->setPos(0,0);
    wall3->setPos(1230,0);
    wall4->setPos(0,800);

    //for horizontal bars
    QGraphicsRectItem *v1 = new QGraphicsRectItem();
        QGraphicsRectItem *v2 = new QGraphicsRectItem();
        scene->addItem(v1);
        scene->addItem(v2);
        v1->setRect(400,50,25,250);
        v2->setRect(1280-400-25,850-50-250,25,250);

        QGraphicsRectItem *v3 = new QGraphicsRectItem();
        QGraphicsRectItem *v4 = new QGraphicsRectItem();
        scene->addItem(v3);
        scene->addItem(v4);
        v3->setRect(475,50+400,25,250);
        v4->setRect(1280-475-25,850-50-250-400,25,250);

        QGraphicsRectItem *v5 = new QGraphicsRectItem();
        scene->addItem(v5);
        v5->setRect(1280/2-12,850/2-250,25,500);

        QGraphicsRectItem *v6 = new QGraphicsRectItem();
        QGraphicsRectItem *v7 = new QGraphicsRectItem();
        scene->addItem(v6);
        scene->addItem(v7);
        v6->setRect(1280-250-25,50,25,150);
        v7->setRect(250,850-50-150,25,150);

        //  Horizontal bars

        QGraphicsRectItem *h1 = new QGraphicsRectItem();
        QGraphicsRectItem *h2 = new QGraphicsRectItem();
        scene->addItem(h1);
        scene->addItem(h2);
        h1->setRect(225-25,50+400,300,25);
        h2->setRect(1280-225-300+25,850-400-50-25,300,25);

        QGraphicsRectItem *h3 = new QGraphicsRectItem();
        QGraphicsRectItem *h4 = new QGraphicsRectItem();
        scene->addItem(h3);
        scene->addItem(h4);
        h3->setRect(50,275,150,25);
        h4->setRect(1280-50-150,850-275-25,150,25);
    //
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    inputHandler->setScene(scene);
    inputHandler->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    inputHandler->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    inputHandler->setFixedSize(1280,850);

    inputHandler->setGameState(client->gameState);
    inputHandler->showFullScreen();

    inputHandler->show();
}

