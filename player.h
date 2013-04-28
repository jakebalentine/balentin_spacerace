#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "laser.h"

class MainWindow;

/**
  
  */
class Player : public QGraphicsRectItem {

public:
    Player(double nx, double ny, MainWindow *mw, QGraphicsScene *s);
    ~Player();
    void setX( int x );
    void setY( int y );
    void setVelocityX( int vx );
    void setVelocityY( int vy );
    void increaseMultiplier();
    void increasePoints(int points);
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void move(int windowMaxX, int windowMaxY );
    void fire();
    MainWindow *window;
    QGraphicsScene *scene;

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int x;
    int y;
    int width;
    int height;
    int velocityX;
    int velocityY;
    int life;
    int multiplier;
    int score;
    QGraphicsPixmapItem *image;
};

#endif 
