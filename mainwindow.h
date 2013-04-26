#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QFont>
#include <QListView>

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
  
  public slots:
   /** Creates interative board */
   //void run();
   /** Runs puzzle solver */
   //void cheatRun();
   /** Used for animation */
   //void handleTimer();


};

#endif
