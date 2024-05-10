#include <spravochnik.h>
#include <roundedbutton.h>

Spravochnik::Spravochnik(QWidget *parent) {
    this->setGeometry(parent->rect());
    image = new QPixmap(":/images/kpkBackground.png");

    backButton = new RoundedButton(this);
    backButton->setGeometry(30, 30, 60, 60);
    backButton->setImage(new QPixmap(":/images/levelBackButton.png"));
    connect(backButton, &RoundedButton::clicked, backButton, [=]{
        switchBack();
    });

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);
    monospace.setPixelSize(24);

    for (int i = 1; i < 32; i++) {
        QString path = ":/images/info";
        path += QString::number(i);
        pictures.push_back(new QPixmap(path));
    }

    buttonLeft = new RoundedButton(this);
    buttonLeft->setImage(new QPixmap(":/images/kpkButtonLeft.png"));
    buttonLeft->setGeometry(200, 480, 175, 120);
    connect(buttonLeft, &RoundedButton::clicked, buttonLeft, [=]{
        if (counter != 0)
            counter--;
        repaint();
    });


    buttonRight = new RoundedButton(this);
    buttonRight->setImage(new QPixmap(":/images/kpkButtonRight.png"));
    buttonRight->setGeometry(1545, 480, 175, 120);
    connect(buttonRight, &RoundedButton::clicked, buttonRight, [=]{
        if (counter != 30)
            counter++;
        repaint();
    });
}

Spravochnik::~Spravochnik() {

}

void Spravochnik::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 4));
    painter.fillRect(0, 0, 1920, 1080, Qt::white);
    painter.drawPixmap(QRect(578, 0, 764, 1080), *pictures[counter]);
}
