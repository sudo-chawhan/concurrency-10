#include <QtWidgets>
#include <QGridLayout>
#include <QtGui>
#include "dialog.h"

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

 }

 void dialog::make_client()
 {

 }