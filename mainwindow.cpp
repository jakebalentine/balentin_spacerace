#include <QApplication>
#include <QString>
#include <cstdlib>
#include <cstdio>
#include "mainwindow.h"

MainWindow::MainWindow(){  

  scene= new QGraphicsScene();
  view= new QGraphicsView(scene);
  view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
  view->setWindowTitle( "Space Race");
  
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
}
