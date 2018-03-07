#ifndef CLIENT_H
#define CLIENT_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include "gamestate.h"
#include "global.h"
#include "flag.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Flag *flagA;
    Flag *flagB;
    explicit Client(QUrl url_local, QObject *parent = nullptr);
    virtual ~Client();
    GameState *gameState;
    void sendTextMessageToServer(QString message);
    void sendBinaryMessageToServer(QByteArray message);
    int checkBullet(QJsonArray bulletArray,int id);
    int main_id;

private slots:
    void onConnected();
    void closed();
    void onTextMessageReceived(QString message);
    void onBinaryMessageReceived(QByteArray bytes);
private:
    QWebSocket m_client_socket;
};

#endif //CLIENT_H
