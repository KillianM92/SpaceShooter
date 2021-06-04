/******************************************************
 *                                                    *
 *             SOURCE FILE FOR THE SCORE              *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include "Score.h"                                                  // Import of the file "Score.h"
#include <QFont>                                                    // QFont class specifies a query for a font used for drawing text

/******************************************************
 *                                                    *
 *     IMPLEMENTATION OF SCORE IN SOURCE FILE         *
 *                                                    *
 ******************************************************/

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)      // Implementation of constructor function
{
    score = 0;                                                      // Initialization of the score to 0

    setPlainText(QString("Score: ") + QString::number(score));      // Draw the text ('Score: 0')
    setDefaultTextColor(Qt::yellow);                                // Set the colour of the text to green
    setFont(QFont("Times", 14, QFont::Bold));                       // Set the font to Times in size 14 with a bold text
}

void Score::increase(){                                             // Implementation of the increase() function for score
    score++;                                                        // Addition of 1 point in score
    setPlainText(QString("Score: ") + QString::number(score));      // Set a new text when a point of score is won ('Score: 1')
}

int Score::getScore(){                                              // Implementation of the getScore() function for score
    return score;                                                   // Return the value of score for reusing in the project
}
