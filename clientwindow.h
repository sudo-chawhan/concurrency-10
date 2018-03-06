#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include<QString>
#include <QDebug>
#include "game.h"

extern Game * game;

namespace Ui {
class clientwindow;
}

class clientwindow : public QDialog
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = 0);
    ~clientwindow();
    QString ip;

private slots:
    void on_pushButton_clicked();

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
