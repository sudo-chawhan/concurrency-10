#include "hostdialog.h"
#include "ui_hostdialog.h"
#include <string>

hostdialog::hostdialog(QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hostdialog)
{
    ui->setupUi(this);
    this->setWindowTitle("HOST WINDOW");
    ui->label->setText("ENTER THE IP IN JOIN MENU :"+s);
}

hostdialog::~hostdialog()
{
    delete ui;
}

void hostdialog::on_pushButton_clicked()
{
    this->close();
    ss =new serverScreen();
}
