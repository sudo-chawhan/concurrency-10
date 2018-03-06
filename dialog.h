#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include "hostdialog.h"
#include "clientwindow.h"

class dialog : public QDialog
{
    Q_OBJECT
public:
    dialog(QWidget * parent=0);
   // ~dialog();
    QLabel *myLabel;

private slots:
     void make_server();
     void make_client();
private:
    // hostdialog *host_sc;

};

#endif // DIALOG_H
