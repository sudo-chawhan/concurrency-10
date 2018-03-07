#include "server.h"

#include <QtWebSockets>
#include <QGraphicsScene>
#include <QtCore>
#include <QDebug>
#include <string>
#include <QTimer>

#include "player.h"

#include <cstdio>
using namespace std;

extern QGraphicsScene *scene;

QT_USE_NAMESPACE

bool isFlagATaken=false;
bool isFlagBTaken=false;
int takersIDA;
int takersIDB;


static QString getIdentifier(QWebSocket *peer)
{
    return QStringLiteral("%1:%2").arg(peer->peerAddress().toString(),
                                       QString::number(peer->peerPort()));
}

Server::Server(int max_threads,quint16 port, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Chat Server"),
                                            QWebSocketServer::NonSecureMode,
                                            this)),serverThreadPool(max_threads)
{
    gameState = new GameState();
    flagA=new Flag(true);
    flagB=new Flag(false);


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

void Server::onFlagScore_A()
{
    onFlagDropped_B();
    qDebug()<<"score incremented a";
    (gameState->score_a)++;
}

void Server::onFlagScore_B()
{
    onFlagDropped_A();
    qDebug()<<"score incremented b";
    (gameState->score_b)++;
}

void Server::startGameLoop(){

    qDebug()<<"sending start message to all the clients...";
    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
    {
          (*i)->sendTextMessage(QString::fromStdString("start"));
    }
    qDebug()<<"sent start message to all the clients";

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(sendGameStateToClients()));

    // start the timer
    timer->start(50);
}

void Server::onFlagDropped_A()
{
    // drop flagA make flag visible and send all clients text that flag is dropped and make flag visible
    std::string drop_message;
    isFlagATaken=false;
    drop_message="dropA:";
    scene->addItem(flagA);

    drop_message +=std::to_string(takersIDA);
    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
    {
          (*i)->sendTextMessage(QString::fromStdString(drop_message));
    }

}

void Server::onFlagDropped_B()
{
    // drop flagA make flag visible and send all clients text that flag is dropped and make flag visible
    std::string drop_message;
    isFlagBTaken=false;
    drop_message="dropB:";
    scene->addItem(flagB);

    drop_message+=std::to_string(takersIDB);
    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
    {
          (*i)->sendTextMessage(QString::fromStdString(drop_message));
    }

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

///********can use mutex for new connection sending id


    std::string init_messsage="init:";
    init_messsage+=std::to_string(playersConnected);
    pSocket->sendTextMessage(QString::fromStdString(init_messsage));
    qDebug()<<"init message sent to client #"<<playersConnected;

    player *new_player = new player(playersConnected,true); // dummy entry

    scene->addItem(new_player);
    gameState->players.push_back(new_player);

    playersConnected++;

///**************mutex signal
    scene->addItem(flagA);
    scene->addItem(flagB);

}

void Server::onBinaryMessageFromClient(QByteArray message){
    qDebug()<<"before threadpool allocation";
    serverThreadPool.thread_assigner([&message,&gameState,&takersIDA,&takersIDB,&isFlagATaken,&isFlagBTaken,&scene,&m_clients](QByteArray message,GameState *gameState,int takersIDA,int takersIDB,bool isFlagATaken,bool isFlagBTaken,QGraphicsScene *scene,QList<QWebSocket *> m_clients){
        qDebug()<<"inside threadpool ";
            QJsonDocument item_doc = QJsonDocument::fromJson(message);
            QJsonObject item_object = item_doc.object();
            int id = item_object["id"].toInt();

            QString key = item_object["key"].toString();

            if(key=="LEFT"){
                ///use mutex for flag
                ///below: returns whether flag taken or not
                bool flagTaken=gameState->players.at(id)->moveLeft();
                if(flagTaken==true){
                    std::string take_messsage;
                    if(gameState->players.at(id)->team) {
                        gameState->players.at(id)->setPixmap(QPixmap(":images/red_playerwithblueflag.png"));
                        takersIDB=id;
                        isFlagBTaken=true;
                        take_messsage="takerB:";
                        scene->removeItem(flagB);
                    }
                    else{
                        gameState->players.at(id)->setPixmap(QPixmap(":images/blue_playerwithredflag.png"));
                        isFlagATaken=true;
                        takersIDA=id;
                        take_messsage="takerA:";
                        scene->removeItem(flagA);
                    }

                    take_messsage+=std::to_string(id);
                    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
                    {
                        (*i)->sendTextMessage(QString::fromStdString(take_messsage));
                    }

                }
            }
            if(key=="RIGHT"){
                bool flagTaken = gameState->players.at(id)->moveRight();
                if(flagTaken==true){
                    std::string take_messsage;
                    if(gameState->players.at(id)->team) {
                        gameState->players.at(id)->setPixmap(QPixmap(":images/red_playerwithblueflag.png"));
                        takersIDB=id;
                        isFlagBTaken=true;
                        take_messsage="takerB:";
                        scene->removeItem(flagB);
                    }
                    else{
                        gameState->players.at(id)->setPixmap(QPixmap(":images/blue_playerwithredflag.png"));
                        isFlagATaken=true;
                        takersIDA=id;
                        take_messsage="takerA:";
                        scene->removeItem(flagA);
                    }

                    take_messsage+=std::to_string(id);
                    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
                    {
                        (*i)->sendTextMessage(QString::fromStdString(take_messsage));
                    }

                }
            }
            if(key=="UP"){
                bool flagTaken = gameState->players.at(id)->moveUp();
                if(flagTaken==true){
                    std::string take_messsage;
                    if(gameState->players.at(id)->team) {
                        gameState->players.at(id)->setPixmap(QPixmap(":images/red_playerwithblueflag.png"));
                        takersIDB=id;
                        isFlagBTaken=true;
                        take_messsage="takerB:";
                        scene->removeItem(flagB);
                    }
                    else{
                        gameState->players.at(id)->setPixmap(QPixmap(":images/blue_playerwithredflag.png"));
                        isFlagATaken=true;
                        takersIDA=id;
                        take_messsage="takerA:";
                        scene->removeItem(flagA);
                    }

                    take_messsage+=std::to_string(id);
                    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
                    {
                        (*i)->sendTextMessage(QString::fromStdString(take_messsage));
                    }

                }
            }
            if(key=="DOWN"){
                bool flagTaken = gameState->players.at(id)->moveDown();
                if(flagTaken==true){
                    std::string take_messsage;
                    if(gameState->players.at(id)->team) {
                        gameState->players.at(id)->setPixmap(QPixmap(":images/red_playerwithblueflag.png"));
                        takersIDB=id;
                        isFlagBTaken=true;
                        take_messsage="takerB:";
                        scene->removeItem(flagB);
                    }
                    else{
                        gameState->players.at(id)->setPixmap(QPixmap(":images/blue_playerwithredflag.png"));
                        isFlagATaken=true;
                        takersIDA=id;
                        take_messsage="takerA:";
                        scene->removeItem(flagA);
                    }

                    take_messsage+=std::to_string(id);
                    for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
                    {
                        (*i)->sendTextMessage(QString::fromStdString(take_messsage));
                    }

                }
            }
            if(key=="W"||key=="A"||key=="S"||key=="D"){
                qDebug()<<"press W";
                bullet *new_bullet = gameState->createBullet(key,gameState->players.at(id)->team,gameState->players.at(id)->pos().x()+25,gameState->players.at(id)->pos().y()+25);
                scene->addItem(new_bullet);
            }
            qDebug()<<"reached before json creation";
            QJsonDocument doc = gameState->getJsonDocFromGameState();
            QByteArray bytes = doc.toJson();

            for (QList<QWebSocket*>::iterator i = m_clients.begin(); i != m_clients.end(); i++)
            {
                (*i)->sendBinaryMessage(bytes);
            }
      });


}

void Server::onTextMessageFromClient(const QString &message)
{
    qDebug()<<"message recieved for ready";

        //qDebug()<<"init message recieved: "<<message;

        // make new player for client in server
        if(message.startsWith("readyA:")){
            int m_id = message.mid(7,message.size()-7).toInt();
            gameState->players.at(m_id)->team=true;
            gameState->players.at(m_id)->setPixmap(QPixmap(":/images/space_shipA.png"));
            gameState->players.at(m_id)->setPos(start_a);
        }
       if(message.startsWith("readyB:")){
           int m_id = message.mid(7,message.size()-7).toInt();
           gameState->players.at(m_id)->team=false;
           gameState->players.at(m_id)->setPixmap(QPixmap(":/images/space_shipB.png"));
           gameState->players.at(m_id)->setPos(start_b);

        }// make the player focusable and set it to be the current focus

///***********mutex wait
        playersReady++;
///***********mutex signal


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
