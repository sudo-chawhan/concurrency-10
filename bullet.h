#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "global.h"
#include "enums.h"

/**
 * @brief Simulates the bullet
 */

class bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:

    /**
     * @brief true if team=A
     */
    bool team;

    /**
     * @brief ENUM to store the keypress events
     */
    enums::direc dir;

    /**
     * @brief Removes bullet the scene
     */
    void delete_bullet();

    /**
     * @brief unique identifier
     */
    int id;

    /**
     * @brief differentiate btw move function of server and client
     */
    bool is_server;

    /**
     * @brief constructor
     * @param dirc :enum to show direction of bullet fired
     * @param id :unique id of bullet
     * @param team1 :team A or NOT
     * @param parent
     */
    bullet(enums::direc dirc,int id,bool team1,QGraphicsItem * parent=0);


public slots:
    /**
     * @brief simulates the movement of bullet
     */
    void move();
};

#endif
