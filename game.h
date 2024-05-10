#ifndef GAME_H
#define GAME_H

#include <roundedbutton.h>
#include <menu.h>
#include <levels.h>
#include <leveltemplate.h>
#include <randomlevels.h>
#include <randomleveltemplate.h>
#include <kpk.h>
#include <spravochnik.h>

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);
    ~Game();
    int getLevel();
    int previous = -1;

public slots:
    void exit();
    void goMenu();
    void goLevels();
    void goRandomLevels();
    void goLevel(int index);
    void timerAction();
    void goKpk();
    void goBack();
    void goSpravochnik();

private:
    QStackedWidget *tabs;
    Menu *menu;
    Levels *levels;
    RandomLevels *randomLevels;
    vector <LevelTemplate*> levelWidgets;
    vector <RandomLevelTemplate*> randomLevelWidgets;
    Kpk *kpk;
    Spravochnik *spravochnik;
    QTimer *timer;
};

#endif // GAME_H
