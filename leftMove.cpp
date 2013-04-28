
#include <cstdlib>
#include <iostream>
#include "leftMove.h"
#include "mainwindow.h"

LeftMove::LeftMove(double nx, double ny, MainWindow *mw, QGraphicsScene *s, Player *p) :
    QGraphicsRectItem(nx, ny, 40, 40) {

  player= p;
   
}

void LeftMove::mousePressEvent(QGraphicsSceneMouseEvent *event){
  int testX= player->getX();
   
   if (testX < 41 ){
    return;
  }
  if ( player->getVelocityX() == -4 ){
    player->setVelocityX(0);
    return;
  }
  player->setVelocityX(-4);
}
