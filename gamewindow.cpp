#include "gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
}

gamewindow::~gamewindow()
{
    delete ui;
}


void gamewindow::on_radioButton_toggled(bool checked)
{
    team=true;
    qDebug()<<"team a selected";
}

void gamewindow::on_radioButton_2_toggled(bool checked)
{
    team=false;
    qDebug()<<"team b selected";
}

void gamewindow::on_pushButton_clicked()
{
    //function for ready
}
