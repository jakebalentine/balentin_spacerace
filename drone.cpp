#include <cstdlib>
#include "drone.h"

#include "mainwindow.h"

using namespace std;

/** 
 * Constructor
 *
 * @param coordinate x
 * @param coordinate y
 * @param pointer to parent window
 * @param pointer to parent scene 
 */
Drone::Drone(double nx, double ny, MainWindow *mw, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 40, 40) {
    x = nx;
    y = ny;
    width = 60;
    height = 60;
    velocityX = 7;
    velocityY = 10;
    life= 3;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/drone.png"), this, scene);
    
}

/**
 * Destructor
 */
Drone::~Drone(){

}

/** 
 * Take away one life 
 */
bool Drone::hit(){
  --life;
  if(life<1){
    return true;
  }
  else{
    return false;
  }
}

/** 
 * Accessor for velocityX 
 */
int Drone::getVelocityX() {
    return velocityX;
}

/** 
 * Accessor for velocityY 
 */
int Drone::getVelocityY() {
    return velocityY;
}

/** 
 * Change velocityX 
 *
 * @param new value
 */
void Drone::setVelocityX( int vx ) {
    velocityX = vx;
}

/** 
 * Change velocityY 
 *
 * @param new value
 */
void Drone::setVelocityY( int vy ) {
    velocityY = vy;
}

/** 
 * Move the object 
 * 
 * @param width of window
 * @param height of window
 */
void Drone::move( int windowMaxX, int windowMaxY ) {
    
    x += velocityX;
    y += 1;

    if ( x < 0 ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( (x+width) > windowMaxX ) {
         velocityX = -velocityX;
         x+=velocityX;
    }

    if ( (y+height) > windowMaxY-50 ) {
         velocityX= 0;
         velocityY= 0;
         window->destroyDrone(this);
    }


    QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );
    image->setPos(x,y);

}

/**
 * Accessor for X
 */
int Drone::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Drone::getY() {
    return y;
}

/**
 * Change X
 *
 * @param new x coordinate
 */
void Drone::setX(int nx) {
    x = nx;
}

/**
 * Change Y
 *
 * @param new x coordinate
 */
void Drone::setY(int ny) {
    y = ny;
}
