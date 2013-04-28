#ifndef CARE_H
#define CARE_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "player.h"

class MainWindow;

/**
  
  */
class Care : public QGraphicsRectItem {
public:
    Care(double nx, double ny, MainWindow *mw, QGraphicsScene *s);
    ~Care();
    void setX( int x );
    void setY( int y );
    void setVelocityX( int vx );
    void setVelocityY( int vy );
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void move(int windowMaxX, int windowMaxY );
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
