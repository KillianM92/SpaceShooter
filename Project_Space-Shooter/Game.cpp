/******************************************************
 *                                                    *
 *             SOURCE FILE FOR THE GAME              *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include "Game.h"                                                       // Import of file "Game.h"
#include "Enemy.h"                                                      // Import of file "Enemy.h"
#include <QGraphicsTextItem>                                            // QGraphicsTextItem class provides a text item that you can add to a QGraphicsScene to display formatted text
#include <QTimer>                                                       // QTimer class provides repetitive and single-shot timers
#include <QFont>                                                        // QFont class specifies a query for a font used for drawing text
#include <QMediaPlayer>                                                 // QMediaPlayer class allows the playing of a media source
#include <QBrush>                                                       // QBrush class defines the fill pattern of shapes drawn by QPainter
#include <QImage>                                                       // QImage class provides a hardware-independent image representation that allows direct access to the pixel data, and can be used as a paint device

/******************************************************
 *                                                    *
 *      IMPLEMENTATION OF GAME IN SOURCE FILE         *
 *                                                    *
 ******************************************************/

Game::Game(QWidget *parent)                                             // Implementation of constructor function
{
    scene = new QGraphicsScene();                                       // Creation of a new scene
    scene->setSceneRect(0,0,800,600);                                   // Dimensions of the scene will be a the position 0,0 and 800x600 pixels
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));              // Definition of background for the application

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);               // Removing Horizontal Scroll Bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                 // Removing Vertical Scroll Bar
    setFixedSize(800,600);                                              // Definition of the size of scene

    play_bar = new Play_Bar();                                          // Creation of player's plane
    play_bar->setPos(400,500);                                          // Definition of the position (here is centered)

    play_bar->setFlag(QGraphicsItem::ItemIsFocusable);                  // Make player's plane focusable
    play_bar->setFocus();                                               // Set a focus on the player's plane to control it
    scene->addItem(play_bar);                                           // Add the item to the scene

    score = new Score();                                                // Creation of the score
    scene->addItem(score);                                              // Add the item to the scene

    health = new Health();                                              // Creation of the health
    health->setPos(health->x()+660, health->y()+0);                     // Change of position for the text of health to the right
    scene->addItem(health);                                             // Add the item to the scene

    QTimer * timer = new QTimer();                                      // New object Qtimer to Spawn enemies
    QObject::connect(timer,SIGNAL(timeout()),play_bar,SLOT(spawn()));   // Connecting the timer with a signal, the player's plane and the spawn() function
    timer->start(1000);                                                 // Every 1000 milliseconds (1 second), an enemy is spawning on the map

    QMediaPlayer * music = new QMediaPlayer();                          // New object QMediaPLayer to play a background music
    music->setMedia(QUrl("qrc:/sounds/Travis Scott_Goosebumps.mp3"));   // Access to the music file in the ressources
    music->play();                                                      // Launch of the music

    show();                                                             // Opening of the application (it's showing the scene)
}
