#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    int scoreA;
    int scoreB;
    void update_score();
};

#endif // SCORE_H


