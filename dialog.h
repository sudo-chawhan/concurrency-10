#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

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

};

#endif // DIALOG_H
