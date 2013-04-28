#include <cstdlib>
#include "care.h"

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
Care::Care(double nx, double ny, MainWindow *mw, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 30, 30) {
    x = nx;
    y = ny;
    width = 30;
    height = 30;
    velocityX = 0;
    velocityY = 4;
    life= 2;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/carepackage.png"), this, scene);
    
}

/**
 * Destructor
 */
Care::~Care(){

}

/** 
 * Accessor for velocityX 
 */
int Care::getVelocityX() {
    return velocityX;
}

/** 
 * Accessor for velocityY 
 */
int Care::getVelocityY() {
    return velocityY;
}

/** 
 * Change velocityX 
 *
 * @param new value
 */
void Care::setVelocityX( int vx ) {
    velocityX = vx;
}

/** 
 * Change velocityY 
 *
 * @param new value
 */
void Care::setVelocityY( int vy ) {
    velocityY = vy;
}

/** 
 * Move the object 
 * 
 * @param width of window
 * @param height of window
 */
void Care::move( int windowMaxX, int windowMaxY ) {
    
    y += velocityY;


    if ( (y+height) > windowMaxY-50 ) {
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
int Care::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Care::getY() {
    return y;
}

/**
 * Change X
 *
 * @param new x coordinate
 */
void Care::setX(int nx) {
    x = nx;
}
/**
 * Change y
 *
 * @param new y coordinate
 */
void Care::setY(int ny) {
    y = ny;
}
