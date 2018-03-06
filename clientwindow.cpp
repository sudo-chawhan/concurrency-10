#include "clientwindow.h"
#include "ui_clientwindow.h"

clientwindow::clientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
}

clientwindow::~clientwindow()
{
    delete ui;
}
