#include <cstdlib>
#include <iostream>
#include "player.h"
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

/**
 * Destructor
 */
Player::~Player(){

}

/**
 * Fire laser
 */
void Player::fire(){
  Laser *laser= new Laser(x+5, y-20, window);
  QBrush brush(Qt::red);
  laser->setBrush(brush);
  window->addLaser(laser);
}

/** 
 * Triggered when user clicks object
 *
 * @param triggered mouse event
 */
void Player::mousePressEvent(QGraphicsSceneMouseEvent *event){
  fire();
}

/** 
 * Accessor for velocityX 
 */
int Player::getVelocityX() {
    return velocityX;
}

/** 
 * Accessor for velocityY 
 */
int Player::getVelocityY() {
    return velocityY;
}

/** 
 * Change velocityX 
 *
 * @param new value
 */
void Player::setVelocityX( int vx ) {
    velocityX = vx;
}

/** 
 * Change velocityY 
 *
 * @param new value
 */
void Player::setVelocityY( int vy ) {
    velocityY = vy;
}

/** 
 * Increase score multiplier 
 */
void Player::increaseMultiplier(){
  multiplier++;
}

/** 
 * Add points to score 
 *
 * @param Points to add
 */
void Player::increasePoints(int points){
  score= score + (points*multiplier);
}

/** 
 * Take away one life 
 */
void Player::decreaseLife(){
  life--;
  if(life<1){
    window->gameOver();
  }
}

/** 
 * Move the object 
 */
void Player::move() {
    
    x += velocityX;
    y += velocityY;

    //Check for collision
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

/**
 * Accessor for X
 */
int Player::getX() {
    return x;
}

/**
 * Accessor for Y
 */
int Player::getY() {
    return y;
}

/**
 * Accessor for score
 */
int Player::getScore(){
  return score;
}

/**
 * Accessor for lives
 */
int Player::getLife(){
  return life;
}

/**
 * Change X
 *
 * @param new x coordinate
 */
void Player::setX(int nx) {
    x = nx;
}

/**
 * Change Y
 *
 * @param new y coordinate
 */
void Player::setY(int ny) {
    y = ny;
}
