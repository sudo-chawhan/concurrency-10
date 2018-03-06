#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

namespace Ui {
class clientwindow;
}

class clientwindow : public QDialog
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = 0);
    ~clientwindow();

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
