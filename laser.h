#ifndef LASER_H
#define LASER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class MainWindow;

/**
 * Laser object that is fired by player
 */
class Laser : public QGraphicsRectItem {

public:
    /** Constructor */
    Laser(double nx, double ny, MainWindow *mw);
    /** Destructor */
    ~Laser();
    /** Accessor for X */
    int getX();
    /** Accessor for Y */ 
    int getY();
    /** Move the object */
    void move();
    
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
    /** Pointer to parent window */
    MainWindow *window;

};

#endif
