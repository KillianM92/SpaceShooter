/******************************************************
 *                                                    *
 *            HEADER FILE FOR THE HEALTH              *
 *                                                    *
 ******************************************************/

#ifndef HEALTH_H
#define HEALTH_H

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

class Health: public QGraphicsTextItem{     // Function of Health with qgraphicstextitem in parameters
public:                                     // Definition of a public function (implementation in the .cpp file)
    Health(QGraphicsItem * parent=0);       // Constructor function of the health with qgraphicsitem pointer parent = 0 in parameters
public slots :                              // Functions that will be assigned to health
    void decrease();                        // Initialization of the function decrease() which the type is void because it returns nothing
    int getHealth();                        // Initialization of the function getHealth() which the type is int because it returns a whole number
private:                                    // Private attribute of the class health
    int health;                             // Variable which the type is integer because it's a number and it's use in the function getHealth()
};

#endif // HEALTH_H
