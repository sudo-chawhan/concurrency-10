#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "enemy.h"
#include <thread>
#include <QTimer>
#include <time.h>
#include <QBrush>
#include <QImage>

extern time_t start;

//QGraphicsView *game_over;

Game::Game(QWidget *parent)
{
    // creating a scene
    scene = new QGraphicsScene();
//    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    // making the rectangle item
    player = new Player();
    // draw enemy
     player->setPixmap(QPixmap(":/images/player.png"));

    // set rect as focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // adding item to the screen
    scene->addItem(player);
    // creating the view
    QGraphicsView *view = new QGraphicsView(scene);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    scene->addItem(health);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(view->width()/2-50/2,view->height()-50);


    //generate enemies randomly in a time interval of 3 sec
    QTimer *timer=new QTimer();
    QTimer::connect(timer,SIGNAL(timeout()),player,SLOT(create_enemy()));
    if(2000-((time(0)-start)*100) > 1000)
        timer->start(2000-((time(0)-start)*50));   // increasing rate of arrival as game time increases
    else
        timer->start(1000);
}
