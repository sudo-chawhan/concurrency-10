#include <QApplication>
#include "game.h"
#include "server.h"
#include "mainwindow.h"
#include "dialog.h"

Server *server;
Game * game;
bool isServer;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    isServer = false;
    //server= new Server(3000);

    //Server *ser = new Server(3000);

    //game = new Game();
    //game->show();
    //mainwindow window;
    //window.show();
    dialog dialog1;
    dialog1.resize(500, 500);
    dialog1.show();


    return a.exec();
}
