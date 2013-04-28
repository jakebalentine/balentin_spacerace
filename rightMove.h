#ifndef RIGHTMOVE_H
#define RIGHTMOVE_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "player.h"

class MainWindow;

/**
  
  */
class RightMove : public QGraphicsRectItem {

public:
    RightMove(double nx, double ny, MainWindow *mw, QGraphicsScene *s, Player *p);
    
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Player *player;

};

#endif
