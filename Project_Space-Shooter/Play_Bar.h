/******************************************************
 *                                                    *
 *            HEADER FILE FOR THE HEALTH              *
 *                                                    *
 ******************************************************/

#ifndef PLAY_BAR_H
#define PLAY_BAR_H

/******************************************************
 *                                                    *
 *         IMPORT OF CLASSES FOR THIS FILE            *
 *                                                    *
 ******************************************************/

#include <QGraphicsPixmapItem>                                  // QGraphicsPixmapItem class provides a pixmap item that you can add to a QGraphicsScene
#include <QObject>                                              // QObject class is the base class of all Qt objects
#include <QGraphicsItem>                                        // QGraphicsItem class is the base class for all graphical items in a QGraphicsScene
#include <QMediaPlayer>                                         // QMediaPlayer class allows the playing of a media source

/******************************************************
 *                                                    *
 *        FUNCTION OF PLAY_BAR IN HEADER FILE         *
 *                                                    *
 ******************************************************/

class Play_Bar: public QObject, public QGraphicsPixmapItem{     // Function of Play_Bar with qobject and qgraphicspixmapitem in parameters
    Q_OBJECT                                                    // Import of Q_Object
public:                                                         // Definition of a public function (implementation in the .cpp file)
    Play_Bar(QGraphicsItem *parent=0);                          // Constructor function of the play_bar with qgraphicsitem pointer parent = 0 in parameters
public slots:                                                   // Functions that will be assigned to play_bar
    void keyPressEvent(QKeyEvent * event);                      // Initialization of the function keyPressEvent() which is used to know if the player push a touch of the keyboard
    void spawn();                                               // Initialization of the function spawn() which the type is void because it returns nothing
private:                                                        // Private attribute of the class play_bar
    QMediaPlayer * bulletsound;                                 // Pointer between the variable bulletsound and the QMediaPlayer
};

#endif // PLAY_BAR_H
