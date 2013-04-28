#include <cstdlib>
#include "care.h"

#include "mainwindow.h"

using namespace std;

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

Care::~Care(){

}

int Care::getVelocityX() {
    return velocityX;
}

int Care::getVelocityY() {
    return velocityY;
}

void Care::setVelocityX( int vx ) {
    velocityX = vx;
}

void Care::setVelocityY( int vy ) {
    velocityY = vy;
}

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


int Care::getX() {
    return x;
}

int Care::getY() {
    return y;
}

void Care::setX(int nx) {
    x = nx;
}

void Care::setY(int ny) {
    y = ny;
}
