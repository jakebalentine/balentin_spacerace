#include <cstdlib>
#include <iostream>
#include "laser.h"
#include "mainwindow.h"

using namespace std;

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

Laser::~Laser(){

}

void Laser::move( int windowMaxX, int windowMaxY ) {
    
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

int Laser::getX() {
    return x;
}

int Laser::getY() {
    return y;
}

