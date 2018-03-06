#ifndef HOSTDIALOG_H
#define HOSTDIALOG_H

#include <QDialog>
#include <QString>
#include "serverscreen.h"

extern serverScreen *ss;

namespace Ui {
class hostdialog;
}

class hostdialog : public QDialog
{
    Q_OBJECT

public:
     hostdialog(QString s,QWidget *parent = 0);
    ~hostdialog();

private slots:
     void on_pushButton_clicked();

private:
    Ui::hostdialog *ui;
};

#endif // HOSTDIALOG_H
