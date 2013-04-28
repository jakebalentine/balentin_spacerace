#ifndef LEFTMOVE_H
#define LEFTMOVE_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "player.h"

class MainWindow;

/**
 * Clickable vortex that moves the user to the left
 */
class LeftMove : public QGraphicsRectItem {

public:
    /** Constructor */
    LeftMove(double nx, double ny, Player *p, QGraphicsScene *s);
    
protected:
  /** Event triggered when object is clicked */
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    /** Pointer to player object */
    Player *player;
    /** Pointer to object image */
    QGraphicsPixmapItem *image;
    /** Pointer to parent scene */
    QGraphicsScene *scene;

};

#endif
