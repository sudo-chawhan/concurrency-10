#include "serverscreen.h"
#include "server.h"

#include <QBrush>
#include <QGraphicsRectItem>
#include <QImage>
#include <QDebug>
#include "wall.h"

QGraphicsScene *scene;

serverScreen::serverScreen(QWidget *parent)
{

    qDebug()<<"passed server";
    // create the scene
    scene = new QGraphicsScene();
    qDebug()<<"passed scene init";
    scene->setSceneRect(0,0,1280,850); // make the scene 800x600 instead of infinity by infinity (default)
    qDebug()<<"passed set scene";
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
        QGraphicsRectItem *o1 = new QGraphicsRectItem();
        QGraphicsRectItem *o2 = new QGraphicsRectItem();

        scene->addItem(o1);
        scene->addItem(o2);

        o1->setRect(0,0,500,50);
        o2->setRect(0,0,500,50);

        o1->setPos(260,260);
        o2->setPos(1280-260-500,540);

    //for vertical bars
        QGraphicsRectItem *o3 = new QGraphicsRectItem();
        QGraphicsRectItem *o4 = new QGraphicsRectItem();

        scene->addItem(o3);
        scene->addItem(o4);

        o3->setRect(0,0,50,400);
        o4->setRect(0,0,50,400);


        o3->setPos(260,260);
        o4->setPos(970,540-350);
    //
    view = new QGraphicsView(scene);
    //view->setBackgroundBrush(QBrush(QImage(":/images/ye.png")));

    qDebug()<<"passed server 2";
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
//    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qDebug()<<"passed server";
    view->setFixedSize(1280,850);

    qDebug()<<"passed server fixedsize";
    //view->showFullScreen();
    qDebug()<<"passed server fullscreen";

    view->show();
    qDebug()<<"passed server show";
}
