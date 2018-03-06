#ifndef HOSTDIALOG_H
#define HOSTDIALOG_H

#include <QDialog>

namespace Ui {
class hostdialog;
}

class hostdialog : public QDialog
{
    Q_OBJECT

public:
    explicit hostdialog(QWidget *parent = 0);
    ~hostdialog();

private:
    Ui::hostdialog *ui;
};

#endif // HOSTDIALOG_H
