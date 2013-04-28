#ifndef DRONE_H
#define DRONE_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class MainWindow;

/**
 * Drone enemy class that moves back and forth across the screen,
 * slowly advancing at the user. 
 */
class Drone : public QGraphicsRectItem {
public:
    /** Constructor */
    Drone(double nx, double ny, MainWindow *mw, QGraphicsScene *s);
    /** Destructor */
    ~Drone();
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
};

#endif
