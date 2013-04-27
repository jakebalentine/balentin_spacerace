#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class MainWindow;

/**
  
  */
class Asteroid : public QGraphicsRectItem {
public:
    Asteroid(double nx, double ny, MainWindow *mw, QGraphicsScene *scene);
    ~Asteroid();
    void setX( int x );
    void setY( int y );
    void setVelocityX( int vx );
    void setVelocityY( int vy );
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void move(int windowMaxX, int windowMaxY );
    MainWindow *window;
    QGraphicsScene *scene;

private:
    int x;
    int y;
    int width;
    int height;
    int velocityX;
    int velocityY;
    int life;
    QGraphicsPixmapItem *image;
};

#endif
