#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "global.h"


/**
 * @brief The player class
 */
class player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    /**
     * @brief player
     * @param id
     * @param team1
     * @param parent
     */
    player(int id,bool team1,QGraphicsItem * parent=0);

    /**
     * @brief team
     */
    bool team;

    /**
     * @brief id
     */
    int id;

    /**
     * @brief moveLeft
     * @return
     */
    bool moveLeft();

    /**
     * @brief moveRight
     * @return
     */
    bool moveRight();

    /**
     * @brief moveUp
     * @return
     */
    bool moveUp();

    /**
     * @brief moveDown
     * @return
     */
    bool moveDown();

    /**
     * @brief respawn
     */
    void respawn();
};

#endif // PLAYER_H
