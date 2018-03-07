#include "server.h"

#include <QtWebSockets>
#include <QGraphicsScene>
#include <QtCore>
#include <QDebug>
#include <string>
#include <QTimer>

#include "player.h"
#include "player_teama.h"
#include "player_teamb.h"
#include <QMediaPlayer>

#include <cstdio>
using namespace std;

extern QGraphicsScene *scene;

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

    if (m_pWebSocketServer->listen(QHostAddress("0.0.0.0"), port))
    {

        qDebug() << "Server's connecting URL : " << m_pWebSocketServer->serverUrl();
        QTextStream(stdout) << "Chat Server listening on port " << port << '\n';
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &Server::onNewConnection);
        qDebug()<<"passed server onnewconnnection";
    }
}

Server::~Server()
{

}

void Server::startGameLoop(){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(sendGameStateToClients()));

    // start the timer
    timer->start(50);
}

void Server::sendGameStateToClients(){
    QJsonDocument doc = gameState->getJsonDocFromGameState();
    QByteArray bytes = doc.toJson();

    //qDebug()<<"server sent json message at game init:";
    //qDebug()<<bytes;

    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
    {
          (*i)->sendBinaryMessage(bytes);
    }
}

void Server::onNewConnection()
{
    qDebug()<<"new connection with client...";

    auto pSocket = m_pWebSocketServer->nextPendingConnection();
    QTextStream(stdout) << getIdentifier(pSocket) << " connected!\n";
    pSocket->setParent(this);

    connect(pSocket, &QWebSocket::textMessageReceived,
            this, &Server::onTextMessageFromClient);

    connect(pSocket, &QWebSocket::binaryMessageReceived,
            this, &Server::onBinaryMessageFromClient);

    connect(pSocket, &QWebSocket::disconnected,
            this, &Server::socketDisconnected);

    m_clients << pSocket;

//********can use mutex for new connection sending id

    // make new player
    player *new_player;
    if(gameState->players.size()%2==0){
        new_player = new player(playersConnected,true);
        new_player->setPos(start_a); // TODO generalize to always be in the middle bottom of screen
    }
   else{
        new_player = new player(playersConnected,false);
        new_player->setPos(start_b); // TODO generalize to always be in the middle bottom of screen
    }// make the player focusable and set it to be the current focus

    scene->addItem(new_player);
    gameState->players.push_back(new_player);

    std::string init_messsage="init:";
    init_messsage+=std::to_string(playersConnected);
    pSocket->sendTextMessage(QString::fromStdString(init_messsage));
    qDebug()<<"init message sent to client #"<<playersConnected;

    playersConnected++;

//**************mutex signal


    // if all clients are done start game loop
    // ...

//************** signal mutex

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
    if(key=="UP"){
        gameState->players.at(id)->moveUp();
    }
    if(key=="DOWN"){
        gameState->players.at(id)->moveDown();
    }
    if(key=="W"||key=="A"||key=="S"||key=="D"){
        bullet *new_bullet = gameState->createBullet(key,gameState->players.at(id)->team,gameState->players.at(id)->pos().x()+25,gameState->players.at(id)->pos().y()+25);
        scene->addItem(new_bullet);
        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/bullet/bullet.mp3"));

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
    qDebug()<<"message recieved for ready";
    if(message.startsWith("ready:")){
        //qDebug()<<"init message recieved: "<<message;
        QString m_id = message.mid(6,message.size()-6);
///***********mutex wait
        playersReady++;
///***********mutex signal
        if(playersReady==playersConnected){
              startGameLoop();
        }
    }
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
