#include <QApplication>
#include "game.h"
#include "server.h"
#include "mainwindow.h"
#include "dialog.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

//    Server *ser = new Server(3000);

    //game = new Game();
//    game->show();
    //mainwindow window;
    //window.show();
    dialog dialog1;
    dialog1.resize(500, 500);
    dialog1.show();


    return a.exec();
}
