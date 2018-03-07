#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include "hostdialog.h"
#include "clientwindow.h"
#include "global.h"

/**
 * @brief The dialog class
 */
class dialog : public QDialog
{
    Q_OBJECT
public:

    /**
     * @brief Constructor
     * @param parent
     */
    dialog(QWidget * parent=0);

    /**
     * @brief myLabel:QLabel widget
     */
    QLabel *myLabel;

private slots:

    /**
      * @brief Make the server on pressing server button
      */
     void make_server();

     /**
      * @brief Make the host on pressing server button
      */
     void make_client();


};

#endif // DIALOG_H
