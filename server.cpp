#include "server.h"

#include <QtWebSockets>
#include <QtCore>
#include <QDebug>
#include <string>

#include "player.h"
#include "player_teama.h"
#include "player_teamb.h"

#include <cstdio>
using namespace std;

QT_USE_NAMESPACE

static QString getIdentifier(QWebSocket *peer)
{
    return QStringLiteral("%1:%2").arg(peer->peerAddress().toString(),
                                       QString::number(peer->peerPort()));
}

Server::Server(quint16 port, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Chat Server"),
                                            QWebSocketServer::NonSecureMode,
                                            this))
{
    gameState = new GameState();

    if (m_pWebSocketServer->listen(QHostAddress::Any, port))
    {

        qDebug() << "Server's connecting URL : " << m_pWebSocketServer->serverUrl();
        QTextStream(stdout) << "Chat Server listening on port " << port << '\n';
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &Server::onNewConnection);
    }
}

Server::~Server()
{

}

void Server::startGameLoop(){

}

void Server::onNewConnection()
{
    qDebug()<<"new connection with client...";
    // id to send to client
    int id;
    // make new player
    player *new_player;
    if(gameState->players.size()==0){
        id=0;
        new_player = new player_teama(id,true);
        new_player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    }
   else{
        id=1;
        new_player = new player_teamb(id,false);
        new_player->setPos(400,100); // TODO generalize to always be in the middle bottom of screen
    }// make the player focusable and set it to be the current focus

    gameState->players.push_back(new_player);

    auto pSocket = m_pWebSocketServer->nextPendingConnection();
    QTextStream(stdout) << getIdentifier(pSocket) << " connected!\n";
    pSocket->setParent(this);

    connect(pSocket, &QWebSocket::textMessageReceived,
            this, &Server::onTextMessageFromClient);

    connect(pSocket, &QWebSocket::binaryMessageReceived,
            this, &Server::onBinaryMessageFromClient);

    connect(pSocket, &QWebSocket::disconnected,
            this, &Server::socketDisconnected);

    std::string init_messsage="init:";
    init_messsage+=std::to_string(id);
    pSocket->sendTextMessage(QString::fromStdString(init_messsage));
    qDebug()<<"init message sent to client #"<<id;

    m_clients << pSocket;

    // if all clients are done start game loop
    // ...
    if(id==1){
        QJsonDocument doc = gameState->getJsonDocFromGameState();
        QByteArray bytes = doc.toJson();

        qDebug()<<"server sent json message at game init:";
        qDebug()<<bytes;

        for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
        {
              (*i)->sendBinaryMessage(bytes);
        }
    }


}

void Server::onBinaryMessageFromClient(QByteArray message){
    // should be done in parallel
    QJsonDocument item_doc = QJsonDocument::fromJson(message);
    QJsonObject item_object = item_doc.object();
    int id = item_object["id"].toInt();
    QString key = item_object["key"].toString();

    if(key=="LEFT"){
        gameState->players.at(id)->moveLeft();
    }
    if(key=="RIGHT"){
        gameState->players.at(id)->moveRight();
    }
    if(key=="SPACE"){
        gameState->createBullet(gameState->players.at(id)->team,gameState->players.at(id)->pos().x(),gameState->players.at(id)->pos().y());
    }

    QJsonDocument doc = gameState->getJsonDocFromGameState();
    QByteArray bytes = doc.toJson();

    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
    {
          (*i)->sendBinaryMessage(bytes);
    }


}

void Server::onTextMessageFromClient(const QString &message)
{
    qDebug()<<"from client: "<<message;

}

void Server::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    QTextStream(stdout) << getIdentifier(pClient) << " disconnected!\n";
    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
