#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include <QJsonObject>
#include <QJsonDocument>
#include <string>
#include "bullet.h"
#include "player.h"
#include "player_teama.h"
#include "player_teamb.h"
#include "global.h"

/**
 * @brief The GameState class
 */
class GameState: public QObject{
    Q_OBJECT
private:
    /**
     * @brief bullet_count
     */
    int bullet_count=0;

public:

    /**
     * @brief GameState
     */
    GameState();

    /**
     * @brief bullets
     */
    std::vector<bullet*> bullets;

    /**
     * @brief players
     */
    std::vector<player*> players;

    /**
     * @brief addBullet
     * @param new_bullet
     */
    void addBullet(bullet * new_bullet);

    /**
     * @brief addPlayer
     * @param new_player
     */
    void addPlayer(player * new_player);
    ///can put mutex

    /**
     * @brief updatePlayer
     * @param id
     * @param new_pos
     */
    void updatePlayer(int id, QPoint new_pos);

    /**
     * @brief createBullet
     * @param dir
     * @param team1
     * @param x
     * @param y
     * @return
     */
    bullet* createBullet(QString dir,bool team1, qreal x, qreal y);

    /**
     * @brief getJsonDocFromGameState
     * @return
     */
    QJsonDocument getJsonDocFromGameState();
};


#endif // GAMESTATE_H
