#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class MainWindow;

/**
 * Asteroid enemy class. Asteroids shoot off from a random location
 * and bounce off the screen.
 */
class Asteroid : public QGraphicsRectItem {
public:
    /** Constructor */
    Asteroid(double nx, double ny, MainWindow *mw, QGraphicsScene *scene);
    /** Destructor */
    ~Asteroid();
    /** Change X */
    void setX( int x );
    /** Change Y */
    void setY( int y );
    /** Change velocityX */
    void setVelocityX( int vx );
    /** Change velocityY */
    void setVelocityY( int vy );
    /** Deducts life once hit by laser */
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
    void move( int windowMaxX, int windowMaxY );

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
    /** Pointer to parent window */
    MainWindow *window;
    /** Pointer to parent scene */
    QGraphicsScene *scene;
    /** Object's image */
    QGraphicsPixmapItem *image;
};

#endif
