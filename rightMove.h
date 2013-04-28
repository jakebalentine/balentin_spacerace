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
    RightMove(double nx, double ny, Player *p, QGraphicsScene *s);
    
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Player *player;
    QGraphicsPixmapItem *image;
    QGraphicsScene *scene;

};

#endif
