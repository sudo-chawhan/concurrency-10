#include "serverscreen.h"
#include "server.h"

#include <QBrush>
#include <QImage>
#include <QDebug>

QGraphicsScene *scene;

serverScreen::serverScreen(QWidget *parent)
{

    qDebug()<<"passed server";
    // create the scene
    scene = new QGraphicsScene();
    qDebug()<<"passed scene init";
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    qDebug()<<"passed set scene";
    view = new QGraphicsView(scene);
    //view->setBackgroundBrush(QBrush(QImage(":/images/ye.png")));

    qDebug()<<"passed server 2";
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
//    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    qDebug()<<"passed server";
    view->setFixedSize(800,600);

    qDebug()<<"passed server fixedsize";
    //view->showFullScreen();
    qDebug()<<"passed server fullscreen";

    view->show();
    qDebug()<<"passed server show";
}
