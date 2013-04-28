#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "laser.h"

class MainWindow;

/**
 * Player class that is controlled by the user's
 * mouse clicks. Keeps track of score and lives
 * of the user.
 */
class Player : public QGraphicsRectItem {

public:
    /** Constructor */
    Player(double nx, double ny, MainWindow *mw, QGraphicsScene *s);
    /** Destructor */
    ~Player();
    /** Change X */
    void setX( int x );
    /** Change Y */
    void setY( int y );
    /** Change velocityX */
    void setVelocityX( int vx );
    /** Change velocityY */
    void setVelocityY( int vy );
    /** Increase score multiplier */
    void increaseMultiplier();
    /** Add points to score */
    void increasePoints(int points);
    /** Take away one life */
    void decreaseLife();
    /** Accessor for score */
    int getScore();
    /** Accessor for lives */
    int getLife();
    /** Accessor for X */
    int getX();
    /** Accessor for Y */ 
    int getY();
    /** Accessor for velocityX */
    int getVelocityX();
    /** Accessor for velocityY */
    int getVelocityY();
    /** Move the object */
    void move();
    /** Fire laser */
    void fire();

protected:
  /** Triggered when user clicks object */
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    /** Coordinate X */
    int x;
    /** Coordinate Y */
    int y;
    /** Rect width */
    int width;
    /** Rect height */
    int height;
    /** Object's horizontal speed */
    int velocityX;
    /** Object's vertical speed */
    int velocityY;
    /** Amount of lives */
    int life;
    /** Current multiplier */
    int multiplier;
    /** User's score */
    int score;
    /** Object's image */
    QGraphicsPixmapItem *image;
    /** Pointer to parent window */
    MainWindow *window;
    /** Pointer to parent scene */
    QGraphicsScene *scene;
};

#endif 
