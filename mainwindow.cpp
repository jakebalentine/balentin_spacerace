#include <QApplication>
#include <QString>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "mainwindow.h"

void MainWindow::handleTimer() {
  for(int x= 0; x<asteroids.size(); x++){
    asteroids[x]->move( WINDOW_MAX_X, WINDOW_MAX_Y );
  }
  for(int y= 0; y<drones.size(); y++){
    drones[y]->move( 600, 600 );
  }
  for(int y= 0; y<praetorians.size(); y++){
    praetorians[y]->move( 600, 600 );
  }
}

void MainWindow::destroyAsteroid(Asteroid *thing){
  scene->removeItem(thing);
}
void MainWindow::destroyDrone(Drone *thing){
  
  scene->removeItem(thing);
}

void MainWindow::run(){
  Praetorian *thing2;
  Asteroid *thing3;
  
  player= new Player(270, 520, this, scene);
  scene->addItem(player);
  
  thing3= new Asteroid(270, 80, this, scene);
  scene->addItem(thing3);
  asteroids.push_back(thing3);
  
  thing2= new Praetorian(50, 70, this, scene, player);
  scene->addItem(thing2);
  praetorians.push_back(thing2);
}

MainWindow::MainWindow(){  

  scene= new QGraphicsScene(this);
  view= new QGraphicsView();
  view->setScene(scene);
  view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
  view->setWindowTitle( "Space Race");
  //scene->setSceneRect(-350, -350, 350, 350);
  QGraphicsRectItem *rectObj= new QGraphicsRectItem(0, 0, 600, 600);
  scene->addItem(rectObj);
  
  view->setBackgroundBrush(QPixmap("images/background.png"));
  
  timer= new QTimer;
    
  timer = new QTimer(this);  
  timer->setInterval(20);
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  
  srand(time(NULL));
  
  widget1= new QWidget;
  vLay = new QVBoxLayout(widget1);
  h1= new QHBoxLayout;
  
  startButton= new QPushButton("Start");
  startButton->setFont(QFont("Times", 18, QFont::Bold));
  connect(startButton, SIGNAL(clicked()), this, SLOT(run()));
  h1->addWidget(startButton);
  
  scoreButton= new QPushButton("Scores");
  scoreButton->setFont(QFont("Times", 18, QFont::Bold));
  //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
  h1->addWidget(scoreButton);
  
  quitButton= new QPushButton("Quit");
  quitButton->setFont(QFont("Times", 18, QFont::Bold));
  connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
  h1->addWidget(quitButton);
  
  vLay->addLayout(h1);
  
  h2= new QHBoxLayout;
  h2->addWidget(view);
  vLay->addLayout(h2);

}

MainWindow::~MainWindow(){
  delete scene;
  delete view;
  delete startButton;
  delete scoreButton;
  delete quitButton;
  delete h1;
  delete h2;
  delete vLay;
  delete widget1;
}

void MainWindow::show(){
  widget1->show();
  timer->start();
}
