#include <QApplication>
#include "game.h"
#include "server.h"

Server *server;
Game * game;
bool isServer;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    isServer = false;
    //server= new Server(3000);

    game = new Game();
//    game->show();

    return a.exec();
}
