#include "clientwindow.h"
#include "ui_clientwindow.h"

Game * game;

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
    if(1)
    {
        QString url_string = "ws://"+ip+":3000";
        Client *client = new Client(QUrl(url_string));
        game_selection=new gamewindow();
        game_selection->show();
        this->deleteLater();
    }
    else
    {
        qDebug()<<"ENTER THE CORRECT IP ADDRESSS";
    }
    //game =new Game();

}
