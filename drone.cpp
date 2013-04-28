#include <cstdlib>
#include "drone.h"

#include "mainwindow.h"

using namespace std;

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

Drone::~Drone(){

}

bool Drone::hit(){
  --life;
  if(life<1){
    return true;
  }
  else{
    return false;
  }
}

int Drone::getVelocityX() {
    return velocityX;
}

int Drone::getVelocityY() {
    return velocityY;
}

void Drone::setVelocityX( int vx ) {
    velocityX = vx;
}

void Drone::setVelocityY( int vy ) {
    velocityY = vy;
}

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


int Drone::getX() {
    return x;
}

int Drone::getY() {
    return y;
}

void Drone::setX(int nx) {
    x = nx;
}

void Drone::setY(int ny) {
    y = ny;
}
