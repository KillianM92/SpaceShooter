/******************************************************
 *                                                    *
 *             SOURCE FILE FOR THE HEALTH             *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include "Health.h"                                                 // Import of the file "Health.h"
#include <QFont>                                                    // QFont class specifies a query for a font used for drawing text

/******************************************************
 *                                                    *
 *     IMPLEMENTATION OF HEALTH IN SOURCE FILE        *
 *                                                    *
 ******************************************************/

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)    // Implementation of constructor function
{
    health = 3;                                                     // Initialization of the health to 3

    setPlainText(QString("Health: ") + QString::number(health));    // Draw the text ('Health: 3')
    setDefaultTextColor(Qt::green);                                 // Set the colour of the text to green
    setFont(QFont("Times", 14, QFont::Bold));                       // Set the font to Times in size 14 with a bold text
}

void Health::decrease(){                                            // Implementation of the decrease() function for health
    health--;                                                       // Substraction of 1 point in health
    setPlainText(QString("Health: ") + QString::number(health));    // Set a new text when a point of health is lost ('Health: 2')
}

int Health::getHealth(){                                            // Implementation of the getHealth() function for health
    return health;                                                  // Return the value of health for reusing in the project
}
