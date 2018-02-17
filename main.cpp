#include <QApplication>
#include "game.h"
#include <time.h>
time_t start;
Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start=time(0);
    game = new Game();

    //game->show();

    return a.exec();
}
