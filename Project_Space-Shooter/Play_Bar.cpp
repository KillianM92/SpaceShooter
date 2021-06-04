/******************************************************
 *                                                    *
 *            SOURCE FILE FOR THE PLAY_BAR            *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include "Play_Bar.h"                                                   // Import of header file "Play_Bar.h"
#include "Bullet.h"                                                     // Import of header file "Bullet.h"
#include "Enemy.h"                                                      // Import of header file "Enemy.h"
#include <QKeyEvent>                                                    // QKeyEvent class describes a key event
#include <QGraphicsScene>

/******************************************************
 *                                                    *
 *     IMPLEMENTATION OF PLAY_BAR IN SOURCE FILE      *
 *                                                    *
 ******************************************************/

Play_Bar::Play_Bar(QGraphicsItem *parent): QGraphicsPixmapItem(parent){ // Implementation of constructor function

    bulletsound = new QMediaPlayer();                                   // New object QMediaPlayer for the bullet sound
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));              // Access to the file of bullet sound

    setPixmap(QPixmap(":/images/play_bar.png"));                        // Draw the graphic of player's plane
}

void Play_Bar::keyPressEvent(QKeyEvent *event)                          // Implementation of the keyPressEvent() function for Play_Bar
{
    if (event->key() == Qt::Key_Left){                                  // If the left arrow of the keyboard is pressed
        if (pos().x() > 0){                                             // And if the position of the player's plane is not under 0 for the x()
            setPos(x()-30,y());                                         // Move player's plane with 30 pixels in the left
        }
    }
    else if (event->key() == Qt::Key_Right){                            // If the right arrow of the keyboard is pressed
        if (pos().x() + 100 < 800){                                     // And if the position of the player's plane is not higher than the right side
            setPos(x()+30,y());                                         // Move player's plane with 30 pixels in the right
        }
    }
    else if (event->key() == Qt::Key_Up){                               // If the top arrow of the keyboard is pressed
        if(pos().y() > 0){                                              // And if the position of the player's plane is not under 0 for the y()
            setPos(x(),y()-30);                                         // Move player's plane with 30 pixels to the top
        }
    }
    else if (event->key() == Qt::Key_Down){                             // If the down arrow of the keyboard is pressed
        if(pos().y() +100 < 600){                                       // And if the position of the player's plane is not higher than the bottom side
            setPos(x(),y()+30);                                         // Move player's plane with 30 pixels down
        }
    }
    else if(event->key() == Qt::Key_Space){                             // If the key space of the keyboard is pressed

        Bullet * bullet = new Bullet();                                 // Create a bullet
        bullet->setPos(x() + 37,y() - 25);                              // Set the position of the bullet top center of the player's plane
        scene()->addItem(bullet);                                       // Add the bullet to the scene

        if (bulletsound->state() == QMediaPlayer::PlayingState){        // If the sound of the bullet is started
            bulletsound->setPosition(0);                                // Reset it or put the position to 0:00 seconds
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){   // Else if the sound of the bullet is stopped of finished
            bulletsound->play();                                        // Play the bullet sound
        }
    }
}

void Play_Bar::spawn()                                                  // Implementation of the spawn() function for Play_Bar (enemies in fact)
{
    Enemy * enemy = new Enemy();                                        // Creation of an enemy
    scene()->addItem(enemy);                                            // Add the enemy to the scene
}
                                                                        /* Enemies and player's plane are created at the same time to make more easier
                                                                          the launch and creation of the application */
