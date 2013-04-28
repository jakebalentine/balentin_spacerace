#ifndef LEFTMOVE_H
#define LEFTMOVE_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "player.h"

class MainWindow;

/**
  
  */
class LeftMove : public QGraphicsRectItem {

public:
    LeftMove(double nx, double ny, Player *p, QGraphicsScene *s);
    
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Player *player;
    QGraphicsPixmapItem *image;
    QGraphicsScene *scene;

};

#endif
