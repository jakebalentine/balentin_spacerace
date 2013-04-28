#include <cstdlib>
#include "praetorian.h"

#include "mainwindow.h"

using namespace std;

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

Praetorian::~Praetorian(){

}

bool Praetorian::hit(){
  --life;
  if(life<1){
    return true;
  }
  else{
    return false;
  }
}

int Praetorian::getVelocityX() {
    return velocityX;
}

int Praetorian::getVelocityY() {
    return velocityY;
}

void Praetorian::setVelocityX( int vx ) {
    velocityX = vx;
}

void Praetorian::setVelocityY( int vy ) {
    velocityY = vy;
}

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


int Praetorian::getX() {
    return x;
}

int Praetorian::getY() {
    return y;
}

void Praetorian::setX(int nx) {
    x = nx;
}

void Praetorian::setY(int ny) {
    y = ny;
}
