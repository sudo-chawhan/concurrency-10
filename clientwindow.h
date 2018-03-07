#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include<QString>
#include <QDebug>
#include "game.h"
#include "gamewindow.h"

extern Game * game;

namespace Ui {
class clientwindow;
}

/**
 * @brief The clientwindow class
 */
class clientwindow : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief constructor
     * @param parent
     */
    explicit clientwindow(QWidget *parent = 0);

    /**
      *@brief Desturctor
      */
    ~clientwindow();

    /**
     * @brief ip :ip address entered
     */
    QString ip;

    /**
     * @brief open the game selection dialog
     */
    gamewindow * game_selection;

private slots:

    /**
     * @brief Action taken on pushing button=entered ip address
     */
    void on_pushButton_clicked();

private:

    /**
     * @brief UI interface
     */
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
