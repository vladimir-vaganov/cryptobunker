#include "game.h"

Game::Game(QWidget *parent)
{
    this->setGeometry(parent->rect());

    tabs = new QStackedWidget(this);
    tabs->setGeometry(this->rect());

    menu = new Menu(this);
    levels = new Levels(this);
    randomLevels = new RandomLevels(this);
    kpk = new Kpk(this);
    spravochnik = new Spravochnik(this);

    for (int i = 0; i < 100; i++)
        if (i < 100){
            QString tmp = ":/images/levelBackground";
            tmp += QString::number(i + 1);
            tmp += ".png";
            levelWidgets.push_back(new LevelTemplate(this, new QPixmap(tmp), i));
        }
        else
            levelWidgets.push_back(new LevelTemplate(this, new QPixmap(":/images/levelBackground.png"), 0));

    for (int i = 0; i < 20; i++) {
        QString tmp = ":/images/randomLevelBackground";
        tmp += QString::number(i + 1);
        tmp += ".png";
        randomLevelWidgets.push_back(new RandomLevelTemplate(this, new QPixmap(tmp), i + 101));
    }

    tabs->addWidget(menu);
    tabs->addWidget(levels);
    for (int i = 0; i < 100; i++)
        tabs->addWidget(levelWidgets[i]);
    tabs->addWidget(randomLevels);
    for (int i = 0; i < 20; i++)
        tabs->addWidget(randomLevelWidgets[i]);
    tabs->addWidget(kpk);
    tabs->addWidget(spravochnik);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerAction()));
    timer->start(20);

    tabs->show();
    tabs->setCurrentIndex(0);
}

void Game::exit(){
    QApplication::quit();
}

void Game::goMenu(){
    tabs->setCurrentWidget(menu);
    this->previous = this->tabs->currentIndex();
}

void Game::goLevels(){
    tabs->setCurrentWidget(levels);
    this->previous = this->tabs->currentIndex();
}

void Game::goRandomLevels(){
    tabs->setCurrentWidget(randomLevels);
    this->previous = this->tabs->currentIndex();
}

void Game::goLevel(int index){
    tabs->setCurrentIndex(index + 2);
    this->previous = this->tabs->currentIndex();
}

void Game::goKpk(){
    this->previous = this->tabs->currentIndex();
    tabs->setCurrentWidget(kpk);
}

void Game::goSpravochnik(){
    this->previous = this->tabs->currentIndex();
    tabs->setCurrentWidget(spravochnik);
}

void Game::goBack(){
    tabs->setCurrentIndex(this->previous);
    this->previous = this->tabs->currentIndex();
}

void Game::timerAction(){
    for (int i = 0; i < 100; i++)
        if (levelWidgets[i]->getCompleted())
            levels->setPassed(i);
}

int Game::getLevel() {
    return this->tabs->currentIndex();
}

Game::~Game(){

}
