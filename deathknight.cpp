#include <cstdlib>
#include "deathknight.h"

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
Deathknight::Deathknight(double nx, double ny, MainWindow *mw, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 120, 120) {
    x = nx;
    y = ny;
    width = 60;
    height = 60;
    velocityX = 4;
    velocityY = 0;
    life= 10;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/deathknight.png"), this, scene);
    
}

/**
 * Destructor
 */
Deathknight::~Deathknight(){

}

/** 
 * Take away one life 
 */
bool Deathknight::hit(){
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
int Deathknight::getVelocityX() {
    return velocityX;
}

/** 
 * Accessor for velocityY 
 */
int Deathknight::getVelocityY() {
    return velocityY;
}

/** 
 * Change velocityX 
 *
 * @param new value
 */
void Deathknight::setVelocityX( int vx ) {
    velocityX = vx;
}

/** 
 * Change velocityY 
 *
 * @param new value
 */
void Deathknight::setVelocityY( int vy ) {
    velocityY = vy;
}

/** 
 * Move the object 
 * 
 * @param width of window
 * @param height of window
 */
void Deathknight::move( int windowMaxX, int windowMaxY ) {
    
    x += velocityX;
    y += 0;

    if ( x < 0 ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( (x+width) > windowMaxX-60 ) {
         velocityX = -velocityX;
         x+=velocityX;
    }

    if ( (y+height) > windowMaxY-50 ) {
         velocityX= 0;
         velocityY= 0;
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
int Deathknight::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Deathknight::getY() {
    return y;
}

/**
 * Change X
 *
 * @param new x coordinate
 */
void Deathknight::setX(int nx) {
    x = nx;
}

/**
 * Change Y
 *
 * @param new y coordinate
 */
void Deathknight::setY(int ny) {
    y = ny;
}
