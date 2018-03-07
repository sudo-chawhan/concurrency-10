#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "game.h"
#include "client.h"

bool pressed=false;

gamewindow::gamewindow(Client *client,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewindow)
{
    window_client = client;
    ui->setupUi(this);
}

gamewindow::~gamewindow()
{
    delete ui;
}


void gamewindow::on_radioButton_toggled(bool checked)
{
    window_client->team=true;
    qDebug()<<"team a selected";
}

void gamewindow::on_radioButton_2_toggled(bool checked)
{
    window_client->team=false;
    qDebug()<<"team b selected";
}

void gamewindow::on_pushButton_clicked()
{
    //function for ready
    if(!pressed){
        qDebug()<<"ready messsage sent to client";
        window_client->onReady();
        pressed=true;
    }

}
