
#include <cstdlib>
#include <iostream>
#include "rightMove.h"
#include "mainwindow.h"

/** 
 * Constructor
 *
 * @param coordinate x
 * @param coordinate y
 * @param pointer to player object
 * @param pointer to parent scene 
 */
RightMove::RightMove(double nx, double ny, Player *p, QGraphicsScene *s) :
    QGraphicsRectItem(nx, ny, 40, 40) {

  player= p;
  scene= s;
  image= new QGraphicsPixmapItem(QPixmap("images/blackhole.png"), this, scene);
  image->setPos(nx,ny);
   
}

/**
 *  Event triggered when object is clicked
 */
void RightMove::mousePressEvent(QGraphicsSceneMouseEvent *event){
  int testX= player->getX();
  
  player->fire();
  
  if ( (testX+40) > 560 ){
    return;
  }
  if ( player->getVelocityX() == 4 ){
    player->setVelocityX(0);
    return;
  }
  player->setVelocityX(4);
}
