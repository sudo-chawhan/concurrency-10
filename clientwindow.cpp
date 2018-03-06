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
    //if(ip=="hihi")
    game =new Game();

}
