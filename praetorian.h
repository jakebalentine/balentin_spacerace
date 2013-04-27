#ifndef PRAETORIAN_H
#define PRAETORIAN_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "player.h"

class MainWindow;

/**
  
  */
class Praetorian : public QGraphicsRectItem {
public:
    Praetorian(double nx, double ny, MainWindow *mw, QGraphicsScene *s, Player* p);
    ~Praetorian();
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
    Player *player;

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
