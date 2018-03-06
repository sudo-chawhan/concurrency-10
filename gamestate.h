#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include <QJsonObject>
#include <QJsonDocument>
#include "bullet.h"
#include "player.h"
#include "player_teama.h"
#include "player_teamb.h"

class GameState: public QObject{
    Q_OBJECT
private:
    int bullet_count=0;
public:
    GameState();
    std::vector<bullet*> bullets;
    std::vector<player*> players;
    void addBullet(bullet * new_bullet);
    void addPlayer(player * new_player);
    void updatePlayer(int id, QPoint new_pos);
    bullet* createBullet(bool team1, qreal x, qreal y);
    QJsonDocument getJsonDocFromGameState();
};


#endif // GAMESTATE_H
