#include "flag.h"
#include <QBrush>
#include "global.h"

Flag::Flag(bool team1, QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    team=team1;
    if(team)
        setPos(flagPosA);
    else
        setPos(flagPosB);

    setPixmap(QPixmap(":/images/bullet.png"));
}
