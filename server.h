#ifndef SERVER_H
#define SERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include "gamestate.h"
#include "global.h"
#include "flag.h"
#include "threadpool.h"

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)
QT_FORWARD_DECLARE_CLASS(QString)

class Server : public QObject
{
    Q_OBJECT
public:
    // use mutex for both
    int playersReady=0;
    int playersConnected=0;
    Flag *flagA;
    Flag *flagB;
    explicit Server(int max_threads,quint16 port, QObject *parent = nullptr);
    virtual ~Server();
    threadPool serverThreadPool;
    GameState *gameState;
    void onFlagScore_A();
    void onFlagScore_B();
    void startGameLoop();
    void onFlagDropped_A();
    void onFlagDropped_B();

private slots:
    void sendGameStateToClients();
    void onNewConnection();
    void onTextMessageFromClient(const QString &message);
    void onBinaryMessageFromClient(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
};

#endif //SERVER_H
