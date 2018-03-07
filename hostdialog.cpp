#include "hostdialog.h"
#include "ui_hostdialog.h"
#include <string>
#include "server.h"
#include "serverscreen.h"

extern Server *server;
extern serverScreen *ss;

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
        ss->view->show();
    }
}
