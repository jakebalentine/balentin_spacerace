#ifndef LASER_H
#define LASER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class MainWindow;

/**
  
  */
class Laser : public QGraphicsRectItem {

public:
    Laser(double nx, double ny, MainWindow *mw);
    ~Laser();
    void setX( int x );
    void setY( int y );
    void setVelocityX( int vx );
    void setVelocityY( int vy );
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void move(int windowMaxX, int windowMaxY );
    
private:
    int x;
    int y;
    int width;
    int height;
    int velocityX;
    int velocityY;
    MainWindow *window;

};

#endif
