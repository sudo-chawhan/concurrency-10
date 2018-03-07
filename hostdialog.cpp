#include "hostdialog.h"
#include "ui_hostdialog.h"
#include <string>
#include "server.h"

extern Server *server;

hostdialog::hostdialog(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hostdialog)
{
    ui->setupUi(this);
    this->setWindowTitle("HOST WINDOW");
    ui->label->setText("Press ok to start!"+s);
}

hostdialog::~hostdialog()
{
    delete ui;
}

void hostdialog::on_pushButton_clicked()
{
    if(server->playersConnected==server->playersReady){
        this->close();
        server->startGameLoop();
        ss =new serverScreen();
    }
}
