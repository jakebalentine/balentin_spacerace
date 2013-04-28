#include <cstdlib>
#include "asteroid.h"

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
Asteroid::Asteroid(double nx, double ny, MainWindow *mw, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 60, 60) {
    x = nx;
    y = ny;
    width = 60;
    height = 60;
    velocityX = 4;
    velocityY = 2;
    life= 2;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/asteroid.png"), this);
    
}

/**
 * Destructor
 */
Asteroid::~Asteroid(){

}

/** 
 * Take away one life 
 */
bool Asteroid::hit(){
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
int Asteroid::getVelocityX() {
    return velocityX;
}

/** 
 * Accessor for velocityY 
 */
int Asteroid::getVelocityY() {
    return velocityY;
}

/** 
 * Change velocityX 
 *
 * @param new value
 */
void Asteroid::setVelocityX( int vx ) {
    velocityX = vx;
}

/** 
 * Change velocityY 
 *
 * @param new value
 */
void Asteroid::setVelocityY( int vy ) {
    velocityY = vy;
}

/** 
 * Move the object
 *
 * @param length of window
 * @param height of window 
 */
void Asteroid::move( int windowMaxX, int windowMaxY ) {
    
    x += velocityX;
    y += velocityY;

    if ( x < 0 ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( y < -100 ) {
        velocityY = -velocityY;
        y +=velocityY;
    }

    if ( (x+width) > windowMaxX+200 ) {
         velocityX = -velocityX;
         x+=velocityX;
    }

    if ( (y+height) > windowMaxY+200 ) {
         velocityX= 0;
         velocityY= 0;
         window->destroyAsteroid(this);
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
int Asteroid::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Asteroid::getY() {
    return y;
}

/**
 * Change X
 *
 * @param new x coordinate
 */
void Asteroid::setX(int nx) {
    x = nx;
}

/**
 * Change Y
 *
 * @param new y coordinate
 */
void Asteroid::setY(int ny) {
    y = ny;
}
