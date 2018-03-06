#include "hostdialog.h"
#include "ui_hostdialog.h"

hostdialog::hostdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hostdialog)
{
    ui->setupUi(this);
}

hostdialog::~hostdialog()
{
    delete ui;
}
