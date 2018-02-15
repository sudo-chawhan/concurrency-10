#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include "enemy.h"
#include <thread>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // creating a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // making the rectangle item
    MyRect *rect = new MyRect();
    rect->setRect(0,0,50,50);

    // set rect as focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // adding item to the screen
    scene->addItem(rect);
    // creating the view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    rect->setPos(view->width()/2-rect->rect().width()/2,view->height()-rect->rect().height());

    //generate enemies randomly in a time interval of 3 sec
    QTimer *timer=new QTimer();
    QTimer::connect(timer,SIGNAL(timeout()),rect,SLOT(create_enemy()));
    timer->start(2000);

    return a.exec();
}
