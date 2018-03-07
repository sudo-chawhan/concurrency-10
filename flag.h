#ifndef FLAG_H
#define FLAG_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Flag: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bool team;
    Flag(bool team1,QGraphicsItem * parent=0);
};

#endif // FLAG_H
