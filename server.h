#ifndef SERVER_H
#define SERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <mutex>
#include "gamestate.h"
#include "global.h"
#include "flag.h"

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)
QT_FORWARD_DECLARE_CLASS(QString)

/**
 * @brief The Server class
 */
class Server : public QObject
{
    Q_OBJECT
public:
    // use mutex for both

    /**
     * @brief playersReady
     */
    int playersReady=0;

    /**
     * @brief playersConnected
     */
    int playersConnected=0;

    /**
     * @brief flagA
     */
    Flag *flagA;

    /**
     * @brief flagB
     */
    Flag *flagB;
    explicit Server(quint16 port, QObject *parent = nullptr);
    virtual ~Server();
    GameState *gameState;
    void startGameLoop();
    void onFlagDropped_A();
    void onFlagDropped_B();
    std::mutex mutex_ready;
    std::mutex player_connected;

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
