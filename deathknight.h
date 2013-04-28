#ifndef DEATHKNIGHT_H
#define DEATHKNIGHT_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "praetorian.h"

class MainWindow;

/**
  
  */
class Deathknight : public QGraphicsRectItem {
public:
    Deathknight(double nx, double ny, MainWindow *mw, QGraphicsScene *s);
    ~Deathknight();
    void setX( int x );
    void setY( int y );
    void setVelocityX( int vx );
    void setVelocityY( int vy );
    bool hit();
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void move(int windowMaxX, int windowMaxY );
    void birth();
    MainWindow *window;
    QGraphicsScene *scene;

private:
    int x;
    int y;
    int width;
    int height;
    int velocityX;
    int velocityY;
    int life;
    QGraphicsPixmapItem *image;
};

#endif
