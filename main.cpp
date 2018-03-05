#include <QApplication>
#include "game.h"
#include "server.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

//    Server *ser = new Server(3000);

    game = new Game();
//    game->show();

    return a.exec();
}
