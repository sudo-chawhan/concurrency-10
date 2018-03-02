#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include <QJsonObject>
#include <QJsonDocument>
#include "bullet.h"
#include "player.h"

class GameState: public QObject{
    Q_OBJECT
public:
    GameState();
    std::vector<bullet*> bullets;
    std::vector<player*> players;
    void addBullet(bullet * new_bullet);
    void addPlayer(player * new_player);
    void updatePlayer(int id, QPoint new_pos);
    QJsonDocument getJsonDocFromGameState();
};


#endif // GAMESTATE_H
