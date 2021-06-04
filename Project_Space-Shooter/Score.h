/******************************************************
 *                                                    *
 *            HEADER FILE FOR THE SCORE               *
 *                                                    *
 ******************************************************/

#ifndef SCORE_H
#define SCORE_H

/******************************************************
 *                                                    *
 *           IMPORT OF CLASS FOR THIS FILE            *
 *                                                    *
 ******************************************************/

#include <QGraphicsTextItem>                /* QGraphicsTextItem class provides a text item that you can
                                                add to a QGraphicsScene to display formatted text     */
/******************************************************
 *                                                    *
 *         FUNCTION OF HEALTH IN HEADER FILE          *
 *                                                    *
 ******************************************************/

class Score: public QGraphicsTextItem{      // Function of Score with qgraphicstextitem in parameters
public:                                     // Definition of a public function (implementation in the .cpp file)
    Score(QGraphicsItem * parent = 0);      // Constructor function of the score with qgraphicsitem pointer parent = 0 in parameters
public slots :                              // Functions that will be assigned to score
    void increase();                        // Initialization of the function increase() which the type is void because it returns nothing
    int getScore();                         // Initialization of the function getScore() which the type is int because it returns a whole number
private:                                    // Private attribute of the class score
    int score;                              // Variable which the type is integer because it's a number and it's use in the function getScore()
};

#endif // HEALTH_H
