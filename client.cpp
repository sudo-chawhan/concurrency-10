#include "client.h"
#include "player.h"
#include <QDebug>
#include <QJsonArray>
#include <QBrush>
#include <QImage>
#include <QJsonDocument>
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
    }
}

void Client::onBinaryMessageReceived(QByteArray bytes)
{
    QJsonDocument doc = QJsonDocument::fromJson(bytes);
    qDebug()<<"from server...";
    qDebug()<<doc.toJson();
    QJsonObject item=doc.object();
    QJsonArray bulletArray = item["bullets"].toArray();
    QJsonArray playerArray = item["players"].toArray();

    qDebug()<<"64";
    foreach(const QJsonValue & value , bulletArray)
            {
               QJsonObject obj = value.toObject();
               int bullet_id=obj["id"].toInt();
               bool team_here_a=obj["team"].toBool();
               int flag=0;
               // for updating bullets
               for(auto q = gameState->bullets.begin() ; q != gameState->bullets.end() ; q++)
               {
                   if((*q)->id==bullet_id)
                   {
                       // for updating bullet
                       //gameState->updatePlayer(bullet_id,QPoint(obj["posX"].toInt(),obj["posY"].toInt()));
                       flag=1;
                   }
               }

               // for creating new bullets
               if(flag==0)
               {
                   qDebug()<<"new bullet added! id:"<<bullet_id;
                   //this implies new player joins the game isko sochna hai apan ko
                   bullet *new_bullet = new bullet(bullet_id, team_here_a);
                   new_bullet->setPos(obj["posX"].toDouble(),obj["posY"].toDouble());
                   gameState->addBullet(new_bullet);
                   game->scene->addItem(new_bullet);
               }
            }
    foreach(const QJsonValue & value , playerArray)
            {
                qDebug()<<"67";
               QJsonObject obj = value.toObject();
               int player_id=obj["id"].toInt();
               bool team_here_a=obj["team"].toBool();
               int flag=0;
               qDebug()<<"72";
               for(auto q = gameState->players.begin() ; q != gameState->players.end() ; q++)
               {
                   qDebug()<<"75";
                   if((*q)->id==player_id)
                   {
                       qDebug()<<"76";
                       gameState->updatePlayer(player_id,QPoint(obj["posX"].toInt(),obj["posY"].toInt()));
                       flag=1;
                   }
               }

               if(flag==0)
               {
                   qDebug()<<"83";
                   //this implies new player joins the game isko sochna hai apan ko
                   player *new_player = new player(player_id, team_here_a);
                   qDebug()<<"86";
                   new_player->setPos(obj["posX"].toDouble(),obj["posY"].toDouble());
                   gameState->addPlayer(new_player);
                   new_player->setPixmap(QPixmap(":/images/player.png"));
                   game->scene->addItem(new_player);
                   qDebug()<<"88";
               }
            }
    qDebug()<<"client gamestate after server init json...";
    qDebug()<<gameState->getJsonDocFromGameState().toJson();
}
