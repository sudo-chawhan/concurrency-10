#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"


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
    return a.exec();
}
