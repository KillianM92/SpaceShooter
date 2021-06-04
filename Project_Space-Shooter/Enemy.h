/******************************************************
 *                                                    *
 *              HEADER FILE FOR THE ENEMY             *
 *                                                    *
 ******************************************************/

#ifndef ENEMY_H
#define ENEMY_H

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include <QGraphicsPixmapItem>                              // QGraphicsItem class is the base class for all graphical items in a QGraphicsScene
#include <QObject>                                          // QObject class is the base class of all Qt objects

/******************************************************
 *                                                    *
 *         FUNCTION OF ENEMY IN HEADER FILE           *
 *                                                    *
 ******************************************************/

class Enemy: public QObject, public QGraphicsPixmapItem{    // Function of Enemy with qobject and qgraphicspixmapitem in parameters
    Q_OBJECT                                                // Import of the class Q_Object
public:                                                     // Definition of a public function (implementation in the .cpp file)
    Enemy();                                                // Constructor function of enemy
public slots:                                               // Functions that will be assigned to enemies
    void move();                                            // Initialization of the function move() which the type is void because it returns nothing
};

#endif // ENEMY_H
