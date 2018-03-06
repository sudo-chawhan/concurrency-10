#ifndef SERVER_H
#define SERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include "gamestate.h"
#include "global.h"

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
    explicit Server(quint16 port, QObject *parent = nullptr);
    virtual ~Server();
    GameState *gameState;
    void startGameLoop();

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
