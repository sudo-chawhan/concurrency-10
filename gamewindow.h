#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

namespace Ui {
class gamewindow;
}

class gamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::gamewindow *ui;
};

#endif // GAMEWINDOW_H
