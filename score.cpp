#include "score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialise score
    score=0;
    // make text to put on screen
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
}

void Score::increment(){
    score++;
    setPlainText(QString("Score: ")+QString::number(score));

}

int Score::getScore(){
    return score;
}
