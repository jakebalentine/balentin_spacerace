
#include <cstdlib>
#include <iostream>
#include "rightMove.h"
#include "mainwindow.h"

RightMove::RightMove(double nx, double ny, MainWindow *mw, QGraphicsScene *s, Player *p) :
    QGraphicsRectItem(nx, ny, 40, 40) {

  player= p;
   
}

void RightMove::mousePressEvent(QGraphicsSceneMouseEvent *event){
  int testX= player->getX();
  if ( (testX+40) > 560 ){
    return;
  }
  if ( player->getVelocityX() == 4 ){
    player->setVelocityX(0);
    return;
  }
  player->setVelocityX(4);
}
