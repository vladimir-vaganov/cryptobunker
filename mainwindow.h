#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <game.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Game *game;
};

#endif // MAINWINDOW_H
