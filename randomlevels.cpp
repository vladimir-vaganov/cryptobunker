#include "randomlevels.h"

int numAble2 = 20;

RandomLevels::RandomLevels(QWidget *parent, Game *game)
    : QWidget{parent}
{
    Q_UNUSED(game);

    this->setGeometry(parent->rect());
    image = new QPixmap(":/images/levelsBg.png");
    imageAble = new QPixmap(":/images/randomLevelsButton.png");
    imagePassed = new QPixmap(":/images/randomLevelsButton.png");
    imageBlocked = new QPixmap(":/images/randomLevelsButton.png");

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);
    monospace.setPixelSize(36);

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 10; j++){
            buttons.push_back(new RoundedButton(this));
            buttons[i * 10 + j]->setImage(imageBlocked);
            buttons[i * 10 + j]->setGeometry(240 + i * 780,
                                             60 + j * 90,
                                             660, 60
                                             );
            buttons[i * 10 + j]->setText(QString::number(i * 10 + j + 1));

            buttonLabels.push_back(new QLabel(buttons[i * 10 + j]));
            buttonLabels[i * 10 + j]->setGeometry(buttons[i * 10 + j]->rect());
            buttonLabels[i * 10 + j]->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            buttonLabels[i * 10 + j]->setFont(monospace);
            buttonLabels[i * 10 + j]->setStyleSheet("color: #464646");
        }

    buttonLabels[0]->setText("Шифр Цезаря");
    buttonLabels[1]->setText("Шифр Виженера");
    buttonLabels[2]->setText("Шифр Плейфера");
    buttonLabels[3]->setText("Два квадрата");
    buttonLabels[4]->setText("Решётка Кардано");
    buttonLabels[5]->setText("Атбаш");
    buttonLabels[6]->setText("Квадрат Полибия");
    buttonLabels[7]->setText("Шифр Тритемия");
    buttonLabels[8]->setText("Магический квадрат");
    buttonLabels[9]->setText("Линейка Энея");
    buttonLabels[10]->setText("Шифр Джефферсона");
    buttonLabels[11]->setText("Геометрический шифр");
    buttonLabels[12]->setText("Шифр Бэкона");
    buttonLabels[13]->setText("Диск Альберти");
    buttonLabels[14]->setText("Шифр Rail Fence");
    buttonLabels[15]->setText("Сцитала");
    buttonLabels[16]->setText("Шифр Гронсфельда");
    buttonLabels[17]->setText("Столб. шифр транспонирования");
    buttonLabels[18]->setText("Простая литорея");
    buttonLabels[19]->setText("Немецкий шифр ADFGVX");

    for (int i = 0; i < numAble2; i++)
        connect(buttons[i], &RoundedButton::clicked, buttons[i], [=]{switchLevel(i + 101);});

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

void RandomLevels::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(this->rect(), *this->image);
}

void RandomLevels::setPassed(int index){
    buttons[index]->setImage(imagePassed);
    if (index < 99){
        buttons[index + 1]->setImage(imageAble);
        connect(buttons[index + 1], &RoundedButton::clicked, buttons[index + 1], [=]{
            switchLevel(index + 1);
        });
    }
}

RandomLevels::~RandomLevels(){

}
