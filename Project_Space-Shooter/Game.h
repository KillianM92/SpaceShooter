/******************************************************
 *                                                    *
 *              HEADER FILE FOR THE GAME              *
 *                                                    *
 ******************************************************/

#ifndef GAME_H
#define GAME_H

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include <QGraphicsView>            // QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene
#include <QWidget>                  // QWidget class is the base class of all user interface objects
#include <QGraphicsScene>           // QGraphicsScene class provides a surface for managing a large number of 2D graphical items
#include "Play_Bar.h"               // Import of the header file of the play_bar
#include "Score.h"                  // Import of the header file of the score
#include "Health.h"                 // Import of the header file of the score

/******************************************************
 *                                                    *
 *         FUNCTION OF GAME IN HEADER FILE            *
 *                                                    *
 ******************************************************/

class Game: public QGraphicsView{   // Function of Game with qgraphicsview in parameters
public:                             // Definition of a public function (implementation in the .cpp file)
    Game(QWidget * parent = 0);     // Constructor function of the game with qwidget pointer parent = 0 in parameters

    QGraphicsScene * scene;         // Pointer of the variable scene for the class qgraphicsscene
    Play_Bar * play_bar;            // Pointer of the variable play_bar with the file "Play_Bar.h"
    Score * score;                  // Pointer of the variable score with the file "Score.h"
    Health * health;                // Pointer of the variable score with the file "Health.h"
                                    // Pointers are defined here for reusing them in the project
};

#endif // GAME_H
