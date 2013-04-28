#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Programming Assignment #5
 *
 * @section purpose Purpose/Overview
 * Create an interactive Qt experience where the user is able to play a game.
 * @section requirements Requirements
 * There must be 5 different things that appear randomly.
 * The user must be able to play the game and score points
 */
int main(int argc, char *argv[])
{
    int exitCode= 0;
    
    do{
      QApplication a(argc, argv);
      MainWindow w;

      w.show();
      exitCode= a.exec();
    } while (exitCode == -333);

    return exitCode;
}
