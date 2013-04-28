
#include <cstdlib>
#include <iostream>
#include "rightMove.h"
#include "mainwindow.h"

RightMove::RightMove(double nx, double ny, Player *p) :
    QGraphicsRectItem(nx, ny, 40, 40) {

  player= p;
   
}

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
