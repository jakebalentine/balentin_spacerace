#include <QApplication>
#include <QString>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "mainwindow.h"

using namespace std;

void MainWindow::handleTimer() {
  
  scoreDisplay->display(player->getScore());
  lifeDisplay->display(player->getLife());
  
  if(timerCheck<200){
  timerCheck++;
  }
  
  player->move();
  
  for(unsigned int b= 0; b<lasers.size(); b++){
    lasers[b]->move(600, 600);
  }
  for(unsigned int x= 0; x<asteroids.size(); x++){
    asteroids[x]->move( WINDOW_MAX_X, WINDOW_MAX_Y );
    if(player->rect().intersects(asteroids[x]->rect())){
      player->decreaseLife();
       destroyAsteroid(asteroids[x]);
    }
    for(unsigned int u= 0; u<lasers.size(); u++){
      if(lasers[u]->rect().intersects(asteroids[x]->rect())){
       destroyLaser(lasers[u]);
       if(asteroids[x]->hit()){  
         destroyAsteroid(asteroids[x]);
       }
     }
    }
  }
  for(unsigned int y= 0; y<drones.size(); y++){
    drones[y]->move( 600, 600 );
    if(player->rect().intersects(drones[y]->rect())){
      player->decreaseLife();
      destroyDrone(drones[y]);
    }
    for(unsigned int u= 0; u<lasers.size(); u++){
      if(lasers[u]->rect().intersects(drones[y]->rect())){
       destroyLaser(lasers[u]);
       if(drones[y]->hit()){
         destroyDrone(drones[y]);
       }
     }
    }
  }
  for(unsigned int z= 0; z<praetorians.size(); z++){
    praetorians[z]->move( 600, 600 );
    if(player->rect().intersects(praetorians[z]->rect())){
      player->decreaseLife();
      destroyPraetorian(praetorians[z]);
    }
    for(unsigned int u= 0; u<lasers.size(); u++){
      if(lasers[u]->rect().intersects(praetorians[z]->rect())){
       destroyLaser(lasers[u]);
       if(praetorians[z]->hit()){
         destroyPraetorian(praetorians[z]);
       }
     }
    }
  }
  for(unsigned int a= 0; a<death.size(); a++){
    death[a]->move( 600, 600 );
    for(unsigned int u= 0; u<lasers.size(); u++){
      if(lasers[u]->rect().intersects(death[a]->rect())){
       destroyLaser(lasers[u]);
       if(death[a]->hit()){
         destroyDeathknight(death[a]);
       }
     }
    }
  }
  for(unsigned int c= 0; c<packages.size(); c++){
    packages[c]->move(600, 600);
    if(packages[c]->rect().intersects(player->rect())){
      destroyPackage(packages[c]);
      player->increaseMultiplier();
    }
  }
  
  
  if(timerCheck==140){
    for(unsigned int a= 0; a<death.size(); a++){
      Praetorian *thing;
      thing= new Praetorian(death[a]->getX(), death[a]->getY(), this, scene, player);
      scene->addItem(thing);
      praetorians.push_back(thing);
    }
  }
  if(timerCheck==200){
    int randCheck= rand() % 100+1;
    if(randCheck>=1 && randCheck<=5){
      Deathknight *thing1= new Deathknight(250, 200, this, scene);
      scene->addItem(thing1);
      death.push_back(thing1);
    }
    if(randCheck>=6 && randCheck<=15){
      Care *thing2= new Care((rand() % 300+100), 100, this, scene);
      scene->addItem(thing2);
      packages.push_back(thing2);
    }
    if(randCheck>=16 && randCheck<=40){
      Praetorian *thing3= new Praetorian((rand() % 300+100), 100, this, scene, player);
      scene->addItem(thing3);
      praetorians.push_back(thing3);
    }
    if(randCheck>=41 && randCheck<=85){
      Drone *thing4= new Drone((rand() % 300+100), 100, this, scene);
      scene->addItem(thing4);
      drones.push_back(thing4);
    }
    if(randCheck>=86 && randCheck<=100){
      Asteroid *thing5= new Asteroid((rand() % 300+100), 100, this, scene);
      scene->addItem(thing5);
      asteroids.push_back(thing5);
    }
    timerCheck= timerCheck-difficulty;
    difficulty= difficulty-5;
  }
}

void MainWindow::addLaser(Laser *laser){
  scene->addItem(laser);
  lasers.push_back(laser);
}

void MainWindow::destroyLaser(Laser *laser){
  scene->removeItem(laser);
  for(unsigned int x= 0; x<lasers.size(); x++){
    if(laser==lasers[x]){
      lasers.erase(lasers.begin()+x);
    }
  }
}

void MainWindow::destroyAsteroid(Asteroid *thing){
  scene->removeItem(thing);
  for(unsigned int x= 0; x<asteroids.size(); x++){
    if(thing==asteroids[x]){
      asteroids.erase(asteroids.begin()+x);
      player->increasePoints(10);
    }
  }
}
void MainWindow::destroyDrone(Drone *thing){
  scene->removeItem(thing);
  for(unsigned int x= 0; x<drones.size(); x++){
    if(thing==drones[x]){
      drones.erase(drones.begin()+x);
      player->increasePoints(25);
    }
  }
}

void MainWindow::destroyPraetorian(Praetorian *thing){
  scene->removeItem(thing);
  for(unsigned int x= 0; x<praetorians.size(); x++){
    if(thing==praetorians[x]){
      praetorians.erase(praetorians.begin()+x);
      player->increasePoints(75);
    }
  }
}
void MainWindow::destroyDeathknight(Deathknight *thing){
  scene->removeItem(thing);
  for(unsigned int x= 0; x<death.size(); x++){
    if(thing==death[x]){
      death.erase(death.begin()+x);
      player->increasePoints(300);
    }
  }
}

void MainWindow::destroyPackage(Care *thing){
  scene->removeItem(thing);
  for(unsigned int x= 0; x<packages.size(); x++){
    if(thing==packages[x]){
      packages.erase(packages.begin()+x);
    }
  }
}


void MainWindow::pause(){
  if(timer->isActive()){
    timer->stop();
  }
  else{
    timer->start();
  }
}

void MainWindow::run(){
  if(timer->isActive()){
      gameOver();
    }
    else{
      timer->start();
    }
}

void MainWindow::gameOver(){
  qApp->exit( restartCode );
}

MainWindow::MainWindow(){  

  timerCheck= 0;
  difficulty= 200;
  restartCode= -333;
  
  scene= new QGraphicsScene(this);
  view= new QGraphicsView();
  view->setScene(scene);
  view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
  view->setWindowTitle( "Space Race");
  //scene->setSceneRect(-350, -350, 350, 350);
  QGraphicsRectItem *rectObj= new QGraphicsRectItem(0, 0, 600, 600);
  scene->addItem(rectObj);
  player= new Player(270, 520, this, scene);
  LeftMove *left= new LeftMove(0, 520, player, scene);
  RightMove *right= new RightMove(560, 520, player, scene);
  scene->addItem(player);
  scene->addItem(left);
  scene->addItem(right);
  
  this->setFocusPolicy(Qt::StrongFocus);
  
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
  
  pauseButton= new QPushButton("Pause");
  pauseButton->setFont(QFont("Times", 18, QFont::Bold));
  connect(pauseButton, SIGNAL(clicked()), this, SLOT(pause()));
  h1->addWidget(pauseButton);
  
  scoreDisplay= new QLCDNumber(7);
  scoreDisplay->display(player->getScore());
  h1->addWidget(scoreDisplay);
  
  lifeDisplay= new QLCDNumber(2);
  lifeDisplay->display(player->getLife());
  h1->addWidget(lifeDisplay);
  
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
  delete quitButton;
  delete h1;
  delete h2;
  delete vLay;
  delete widget1;
}

void MainWindow::show(){
  widget1->show();
}
