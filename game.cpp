#include <QtGui/QApplication>
#include "mainwindow.h"

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
