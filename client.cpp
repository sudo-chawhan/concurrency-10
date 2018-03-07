#include "client.h"
#include "player.h"
#include <QDebug>
#include <QJsonArray>
#include <QBrush>
#include <QImage>
#include <QJsonDocument>
#include "enums.h"
#include <QJsonObject>
#include <typeinfo>
#include "game.h"

Game *game;

Client::Client(QUrl url_local,QObject *parent){
    qDebug()<<"flags";
    flagA=new Flag(true);
    flagB=new Flag(false);
    qDebug()<<"flags crossed";

    qDebug()<<"scenes crossed";
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

void Client::onStart(){
    game = new Game(this);
    game->scene->addItem(flagA);
    game->scene->addItem(flagB);
}

void Client::onReady(){
    std::string ready_message;

    if(team)
        ready_message="readyA:";
    else
        ready_message="readyB:";

    ready_message+=std::to_string(main_id);
    m_client_socket.sendTextMessage(QString::fromStdString(ready_message));
    //qDebug()<<"init message sent to client #"<<playersConnected;
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
int Client::checkBullet(QJsonArray bulletArray,int id)
{
    int i=0;
    foreach(const QJsonValue & value , bulletArray){
        QJsonObject obj = value.toObject();
        int bullet_id=obj["id"].toInt();
        if(id==bullet_id){
            return i;
        }
        i++;
    }
    return -1;
}

void Client::closed()
{
    m_client_socket.close();
}

void Client::onTextMessageReceived(QString message){
    qDebug()<<"server text message recieved";

    if(message.startsWith("start")){
        onStart();
    }

    else if(message.startsWith("init:")){
        qDebug()<<"init message recieved: "<<message;
        QString m_id = message.mid(5,message.size()-5);
        main_id=m_id.toInt();
    }

    else if(message.startsWith("takerA:")){
        qDebug()<<"flagA taken message recieved: "<<message;
        int m_id = message.mid(7,message.size()-7).toInt();
        gameState->players.at(m_id)->setPixmap(QPixmap(":images/player.png"));
        game->scene->removeItem(flagA);
    }

    else if(message.startsWith("takerB:")){
        qDebug()<<"flagB taken message recieved: "<<message;
        int m_id = message.mid(7,message.size()-7).toInt();
        gameState->players.at(m_id)->setPixmap(QPixmap(":images/player.png"));
        game->scene->removeItem(flagB);
    }

    else if(message.startsWith("dropA:")){
        qDebug()<<"flagA dropped message recieved: "<<message;
        int m_id = message.mid(6,message.size()-6).toInt();
        gameState->players.at(m_id)->setPixmap(QPixmap(":images/space_shipB.png"));
        game->scene->addItem(flagA);
    }

    else if(message.startsWith("dropB:")){
        qDebug()<<"flagB dropped message recieved: "<<message;
        int m_id = message.mid(6,message.size()-6).toInt();
        gameState->players.at(m_id)->setPixmap(QPixmap(":images/space_shipA.png"));
        game->scene->addItem(flagB);
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
        bullet* q = gameState->bullets.at(i);
        // if bullet does not exist then delete it
        int index=checkBullet(bulletArray,(q)->id);
        if(index==-1)
        {
//***            // delete bullet
            qDebug()<<"*******bullet deleted id:"<<(q->id);
            game->scene->removeItem(q);
            (gameState->bullets).erase((gameState->bullets).begin()+i);
            delete (q);
        }else{
            QJsonObject obj = bulletArray[index].toObject();
            q->setPos(obj["posX"].toDouble(),obj["posY"].toDouble());
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
