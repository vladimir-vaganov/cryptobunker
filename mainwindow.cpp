#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 1920, 1080);
    this->showFullScreen();
    game = new Game(this);

    this->setCentralWidget(game);
    game->show();
}

MainWindow::~MainWindow()
{
    delete game;
}

