#include <cstdlib>
#include "praetorian.h"

#include "mainwindow.h"

using namespace std;

/** 
 * Constructor
 *
 * @param coordinate x
 * @param coordinate y
 * @param pointer to parent window
 * @param pointer to parent scene 
 * @param pointer to player object
 */
Praetorian::Praetorian(double nx, double ny, MainWindow *mw, QGraphicsScene *s, Player *p) :
    QGraphicsRectItem(nx, ny, 70, 70) {
    x = nx;
    y = ny;
    width = 60;
    height = 60;
    velocityX = 0;
    velocityY = 4;
    life= 5;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/praetorian.png"), this, scene);
    player= p;
    
}

/**
 * Destructor
 */
Praetorian::~Praetorian(){

}

/** 
 * Take away one life 
 */
bool Praetorian::hit(){
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
int Praetorian::getVelocityX() {
    return velocityX;
}

/** 
 * Accessor for velocityY 
 */
int Praetorian::getVelocityY() {
    return velocityY;
}

/** 
 * Change velocityX 
 *
 * @param new value
 */
void Praetorian::setVelocityX( int vx ) {
    velocityX = vx;
}

/** 
 * Change velocityY 
 *
 * @param new value
 */
void Praetorian::setVelocityY( int vy ) {
    velocityY = vy;
}

/** 
 * Move the object 
 * 
 * @param width of window
 * @param height of window
 */
void Praetorian::move( int windowMaxX, int windowMaxY ) {
    
    x += ( (player->getX()) - (x) );
    y += velocityY;

    if ( x < 0 ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( (x+width) > windowMaxX-10 ) {
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
int Praetorian::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Praetorian::getY() {
    return y;
}

/**
 * Change X
 *
 * @param new x coordinate
 */
void Praetorian::setX(int nx) {
    x = nx;
}

/**
 * Change Y
 *
 * @param new y coordinate
 */
void Praetorian::setY(int ny) {
    y = ny;
}
