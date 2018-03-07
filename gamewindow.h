#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QDebug>
#include "client.h"

namespace Ui {
class gamewindow;
}


/**
 * @brief The gamewindow class
 */
class gamewindow : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief gamewindow
     * @param client
     * @param parent
     */
    explicit gamewindow(Client *client,QWidget *parent = 0);

    ~gamewindow();
    /**
     * @brief team
     */
    bool team;
    /**
     * @brief window_client
     */
    Client *window_client;

private slots:

    /**
     * @brief on_radioButton_toggled
     * @param checked
     */
    void on_radioButton_toggled(bool checked);

    /**
     * @brief on_radioButton_2_toggled
     * @param checked
     */
    void on_radioButton_2_toggled(bool checked);

    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

private:

    /**
     * @brief ui
     */
    Ui::gamewindow *ui;
};

#endif // GAMEWINDOW_H
