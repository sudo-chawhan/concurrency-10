#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>


/**
 * @brief The Score class
 */
class Score: public QGraphicsTextItem{
public:

    /**
     * @brief Score
     * @param parent
     */
    Score(QGraphicsItem * parent=0);

    /**
     * @brief increase
     */
    void increase();

    /**
     * @brief getScore
     * @return
     */
    int getScore();
private:
    /**
     * @brief score
     */
    int score;
};

#endif // SCORE_H


