#ifndef SERVERSCREEN_H
#define SERVERSCREEN_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "server.h"

class serverScreen{
public:
    serverScreen(QWidget *parent=0);
    QGraphicsView *view;
};


#endif // SERVERSCREEN_H
