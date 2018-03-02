#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    bool a_finder;
    void delete_bullet();
    bullet(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif
