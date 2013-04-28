#ifndef PRAETORIAN_H
#define PRAETORIAN_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "player.h"

class MainWindow;

/**
  * Praetorian enemy class that follows the player's
  * x-coordinate and chases them.
  */
class Praetorian : public QGraphicsRectItem {
public:
    /** Constructor */
    Praetorian(double nx, double ny, MainWindow *mw, QGraphicsScene *s, Player* p);
    /** Destructor */
    ~Praetorian();
    /** Change X */
    void setX( int x );
    /** Change Y */
    void setY( int y );
    /** Change velocityX */
    void setVelocityX( int vx );
    /** Change velocityY */
    void setVelocityY( int vy );
    /** Take away one life */
    bool hit();
    /** Accessor for X */
    int getX();
    /** Accessor for Y */ 
    int getY();
    /** Accessor for velocityX */
    int getVelocityX();
    /** Accessor for velocityY */
    int getVelocityY();
    /** Move the object */
    void move(int, int);
    
private:
    /** Coordinate X */
    int x;
    /** Coordinate Y */
    int y;
    /** Rect width */
    int width;
    /** Rect height */
    int height;
    /** Object's horizontal speed */
    int velocityX;
    /** Object's vertical speed */
    int velocityY;
    /** Amount of lives */
    int life;
    /** Object's image */
    QGraphicsPixmapItem *image;
    /** Pointer to parent window */
    MainWindow *window;
    /** Pointer to parent scene */
    QGraphicsScene *scene;
    /** Pointer to player object */
    Player *player;

};

#endif
