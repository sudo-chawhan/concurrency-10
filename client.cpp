#include "client.h"
#include "player.h"
#include <QDebug>
#include <QJsonArray>
#include <QBrush>
#include <QImage>
#include <QJsonDocument>
#include "enums.h"
#include <QJsonObject>
#include "game.h"

extern Game *game;

Client::Client(QUrl url_local,QObject *parent){

    gameState = new GameState();

    if(&m_client_socket==NULL){
        qDebug()<<"null socket";
    }
    connect(&m_client_socket, &QWebSocket::connected, this, &Client::onConnected);
    connect(&m_client_socket, &QWebSocket::disconnected, this, &Client::closed);
    qDebug()<<"reached here";
    m_client_socket.open(url_local);
    qDebug()<<"crossed open";
    qDebug() << "Websocket client started at url: "<< url_local;
}

void Client::onConnected(){
    qDebug() << "Client WebSocket connected";
    connect(&m_client_socket, &QWebSocket::textMessageReceived,this, &Client::onTextMessageReceived);
    connect(&m_client_socket, &QWebSocket::binaryMessageReceived,this, &Client::onBinaryMessageReceived);

}

Client::~Client(){

}

void Client::sendTextMessageToServer(QString message)
{
    m_client_socket.sendTextMessage(message);
}

void Client::sendBinaryMessageToServer(QByteArray message)
{
    m_client_socket.sendBinaryMessage(message);
}

// check if id's bullet is available is json array
bool Client::checkBullet(QJsonArray bulletArray,int id)
{
    foreach(const QJsonValue & value , bulletArray){
        QJsonObject obj = value.toObject();
        int bullet_id=obj["id"].toInt();
        if(id==bullet_id){
            return true;
        }
    }
    return false;
}

void Client::closed()
{
    m_client_socket.close();
}

void Client::onTextMessageReceived(QString message){
    // init := for assigning main id to the client
    qDebug()<<"server text message recieved";
    if(message.startsWith("init:")){
        qDebug()<<"init message recieved: "<<message;
        QString m_id = message.mid(5,message.size()-5);
        main_id=m_id.toInt();

    ///// send ready to server
        std::string init_messsage="ready:";
        init_messsage+=std::to_string(main_id);
        m_client_socket.sendTextMessage(QString::fromStdString(init_messsage));

    }


}

void Client::onBinaryMessageReceived(QByteArray bytes)
{
    QJsonDocument doc = QJsonDocument::fromJson(bytes);
    qDebug()<<"from server...";
    //qDebug()<<doc.toJson();
    QJsonObject item=doc.object();
    QJsonArray bulletArray = item["bullets"].toArray();
    QJsonArray playerArray = item["players"].toArray();

    // check if to delete a bullet, can be done in ****** parallel******
//%%%%%%%%%% ERROR
    for(int i=0;i<gameState->bullets.size();i++)
    {
        auto q = gameState->bullets.at(i);
        // if bullet does not exist then delete it
        if(!checkBullet(bulletArray,(q)->id))
        {
//***            // delete bullet
            qDebug()<<"*******bullet deleted id:"<<(q->id);
            game->scene->removeItem(q);
            (gameState->bullets).erase((gameState->bullets).begin()+i);
            delete (q);
        }

    }

    foreach(const QJsonValue & value , bulletArray)
            {
               QJsonObject obj = value.toObject();
               int bullet_id=obj["id"].toInt();
               bool team_a=obj["team"].toBool();
               bool flag=false;
               // for checking if not new bullet
               for(auto q = gameState->bullets.begin() ; q != gameState->bullets.end() ; q++)
               {
                   if((*q)->id==bullet_id)
                   {
                       flag=true;
                   }
               }

               // for creating new bullets, if new
               if(flag==false)
               {
                   qDebug()<<"new bullet added! id:"<<bullet_id;

                   //to add new bullet
                   bullet *new_bullet = new bullet(static_cast<enums::direc>(obj["dir"].toInt()),bullet_id, team_a);
                   new_bullet->setPos(obj["posX"].toDouble(),obj["posY"].toDouble());
                   gameState->addBullet(new_bullet);
                   game->scene->addItem(new_bullet);
                   // new bullet added
               }
            }

    foreach(const QJsonValue & value , playerArray)
            {
               QJsonObject obj = value.toObject();
               int player_id=obj["id"].toInt();
               bool team_a=obj["team"].toBool();
               int flag=0;
               for(auto q = gameState->players.begin() ; q != gameState->players.end() ; q++)
               {
                   if((*q)->id==player_id)
                   {
                       gameState->updatePlayer(player_id,QPoint(obj["posX"].toInt(),obj["posY"].toInt()));
                       flag=1;
                   }
               }

               if(flag==0)
               {
                   player *new_player;
                   //adding new player
                   new_player = new player(player_id, team_a);

                   new_player->setPos(obj["posX"].toDouble(),obj["posY"].toDouble());
                   gameState->addPlayer(new_player);
                   game->scene->addItem(new_player);
               }
            }
}
