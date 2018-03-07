#include "serverscreen.h"
#include "server.h"

#include <QBrush>
#include <QGraphicsRectItem>
#include <QImage>
#include <QDebug>

QGraphicsScene *scene;

serverScreen::serverScreen(QWidget *parent)
{

    qDebug()<<"passed server";
    // create the scene
    scene = new QGraphicsScene();
    qDebug()<<"passed scene init";
    scene->setSceneRect(0,0,1280*(screen_breadth/1280),850*(screen_height/850)); // make the scene 800x600 instead of infinity by infinity (default)
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

    wall1->setRect(0,0,50*(screen_breadth/1280),850*(screen_height/850));
    wall2->setRect(0,0,1280*(screen_breadth/1280),50*(screen_height/850));
    wall3->setRect(0,0,50*(screen_breadth/1280),850*(screen_height/850));
    wall4->setRect(0,0,1280*(screen_breadth/1280),50*(screen_height/850));

    wall1->setPos(0,0);
    wall2->setPos(0,0);
    wall3->setPos(1230*(screen_breadth/1280),0);
    wall4->setPos(0,800*(screen_height/850));

    //for horizontal bars

    QGraphicsRectItem *v1 = new QGraphicsRectItem();
        QGraphicsRectItem *v2 = new QGraphicsRectItem();
        scene->addItem(v1);
        scene->addItem(v2);
        v1->setRect(400*(screen_breadth/1280),50*(screen_height/850),25*(screen_breadth/1280),250*(screen_height/850));

        v2->setRect((1280-400-25)*(screen_breadth/1280),(850-50-250)*(screen_height/850),25*(screen_breadth/1280),250*(screen_height/850));

        QGraphicsRectItem *v3 = new QGraphicsRectItem();
        QGraphicsRectItem *v4 = new QGraphicsRectItem();
        scene->addItem(v3);
        scene->addItem(v4);
        v3->setRect(475*(screen_breadth/1280),450*(screen_height/850),25*(screen_breadth/1280),250*(screen_height/850));
        v4->setRect((1280-475-25)*(screen_breadth/1280),150*(screen_height/850),25*(screen_breadth/1280),250*(screen_height/850));
        QGraphicsRectItem *v5 = new QGraphicsRectItem();
        scene->addItem(v5);
        v5->setRect((1280/2-12)*(screen_breadth/1280),(850/2-250)*(screen_height/850),25*(screen_breadth/1280),500*(screen_height/850));

        QGraphicsRectItem *v6 = new QGraphicsRectItem();
        QGraphicsRectItem *v7 = new QGraphicsRectItem();
        scene->addItem(v6);
        scene->addItem(v7);
        v6->setRect((1280-250-25)*(screen_breadth/1280),50*(screen_height/850),25*(screen_breadth/1280),150*(screen_height/850));
        v7->setRect(250*(screen_breadth/1280),(850-50-150)*(screen_height/850),25*(screen_breadth/1280),150*(screen_height/850));

        //  Horizontal bars

        QGraphicsRectItem *h1 = new QGraphicsRectItem();
        QGraphicsRectItem *h2 = new QGraphicsRectItem();
        scene->addItem(h1);
        scene->addItem(h2);
        h1->setRect(200*(screen_breadth/1280),(50+400)*(screen_height/850),300*(screen_breadth/1280),25*(screen_height/850));
        h2->setRect(780*(screen_breadth/1280),(850-400-50-25)*(screen_height/850),300*(screen_breadth/1280),25*(screen_height/850));

        QGraphicsRectItem *h3 = new QGraphicsRectItem();
        QGraphicsRectItem *h4 = new QGraphicsRectItem();
        scene->addItem(h3);
        scene->addItem(h4);
        h3->setRect(50*(screen_breadth/1280),275*(screen_height/850),150*(screen_breadth/1280),25*(screen_height/850));
        h4->setRect((1280-50-150)*(screen_breadth/1280),(850-275-25)*(screen_height/850),150*(screen_breadth/1280),25*(screen_height/850));
      ;

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
    view->setFixedSize(1280*(screen_breadth/1280),850*(screen_height/850));

    qDebug()<<"passed server fixedsize";
    //view->showFullScreen();
    qDebug()<<"passed server fullscreen";

    view->show();
    qDebug()<<"passed server show";
}
