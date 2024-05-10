#include "levels.h"

int numAble = 100;

Levels::Levels(QWidget *parent, Game *game)
    : QWidget{parent}
{
    Q_UNUSED(game);

    this->setGeometry(parent->rect());
    image = new QPixmap(":/images/levelsBg.png");
    imageAble = new QPixmap(":/images/levelsButtonAble.png");
    imagePassed = new QPixmap(":/images/levelsButtonPassed.png");
    imageBlocked = new QPixmap(":/images/levelsButtonBlocked.png");

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);
    monospace.setPixelSize(36);

    for (size_t i = 0; i < 10; i++)
        for (size_t j = 0; j < 10; j++){
            buttons.push_back(new RoundedButton(this));
            buttons[i * 10 + j]->setImage(imageBlocked);
            buttons[i * 10 + j]->setGeometry(240 + j * 150,
                                            60 + i * 90,
                                            90, 60
                                            );
            buttons[i * 10 + j]->setText(QString::number(i * 10 + j + 1));

            buttonLabels.push_back(new QLabel(buttons[i * 10 + j]));
            buttonLabels[i * 10 + j]->setGeometry(buttons[i * 10 + j]->rect());
            buttonLabels[i * 10 + j]->setText(QString::number(i * 10 + j + 1));
            buttonLabels[i * 10 + j]->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            buttonLabels[i * 10 + j]->setFont(monospace);
            buttonLabels[i * 10 + j]->setStyleSheet("color: #464646");
        }

    buttons[0]->setImage(imageAble);
    connect(buttons[0], &RoundedButton::clicked, buttons[0], [=]{
                        switchLevel(0);
                    });

    for (int i = 1; i < numAble; i++)
        connect(buttons[i], &RoundedButton::clicked, buttons[i], [=]{switchLevel(i);});

    backButton = new RoundedButton(this);
    backButton->setGeometry(810,
                          960,
                          300, 50
                          );;
    backButton->setImage(new QPixmap(":/images/levelsBack.png"));
    connect(backButton, SIGNAL(clicked()), parent, SLOT(goMenu()));

    backLabel = new QLabel(backButton);
    backLabel->setText("Back");
    backLabel->setGeometry(backButton->rect());
    backLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    backLabel->setFont(monospace);
    backLabel->setStyleSheet("color: #464646");

}

void Levels::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(this->rect(), *this->image);
}

void Levels::setPassed(int index){
    buttons[index]->setImage(imagePassed);
    if (index < 99){
        buttons[index + 1]->setImage(imageAble);
        connect(buttons[index + 1], &RoundedButton::clicked, buttons[index + 1], [=]{
                            switchLevel(index + 1);
                        });
    }
}

Levels::~Levels(){

}
