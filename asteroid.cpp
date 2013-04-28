#include <cstdlib>
#include "asteroid.h"

#include "mainwindow.h"

using namespace std;

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

Asteroid::~Asteroid(){

}

bool Asteroid::hit(){
  --life;
  if(life<1){
    return true;
  }
  else{
    return false;
  }
}

int Asteroid::getVelocityX() {
    return velocityX;
}

int Asteroid::getVelocityY() {
    return velocityY;
}

void Asteroid::setVelocityX( int vx ) {
    velocityX = vx;
}

void Asteroid::setVelocityY( int vy ) {
    velocityY = vy;
}

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


int Asteroid::getX() {
    return x;
}

int Asteroid::getY() {
    return y;
}

void Asteroid::setX(int nx) {
    x = nx;
}

void Asteroid::setY(int ny) {
    y = ny;
}
