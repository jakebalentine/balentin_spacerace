#ifndef RIGHTMOVE_H
#define RIGHTMOVE_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "player.h"

class MainWindow;

/**
 * Clickable vortex that moves the user to the right
 */
class RightMove : public QGraphicsRectItem {

public:
    /** Constructor */
    RightMove(double nx, double ny, Player *p, QGraphicsScene *s);
    
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
