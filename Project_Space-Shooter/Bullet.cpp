/******************************************************
 *                                                    *
 *            SOURCE FILE FOR THE BULLET              *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include "Bullet.h"                                                         // Import of file Bullet.h
#include "Enemy.h"                                                          // Import of file Enemy.h
#include "Game.h"                                                           // Import of file Game.h
#include <QTimer>                                                           // QTimer class provides repetitive and single-shot timers
#include <QGraphicsScene>                                                   // QGraphicsScene class provides a surface for managing a large number of 2D graphical items

extern Game * game;                                                         // There is an external global object called game to use pointers of Game.h

/******************************************************
 *                                                    *
 *      IMPLEMENTATION OF BULLET IN SOURCE FILE       *
 *                                                    *
 ******************************************************/

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) // Implementation of constructor function
{
    setPixmap(QPixmap(":/images/bullet.png"));                              // Draw graphics of the bullet with the qpixmap element

    QTimer * timer = new QTimer();                                          // New QTimer object
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));                     // Connecting the timer object with the move() function

    timer->start(50);                                                       // Event of timer is starting after 50 milliseconds
}

void Bullet::move(){                                                        // Implementation of the move() function for bullets

    QList<QGraphicsItem *> colliding_items = collidingItems();              // If bullet collides with enemy, destroy both

    for (int i = 0, n = colliding_items.size(); i < n; ++i){                // If one of the colliding items is an Enemy, destroy the bullet and the enemy
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){                // We need to use the pointer otherwise the bullet is passing through the enemy and not destroy it
            game->score->increase();                                        // Increase the score

            scene()->removeItem(colliding_items[i]);                        // Remove the colliding items from the scene (stille in the top of heap)
            scene()->removeItem(this);

            delete colliding_items[i];                                      // Delete them from the heap to save memory in the application
            delete this;
        }
    }

        setPos(x(),y()-15);                                                 // If no collision with an Enemy, move the bullet forward by 15 pixels
        if (pos().y() < 0){                                                 // If the bullet is off the screen, destroy it
            scene()->removeItem(this);                                      // Remove bullets from the scene (still in the top of heap)
            delete this;                                                    // Delete them from the heap to save memory in the application
        }
}
