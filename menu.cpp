#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(parent->rect());
    image = new QPixmap(":/images/menuBackground2.png");

    infoButton = new RoundedButton(this);
    infoButton->setGeometry(1650, 420, 180, 180);
    infoButton->setImage(new QPixmap(":/images/infoButton.png"));
    connect(infoButton, SIGNAL(clicked()), parent, SLOT(goRandomLevels()));

    exitButton = new RoundedButton(this);
    exitButton->setGeometry(90, 420, 180, 180);
    exitButton->setImage(new QPixmap(":/images/exitButton.png"));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exit()));

    levelsButton = new RoundedButton(this);
    levelsButton->setGeometry(820, 489, 280, 391);
    levelsButton->setImage(new QPixmap(":/images/menuLevels.png"));
    connect(levelsButton, SIGNAL(clicked()), parent, SLOT(goLevels()));
}

void Menu::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

void Menu::exit(){
    QApplication::quit();
}

Menu::~Menu(){

}
