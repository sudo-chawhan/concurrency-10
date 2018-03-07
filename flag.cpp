#include "flag.h"
#include <QBrush>
#include "global.h"

Flag::Flag(bool team1, QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    team=team1;
    if(team){
        setPixmap(QPixmap(":/images/red_flag.png"));
        setPos(flagPosA);
    }
    else{
        setPixmap(QPixmap(":/images/blue_flag.png"));
        setPos(flagPosB);
    }
}
