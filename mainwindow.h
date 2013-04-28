#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLCDNumber>
#include <QTimer>
#include <QTimeLine>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QFont>
#include <QListView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <vector>
#include "laser.h"
#include "asteroid.h"
#include "drone.h"
#include "player.h"
#include "praetorian.h"
#include "deathknight.h"
#include "care.h"
#include "leftMove.h"
#include "rightMove.h"

#define WINDOW_MAX_X 350
#define WINDOW_MAX_Y 350

/**
 * A class that creates the interface for the user
 * to interact with.
 */
class MainWindow : public QWidget {
  Q_OBJECT
  

 public:
  /** Constructor */
  explicit MainWindow();
  /** Destructor */
  ~MainWindow();
  /** Displays interface to user */
  void show();
  /** Fire laser */
  void addLaser(Laser *laser);
  /** Destroys laser after contact */
  void destroyLaser(Laser *laser);
  /** Destroys asteroid */
  void destroyAsteroid(Asteroid *thing);
  /** Destroys drone */
  void destroyDrone(Drone *thing);
  /** Destroy praetorian */
  void destroyPraetorian(Praetorian *thing);
  /** Destroy deathknight */
  void destroyDeathknight(Deathknight *thing);
  /** Destroy care package */
  void destroyPackage(Care *thing);
  /** Restarts application */
  void gameOver();
  
 private:
  /** Inherited widget */
  QWidget *widget1;
  /** Area to display tiles */
  QGraphicsScene *scene;
  /** View of scene */
  QGraphicsView *view;
  /** Veritcal layout */
  QVBoxLayout *vLay;
  /** One of the horizontal layouts */
  QHBoxLayout *h1;
  /** One of the horizontal layouts */
  QHBoxLayout *h2;
  /** Start button */
  QPushButton *startButton;
  /** Quit button */
  QPushButton *quitButton;
  /** Pause button */
  QPushButton *pauseButton;
  /** Score display */
  QLCDNumber *scoreDisplay;
  /** Life display */
  QLCDNumber *lifeDisplay;
  /** Timer for animation */
  QTimer *timer;
  /** Player object */
  Player *player;
  /** Vector of asteroids */
  std::vector<Asteroid *> asteroids;
  /** Vector of drones */
  std::vector<Drone *> drones;
  /** Vector of praetorians */
  std::vector<Praetorian *> praetorians;
  /** Vector of deathknights */
  std::vector<Deathknight *> death;
  /** Vector of lasers */
  std::vector<Laser *> lasers;
  /** Vector of packages */
  std::vector<Care *> packages;
  /** integers to keep track of timer and speed */
  int timerCheck, difficulty, restartCode;
  
  /** Background image */
  QGraphicsPixmapItem *background;
  
  public slots:
   /** Starts the game or restarts if already started */
   void run();
   /** Pauses the game */
   void pause();
   /** Used for animation */
   void handleTimer();


};

#endif
