#include <QtWidgets>
#include <QGridLayout>
#include <QtGui>
#include "dialog.h"
#include "server.h"
#include "game.h"

Server *server;
Game * game;
bool isServer;

dialog::dialog(QWidget *parent)
     : QDialog(parent)
 {

     QPushButton *billButton ;
     billButton = new QPushButton("HOST");
     connect(billButton, SIGNAL(clicked()),
             this, SLOT(make_server()));

     QPushButton *benButton ;
     benButton = new QPushButton ("JOIN");
     connect (benButton,  SIGNAL(clicked()),
             this,  SLOT(make_client()));

     QGridLayout *myLayout = new QGridLayout;

     myLayout->addWidget(billButton, 1 ,0);
     myLayout->addWidget(benButton, 1 ,1);

     setLayout(myLayout);

     setWindowTitle("CTF-GAME");
 }


 void dialog::make_server()
 {
     isServer = true;
    server = new Server(3000);
 }

 void dialog::make_client()
 {
    game = new Game();
 }
