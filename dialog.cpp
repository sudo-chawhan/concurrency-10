#include <QtWidgets>
#include <QGridLayout>
#include <QtGui>
#include <QDebug>
#include "dialog.h"
#include "serverscreen.h"
#include "game.h"

Server *server;
serverScreen *ss;
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
     hostdialog * host_sc=new hostdialog("hihi");
     host_sc->show();
     this->hide();
 }

 void dialog::make_client()
 {
    clientwindow *client=new clientwindow();
    client->show();
    this->hide();
 }
