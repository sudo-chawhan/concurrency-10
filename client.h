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
    /**
     * @brief flag object of team A
     */
    Flag *flagA;

    /**
     * @brief flag object of team B
     */
    Flag *flagB;

    /**
     * @brief true for team A else false
     */
    bool team;

    /**
     * @brief constructor
     * @param url_local :ip address
     * @param parent
     */
    explicit Client(QUrl url_local, QObject *parent = nullptr);

    /**
     * @brief destructor
     */
    virtual ~Client();

    /**
     * @brief variable storing state of game at any time
     */
    GameState *gameState;

    /**
     * @brief Sends message to server in the form of QSting
     * @param message :QString to server
     */

    void sendTextMessageToServer(QString message);

    /**
     * @brief Sends message to server in the form of QByteArray
     * @param message :Qbytearray to server
     */
    void sendBinaryMessageToServer(QByteArray message);

    /**
     * @brief Check whether given id bullet is present in Json object
     * @param bulletArray :Array of bullet in QJson
     * @param id :unique id
     * @return :int
     */
    int checkBullet(QJsonArray bulletArray,int id);

    /**
     * @brief main_id
     */
    int main_id;

    /**
     * @brief Sends message to server on connection of every new client
     */
    void onReady();

    /**
     * @brief Adds flag at the start of game
     */
    void onStart();


private slots:

    /**
     * @brief slot to establish communication
     */
    void onConnected();

    /**
     * @brief closes the socket
     */
    void closed();

    /**
     * @brief Recieves message from server in the form of QString
     * @param message :Message recieved from server
     */
    void onTextMessageReceived(QString message);

    /**
     * @brief Recieves message from server in the form of QByteArray
     * @param bytes :message recieved from server
     */
    void onBinaryMessageReceived(QByteArray bytes);

private:
    /**
     * @brief m_client_socket
     */
    QWebSocket m_client_socket;
};

#endif //CLIENT_H
