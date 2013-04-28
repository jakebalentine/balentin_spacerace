#include <cstdlib>
#include <iostream>
#include "player.h"
#include "mainwindow.h"

using namespace std;

Player::Player(double nx, double ny, MainWindow *mw, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 40, 40) {
    x = nx;
    y = ny;
    width = 40;
    height = 40;
    velocityX = 0;
    velocityY = 0;
    life= 5;
    multiplier= 1;
    score= 0;
    window= mw;
    scene= s;
    image= new QGraphicsPixmapItem(QPixmap("images/player.png"), this, scene);
    image->setPos(x,y);
    
}

Player::~Player(){

}

void Player::fire(){
  Laser *laser= new Laser(x+5, y-20, window);
  QBrush brush(Qt::red);
  laser->setBrush(brush);
  window->addLaser(laser);
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event){
  fire();
}

int Player::getVelocityX() {
    return velocityX;
}

int Player::getVelocityY() {
    return velocityY;
}

void Player::setVelocityX( int vx ) {
    velocityX = vx;
}

void Player::setVelocityY( int vy ) {
    velocityY = vy;
}

void Player::increaseMultiplier(){
  multiplier++;
}

void Player::increasePoints(int points){
  score= score + (points*multiplier);
}

void Player::decreaseLife(){
  life--;
  if(life<1){
    window->gameOver();
  }
}

void Player::move() {
    
    x += velocityX;
    y += velocityY;

    if ( x < 41 ) {
        velocityX = 0;
    }

    if ( (x+width) > 560 ) {
         velocityX = 0;
    }


    QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );
    image->setPos(x,y);

}


int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}

int Player::getScore(){
  return score;
}

int Player::getLife(){
  return life;
}

void Player::setX(int nx) {
    x = nx;
}

void Player::setY(int ny) {
    y = ny;
}
