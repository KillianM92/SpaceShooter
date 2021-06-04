/******************************************************
 *                                                    *
 *             SOURCE FILE FOR THE ENEMY              *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include "Enemy.h"                                      // Import of file "Enemy.h"
#include "Game.h"                                       // Import of file "Game.h"
#include <QTimer>                                       // QTimer class provides repetitive and single-shot timers
#include <QGraphicsScene>                               // QGraphicsScene class provides a surface for managing a large number of 2D graphical items
#include <QList>                                        // QList class is a template class that provides lists
#include <stdlib.h>                                     // Import of the library stdlib.h to use the function rand()

extern Game * game;                                     // There is an external global object called game to use pointers of Game.h

/******************************************************
 *                                                    *
 *      IMPLEMENTATION OF ENEMY IN SOURCE FILE        *
 *                                                    *
 ******************************************************/

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()        // Implementation of constructor function
{
    int random_number = rand() % 700;                   // Variable random_number with the function radn() modulo 700
    setPos(random_number,0);                            // Set random position for enemy with the random_number for x() and 0 for y()

    setPixmap(QPixmap(":/images/enemy.png"));           // Apply the image (graphics) to the enemy
    setTransformOriginPoint(50,50);                     // Definition of the origin transform point to rotate the image
    setRotation(180);                                   // Rotation of image of enemy by 180°

    QTimer * timer = new QTimer();                      // New Object QTimer which refers to the pointer of timer
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // Connecting timer to function move() for enemies

    timer->start(50);                                   // Starting the timer at 50 milliseconds
}

void Enemy::move()                                      // Implementation of the move() function for enemies
{
    setPos(x(),y()+5);                                  // Move the enemy down by 5 pixels

    if (pos().y() > 600){                               // Destroy enemy when it goes out of bounds (at the bottom of the screen)

        game->health->decrease();                       // Decrease the health when an enemy goes down
        scene()->removeItem(this);                      // Remove the item enemy from the scene (still in the down of heap)
        delete this;                                    // Delete the enemy from heap to save application memory
    }
}
