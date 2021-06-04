/******************************************************
 *                                                    *
 *                 MAIN SOURCE FILE                   *
 *                                                    *
 ******************************************************/

/******************************************************
 *                                                    *
 *           IMPORT OF CLASSES FOR THIS FILE          *
 *                                                    *
 ******************************************************/

#include <QApplication>             // QApplication class manages the GUI application's control flow and main settings
#include "Game.h"                   // Import of the file "Game.h" which is used to launch the game
#include <QPushButton>
Game * game;                        // The object Game is pointing a variable game to re-use it in an external way

/******************************************************
 *                                                    *
 *      IMPLEMENTATION OF MAIN IN SOURCE FILE         *
 *                                                    *
 ******************************************************/

int main(int argc, char *argv[])    // Main function of the project that will launch it
{
    QApplication app(argc, argv);   // Creation of the QApplication

    game = new Game();              // Creation of a new game

    return app.exec();              // Return the process in the console
}
