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

void gamewindow::on_radioButton_clicked()
{

}

void gamewindow::on_radioButton_2_clicked()
{

}

void gamewindow::on_pushButton_clicked()
{

}
