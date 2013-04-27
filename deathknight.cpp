#include <cstdlib>
#include "deathknight.h"

#include "mainwindow.h"

using namespace std;

Deathknight::Deathknight(double nx, double ny, MainWindow *mw, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 120, 120) {
    x = nx;
    y = ny;
    width = 60;
    height = 60;
    velocityX = 4;
    velocityY = 0;
    life= 2;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/deathknight.png"), this, scene);
    
}

Deathknight::~Deathknight(){

}

int Deathknight::getVelocityX() {
    return velocityX;
}

int Deathknight::getVelocityY() {
    return velocityY;
}

void Deathknight::setVelocityX( int vx ) {
    velocityX = vx;
}

void Deathknight::setVelocityY( int vy ) {
    velocityY = vy;
}

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

void Deathknight::birth(){
  
}


int Deathknight::getX() {
    return x;
}

int Deathknight::getY() {
    return y;
}

void Deathknight::setX(int nx) {
    x = nx;
}

void Deathknight::setY(int ny) {
    y = ny;
}
