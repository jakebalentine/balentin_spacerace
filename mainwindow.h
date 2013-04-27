#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QFont>
#include <QListView>
#include <QGraphicsPixmapItem>
#include <vector>
#include "asteroid.h"
#include "drone.h"
#include "player.h"

#define WINDOW_MAX_X 350
#define WINDOW_MAX_Y 350

/**
 * A class that creates the interface for the user
 * to interact with.
 */
class MainWindow : public QGraphicsView {
  Q_OBJECT
  

 public:
  /** Constructor */
  explicit MainWindow();
  /** Destructor */
  ~MainWindow();
  /** Displays interface to user */
  void show();
  void destroyAsteroid(Asteroid *thing);
  void destroyDrone(Drone *thing);
  
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
  /** Score button */
  QPushButton *scoreButton;
  /** Timer for animation */
  QTimer *timer;
  /** Vector of asteroids */
  std::vector<Asteroid *> asteroids;
  std::vector<Drone *> drones;
  
  QGraphicsPixmapItem *background;
  
  public slots:
   /** Starts the game */
   void run();
   /** Runs puzzle solver */
   //void cheatRun();
   /** Used for animation */
   //void handleTimer();
   /** Used for animation */
   void handleTimer();


};

#endif
