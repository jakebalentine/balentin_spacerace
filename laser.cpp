#include <cstdlib>
#include <iostream>
#include "laser.h"
#include "mainwindow.h"

using namespace std;

/** 
 * Constructor
 *
 * @param coordinate x
 * @param coordinate y
 * @param pointer to parent window
 */
Laser::Laser(double nx, double ny, MainWindow *mw) :
    QGraphicsRectItem(nx, ny, 20, 20) {
    x = nx;
    y = ny;
    width = 20;
    height = 20;
    velocityX = 0;
    velocityY = -7;
    window= mw;
    
}

/**
 * Destructor
 */
Laser::~Laser(){

}

/** 
 * Move the object 
 */
void Laser::move() {
    
    x += velocityX;
    y += velocityY;

    if ( y<0 ) {
      window->destroyLaser(this);
    }


    QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );

}

/**
 * Accessor for X
 */
int Laser::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Laser::getY() {
    return y;
}

