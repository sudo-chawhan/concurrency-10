#include "clientwindow.h"
#include "ui_clientwindow.h"


clientwindow::clientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CLIENT WINDOW");
    ui->label->setText("ENTER THE IP ADDRESS OF SERVER");
}

clientwindow::~clientwindow()
{
    delete ui;
}


void clientwindow::on_pushButton_clicked()
{
    ip=ui->lineEdit->text();
    //compare the ip with the given input
        QString url_string = "ws://"+ip+":3000";
        qDebug()<<"client's request url"<<url_string;
        Client *client = new Client(QUrl(url_string));
        qDebug()<<"created client!";
        game_selection=new gamewindow(client);
        game_selection->show();
        this->deleteLater();

    //game =new Game();

}
