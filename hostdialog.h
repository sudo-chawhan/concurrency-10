#ifndef HOSTDIALOG_H
#define HOSTDIALOG_H

#include <QDialog>
#include <QString>
#include "serverscreen.h"

extern serverScreen *ss;

namespace Ui {
class hostdialog;
}


/**
 * @brief The hostdialog class
 */
class hostdialog : public QDialog
{
    Q_OBJECT

public:

    /**
      * @brief hostdialog
      * @param s
      * @param parent
      */
     hostdialog(QString s,QWidget *parent = 0);
    ~hostdialog();

private slots:

     /**
      * @brief on_pushButton_clicked
      */
     void on_pushButton_clicked();

private:
     /**
     * @brief ui
     */
    Ui::hostdialog *ui;
};

#endif // HOSTDIALOG_H
