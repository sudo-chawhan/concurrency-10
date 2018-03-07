#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    scoreA = 0;
    scoreB = 0;

    // draw the text
    setPlainText(QString::number(scoreA) + QString(" : ") + QString::number(scoreB)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Score::update_score()
{
    setPlainText(QString::number(scoreA) + QString(" : ") + QString::number(scoreB));

}

