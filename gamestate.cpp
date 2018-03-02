#include "gamestate.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

void GameState::addBullet(bullet *new_bullet){
    bullets.push_back(new_bullet);
}

void GameState::addPlayer(player *new_player){
    players.push_back(new_player);
}

void GameState::updatePlayer(int id, QPoint new_pos)
{
    players.at(id)->setPos(new_pos);
}

QJsonDocument GameState::getJsonDocFromGameState(){

    QJsonObject gamestate1;

        gamestate1.insert("FirstName", QJsonValue::fromVariant("John"));
        gamestate1.insert("LastName", QJsonValue::fromVariant("Doe"));
        gamestate1.insert("Age", QJsonValue::fromVariant(43));

        QJsonArray bulletArray;

            for(auto it = bullets.begin() ; it != bullets.end() ; it++)
            {
                QJsonObject n_bullet;
                n_bullet.insert("posX",(*it)->pos().x());
                n_bullet.insert("posY",(*it)->pos().y());
                n_bullet.insert("team",(*it)->a_finder);
                bulletArray.push_back(n_bullet);
            }
        gamestate1.insert("bullets", bulletArray);

        QJsonArray playerArray;

            for(auto it = players.begin() ; it != players.end() ; it++)
            {
                QJsonObject n_player;
                n_player.insert("id",(*it)->get_id());
                n_player.insert("posX",(*it)->pos().x());
                n_player.insert("posY",(*it)->pos().y());
                n_player.insert("team",(*it)->find_a());
                playerArray.push_back(n_player);
            }
        gamestate1.insert("bullets", playerArray);

        QJsonDocument doc(gamestate1);

        return doc;
}



