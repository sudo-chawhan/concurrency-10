#ifndef FLAG_H
#define FLAG_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


/**
 * @brief The Flag class
 */
class Flag: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:

    /**
     * @brief team:true if Team A else false
     */
    bool team;

    /**
     * @brief Constructor
     * @param team1:Team A or not
     * @param parent
     */
    Flag(bool team1,QGraphicsItem * parent=0);
};

#endif // FLAG_H
