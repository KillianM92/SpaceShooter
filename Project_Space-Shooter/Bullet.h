/******************************************************
 *                                                    *
 *              HEADER FILE FOR THE BULLET            *
 *                                                    *
 ******************************************************/

#ifndef BULLET_H
#define BULLET_H

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include <QGraphicsPixmapItem>                              // QGraphicsPixmapItem class provides a pixmap item that you can add to a QGraphicsScene
#include <QGraphicsItem>                                    // QGraphicsItem class is the base class for all graphical items in a QGraphicsScene
#include <QObject>                                          // QObject class is the base class of all Qt objects

/******************************************************
 *                                                    *
 *         FUNCTION OF BULLET IN HEADER FILE          *
 *                                                    *
 ******************************************************/

class Bullet: public QObject,public QGraphicsPixmapItem{    // Function of Bullet with the qobject and qgraphicspixmapitem in parameters
    Q_OBJECT                                                // Import of the class Q_Object
public:                                                     // Definition of a public function (implementation in the .cpp file)
    Bullet(QGraphicsItem * parent=0);                       // Constructor function of bullet with the class QGraphicsItem in parameter with a pointer to parent=0
public slots:                                               // Functions that will be assigned to bullets
    void move();                                            // Initialization of the function move() which the type is void because it returns nothing
};

#endif // BULLET_H
