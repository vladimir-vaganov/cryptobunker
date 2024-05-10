#include "kpk.h"

Kpk::Kpk(QWidget *parent)
    : QWidget{parent}
{
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

    for (size_t i = 0; i < 20; i++) {
        buttonLabels.push_back(new QLabel(this));
        buttonLabels.back()->setGeometry(91, 90 + i * 45, 447, 43);
        buttonLabels.back()->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        buttonLabels.back()->setFont(monospace);
        buttonLabels.back()->setStyleSheet("color: #464646");

        buttons.push_back(new RoundedButton(this));
        buttons.back()->setGeometry(91, 90 + i * 45, 447, 43);
        buttons.back()->setImage(new QPixmap(":/images/kpkButton.png"));
    }

    buttonLabels[0]->setText("  Шифр Цезаря");
    buttonLabels[1]->setText("  Шифр Виженера");
    buttonLabels[2]->setText("  Шифр Плейфера");
    buttonLabels[3]->setText("  Два квадрата");
    buttonLabels[4]->setText("  Решётка Кардано");
    buttonLabels[5]->setText("  Атбаш");
    buttonLabels[6]->setText("  Квадрат Полибия");
    buttonLabels[7]->setText("  Шифр Тритемия");
    buttonLabels[8]->setText("  Магический квадрат");
    buttonLabels[9]->setText("  Линейка Энея");
    buttonLabels[10]->setText("  Шифр Джефферсона");
    buttonLabels[11]->setText("  Геометрический шифр");
    buttonLabels[12]->setText("  Шифр Бэкона");
    buttonLabels[13]->setText("  Диск Альберти");
    buttonLabels[14]->setText("  Шифр Rail Fence");
    buttonLabels[15]->setText("  Сцитала");
    buttonLabels[16]->setText("  Шифр Гронсфельда");
    buttonLabels[17]->setText("  Столб. шифр транспонирования");
    buttonLabels[18]->setText("  Простая литорея");
    buttonLabels[19]->setText("  Немецкий шифр ADFGVX");

    tabs = new QStackedWidget(this);
    tabs->setGeometry(570, 120, 1230, 840);

    kpkCaesar = new KpkCaesar(tabs);
    kpkCaesar->setGeometry(parent->rect());

    kpkVigener = new KpkVigener(tabs);
    kpkVigener->setGeometry(parent->rect());

    kpkPLeyfer = new KpkPLeyfer(tabs);
    kpkPLeyfer->setGeometry(parent->rect());

    kpkDvakvadrata = new KpkDvakvadrata(tabs);
    kpkDvakvadrata->setGeometry(parent->rect());

    kpkKardano = new KpkKardano(tabs);
    kpkKardano->setGeometry(parent->rect());

    kpkAtbash = new KpkAtbash(tabs);
    kpkAtbash->setGeometry(parent->rect());

    kpkKvadratpolibiya = new KpkKvadratpolibiya(tabs);
    kpkKvadratpolibiya->setGeometry(parent->rect());

    kpkTritemiy = new KpkTritemiy(tabs);
    kpkTritemiy->setGeometry(parent->rect());

    kpkMagickvadrat = new KpkMagickvadrat(tabs);
    kpkMagickvadrat->setGeometry(parent->rect());

    kpkLineyka = new KpkLineyka(tabs);
    kpkLineyka->setGeometry(parent->rect());

    kpkJefferson = new KpkJefferson(tabs);
    kpkJefferson->setGeometry(parent->rect());

    kpkGeometric = new KpkGeometric(tabs);
    kpkGeometric->setGeometry(parent->rect());

    kpkBacon = new KpkBacon(tabs);
    kpkBacon->setGeometry(parent->rect());

    kpkAlberti = new KpkAlberti(tabs);
    kpkAlberti->setGeometry(parent->rect());

    kpkRailfence = new KpkRailfence(tabs);
    kpkRailfence->setGeometry(parent->rect());

    kpkScitala = new KpkScitala(tabs);
    kpkScitala->setGeometry(parent->rect());

    kpkGronsfeld = new KpkGronsfeld(tabs);
    kpkGronsfeld->setGeometry(parent->rect());

    kpkTranspon = new KpkTranspon(tabs);
    kpkTranspon->setGeometry(parent->rect());

    kpkLitoreya = new KpkLitoreya(tabs);
    kpkLitoreya->setGeometry(parent->rect());

    kpkAdfgvx = new KpkAdfgvx(tabs);
    kpkAdfgvx->setGeometry(parent->rect());

    tabs->addWidget(kpkCaesar);             // Done
    tabs->addWidget(kpkVigener);            // Done
    tabs->addWidget(kpkPLeyfer);            // Done
    tabs->addWidget(kpkDvakvadrata);        // Done
    tabs->addWidget(kpkKardano);            // Done
    tabs->addWidget(kpkAtbash);             // Done
    tabs->addWidget(kpkKvadratpolibiya);    // Done
    tabs->addWidget(kpkTritemiy);           // Done
    tabs->addWidget(kpkMagickvadrat);       //
    tabs->addWidget(kpkLineyka);            // Done
    tabs->addWidget(kpkJefferson);          // Done
    tabs->addWidget(kpkGeometric);          // Done
    tabs->addWidget(kpkBacon);              // Done
    tabs->addWidget(kpkAlberti);            // Done
    tabs->addWidget(kpkRailfence);          // Done
    tabs->addWidget(kpkScitala);            // Done
    tabs->addWidget(kpkGronsfeld);          // Done
    tabs->addWidget(kpkTranspon);           // Done
    tabs->addWidget(kpkLitoreya);           // Done
    tabs->addWidget(kpkAdfgvx);             // Done

    for (size_t i = 0; i < 20; i++) {
        connect(buttons[i], &RoundedButton::clicked, buttons[i], [=]{
            tabs->setCurrentIndex(i);
            for (size_t j = 0; j < 20; j++)
                buttonLabels[j]->setStyleSheet("color: #464646");
            buttonLabels[i]->setStyleSheet("color: #1f1f1f");
        });
    }

    tabs->setCurrentWidget(kpkCaesar);
    buttonLabels[0]->setStyleSheet("color: #1f1f1f");
}

void Kpk::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

Kpk::~Kpk(){

}

//----------------------------------------------------------------------------------

KpkCaesar::KpkCaesar(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Алфавит");
    label1->setGeometry(120, 100, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    alphabet = new QLineEdit(this);
    alphabet->setGeometry(120, 200, 990, 60);
    alphabet->setMaxLength(33);
    alphabet->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    alphabet->setFont(terminalFont);
    alphabet->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    alphabet->setReadOnly(true);
    alphabet->setText("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");

    QLabel *label2 = new QLabel(this);
    label2->setText("Результат");
    label2->setGeometry(120, 300, 990, 60);
    label2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label2->setFont(terminalFont);
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    result = new QLineEdit(this);
    result->setGeometry(120, 400, 990, 60);
    result->setMaxLength(33);
    result->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    result->setFont(terminalFont);
    result->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    result->setReadOnly(true);
    result->setText("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");

    counterLabel = new QLineEdit(this);
    counterLabel->setGeometry(525, 550, 180, 120);
    counterLabel->setMaxLength(33);
    counterLabel->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    counterLabel->setFont(terminalFont);
    counterLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    counterLabel->setReadOnly(true);
    counterLabel->setText("0");

    buttonLeft = new RoundedButton(this);
    buttonLeft->setImage(new QPixmap(":/images/kpkButtonLeft.png"));
    buttonLeft->setGeometry(350, 550, 175, 120);
    connect(buttonLeft, &RoundedButton::clicked, buttonLeft, [=]{
        QString tmp = result->text();
        tmp.push_back(tmp[0]);
        tmp = tmp.mid(1);
        result->setText(tmp);

        counter = ((counter - 1) + 33) % 33;
        counterLabel->setText(QString::number(counter));

        repaint();
    });

    buttonRight = new RoundedButton(this);
    buttonRight->setImage(new QPixmap(":/images/kpkButtonRight.png"));
    buttonRight->setGeometry(705, 550, 175, 120);
    connect(buttonRight, &RoundedButton::clicked, buttonRight, [=]{
        QString tmp = result->text();
        tmp.push_front(tmp.back());
        tmp.chop(1);
        result->setText(tmp);

        counter = ((counter + 1) + 33) % 33;
        counterLabel->setText(QString::number(counter));

        repaint();
    });
}

KpkCaesar::~KpkCaesar() {

}

void KpkCaesar::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(alphabet);
    PAINT_GREEN_RED_BORDERS(result);
}

//----------------------------------------------------------------------------------

KpkVigener::KpkVigener(QWidget* parent) {
    Q_UNUSED(parent);

    image = new QPixmap(":/images/kpkTable1.png");
}

KpkVigener::~KpkVigener() {

}

void KpkVigener::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

//----------------------------------------------------------------------------------

KpkPLeyfer::KpkPLeyfer(QWidget* parent) {
    Q_UNUSED(parent);

    letters.clear();

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблица");
    label1->setGeometry(120, 50, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            letters.push_back(new QLineEdit(this));
            letters.back()->setMaxLength(1);
            letters.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters.back()->setFont(terminalFont);
            letters.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters.back()->setGeometry(315 + i * 100, 150 + j * 100, 100, 100);
            connect(letters.back(), &QLineEdit::textChanged, letters.back(), [=]{
                for (size_t i = 0; i < letters.size(); i++)
                    letters[i]->setText(normalize(letters[i]->text()));
            });
        }
}

KpkPLeyfer::~KpkPLeyfer() {

}

void KpkPLeyfer::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 4));

    for (size_t i = 0; i < letters.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters[i]);
    }
}

//----------------------------------------------------------------------------------

KpkDvakvadrata::KpkDvakvadrata(QWidget* parent) {
    Q_UNUSED(parent);

    letters1.clear();
    letters1.clear();

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблицы");
    label1->setGeometry(120, 80, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            letters1.push_back(new QLineEdit(this));
            letters1.back()->setMaxLength(1);
            letters1.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters1.back()->setFont(terminalFont);
            letters1.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters1.back()->setGeometry(100 + i * 75, 250 + j * 75, 75, 75);
            connect(letters1.back(), &QLineEdit::textChanged, letters1.back(), [=]{
                for (size_t i = 0; i < letters1.size(); i++)
                    letters1[i]->setText(normalize(letters1[i]->text()));
            });
        }

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            letters2.push_back(new QLineEdit(this));
            letters2.back()->setMaxLength(1);
            letters2.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters2.back()->setFont(terminalFont);
            letters2.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters2.back()->setGeometry(680 + i * 75, 250 + j * 75, 75, 75);
            connect(letters2.back(), &QLineEdit::textChanged, letters2.back(), [=]{
                for (size_t i = 0; i < letters2.size(); i++)
                    letters2[i]->setText(normalize(letters2[i]->text()));
            });
        }
}

KpkDvakvadrata::~KpkDvakvadrata() {

}

void KpkDvakvadrata::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 4));

    for (size_t i = 0; i < letters1.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters1[i]);
    }

    for (size_t i = 0; i < letters2.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters2[i]);
    }
}

//----------------------------------------------------------------------------------

KpkKardano::KpkKardano(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    button4 = new RoundedButton(this);
    button4->setImage(new QPixmap(":/images/kpkButton4.png"));
    button4->setGeometry(235, 100, 120, 75);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            etalon.push_back(new QLineEdit(this));
            etalon.back()->setMaxLength(1);
            etalon.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            etalon.back()->setFont(terminalFont);
            etalon.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            etalon.back()->setGeometry(315 + i * 75, 200 + j * 75, 75, 75);
            connect(etalon.back(), &QLineEdit::textChanged, etalon.back(), [=]{
                for (size_t i = 0; i < etalon.size(); i++)
                    etalon[i]->setText(normalize(etalon[i]->text()));
            });
            etalon.back()->hide();
        }
    }

    connect(button4, &RoundedButton::clicked, this, [=]{
        for (size_t i = 0; i < etalon.size(); i++) {
            etalon[i]->setText("");
            etalon[i]->hide();
        }

        for (int i = 2; i < 6; i++) {
            for (int j = 2; j < 6; j++) {
                etalon[8 * i + j]->show();
            }
        }

        repaint();
    });

    button6 = new RoundedButton(this);
    button6->setImage(new QPixmap(":/images/kpkButton6.png"));
    button6->setGeometry(555, 100, 120, 75);
    connect(button6, &RoundedButton::clicked, button4, [=]{
        for (size_t i = 0; i < etalon.size(); i++) {
            etalon[i]->setText("");
            etalon[i]->hide();
        }

        for (int i = 1; i < 7; i++) {
            for (int j = 1; j < 7; j++) {
                etalon[8 * i + j]->show();
            }
        }

        repaint();
    });

    button8 = new RoundedButton(this);
    button8->setImage(new QPixmap(":/images/kpkButton8.png"));
    button8->setGeometry(875, 100, 120, 75);
    connect(button8, &RoundedButton::clicked, button4, [=]{
        for (size_t i = 0; i < etalon.size(); i++) {
            etalon[i]->setText("");
            etalon[i]->hide();
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                etalon[8 * i + j]->show();
            }
        }

        repaint();
    });
}

KpkKardano::~KpkKardano() {

}

void KpkKardano::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 4));

    for (size_t i = 0; i < etalon.size(); i++) {
        if (!etalon[i]->isHidden()) {
            PAINT_GREEN_RED_BORDERS(etalon[i]);
        }
    }
}

//----------------------------------------------------------------------------------

KpkAtbash::KpkAtbash(QWidget* parent) {
    Q_UNUSED(parent);

    image = new QPixmap(":/images/kpkAtbash.png");
}

KpkAtbash::~KpkAtbash() {

}

void KpkAtbash::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

//----------------------------------------------------------------------------------

KpkKvadratpolibiya::KpkKvadratpolibiya(QWidget* parent) {
    Q_UNUSED(parent);

    letters.clear();

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблица");
    label1->setGeometry(120, 50, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            letters.push_back(new QLineEdit(this));
            letters.back()->setMaxLength(1);
            letters.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters.back()->setFont(terminalFont);
            letters.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters.back()->setGeometry(315 + i * 100, 150 + j * 100, 100, 100);
            connect(letters.back(), &QLineEdit::textChanged, letters.back(), [=]{
                for (size_t i = 0; i < letters.size(); i++)
                    letters[i]->setText(normalize(letters[i]->text()));
            });
        }
}

KpkKvadratpolibiya::~KpkKvadratpolibiya() {

}

void KpkKvadratpolibiya::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 4));

    for (size_t i = 0; i < letters.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters[i]);
    }
}

//----------------------------------------------------------------------------------

KpkTritemiy::KpkTritemiy(QWidget* parent) {
    Q_UNUSED(parent);

    image = new QPixmap(":/images/kpkTable1.png");
}

KpkTritemiy::~KpkTritemiy() {

}

void KpkTritemiy::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

//----------------------------------------------------------------------------------

KpkMagickvadrat::KpkMagickvadrat(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    button4 = new RoundedButton(this);
    button4->setImage(new QPixmap(":/images/kpkButton4.png"));
    button4->setGeometry(235, 100, 120, 75);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            etalon.push_back(new QLineEdit(this));
            etalon.back()->setMaxLength(1);
            etalon.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            etalon.back()->setFont(terminalFont);
            etalon.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            etalon.back()->setGeometry(315 + i * 75, 200 + j * 75, 75, 75);
            connect(etalon.back(), &QLineEdit::textChanged, etalon.back(), [=]{
                for (size_t i = 0; i < etalon.size(); i++)
                    etalon[i]->setText(normalize(etalon[i]->text()));
            });
            etalon.back()->hide();
        }
    }

    connect(button4, &RoundedButton::clicked, this, [=]{
        for (size_t i = 0; i < etalon.size(); i++) {
            etalon[i]->setText("");
            etalon[i]->hide();
        }

        for (int i = 2; i < 6; i++) {
            for (int j = 2; j < 6; j++) {
                etalon[8 * i + j]->show();
            }
        }

        repaint();
    });

    button6 = new RoundedButton(this);
    button6->setImage(new QPixmap(":/images/kpkButton6.png"));
    button6->setGeometry(555, 100, 120, 75);
    connect(button6, &RoundedButton::clicked, button4, [=]{
        for (size_t i = 0; i < etalon.size(); i++) {
            etalon[i]->setText("");
            etalon[i]->hide();
        }

        for (int i = 1; i < 7; i++) {
            for (int j = 1; j < 7; j++) {
                etalon[8 * i + j]->show();
            }
        }

        repaint();
    });

    button8 = new RoundedButton(this);
    button8->setImage(new QPixmap(":/images/kpkButton8.png"));
    button8->setGeometry(875, 100, 120, 75);
    connect(button8, &RoundedButton::clicked, button4, [=]{
        for (size_t i = 0; i < etalon.size(); i++) {
            etalon[i]->setText("");
            etalon[i]->hide();
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                etalon[8 * i + j]->show();
            }
        }

        repaint();
    });
}

KpkMagickvadrat::~KpkMagickvadrat() {

}

void KpkMagickvadrat::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 4));

    for (size_t i = 0; i < etalon.size(); i++) {
        if (!etalon[i]->isHidden()) {
            PAINT_GREEN_RED_BORDERS(etalon[i]);
        }
    }
}

//----------------------------------------------------------------------------------

KpkLineyka::KpkLineyka(QWidget* parent) {
    Q_UNUSED(parent);

    inputString = new QLineEdit(this);
    inputString->setGeometry(120, 220, 990, 60);
    inputString->setMaxLength(33);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);
    inputString->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    inputString->setFont(terminalFont);
    inputString->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    connect(inputString, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *label1 = new QLabel(this);
    label1->setText("Введите алфавит (только символы кириллицы):");
    label1->setGeometry(120, 154, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    letter1 = new QLineEdit(this);
    letter1->setMaxLength(1);
    letter1->setGeometry(120, 400, 60, 60);
    letter1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    letter1->setFont(terminalFont);
    letter1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(letter1, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    letter2 = new QLineEdit(this);
    letter2->setMaxLength(1);
    letter2->setGeometry(120, 500, 60, 60);
    letter2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    letter2->setFont(terminalFont);
    letter2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(letter2, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    result = new QLabel(this);
    result->setGeometry(120, 600, 60, 60);
    result->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    result->setFont(terminalFont);
    result->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    result->setText(" ");

    QLabel* tip1 = new QLabel(this);
    tip1->setGeometry(200, 400, 900, 60);
    tip1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    tip1->setFont(terminalFont);
    tip1->setAlignment(Qt::AlignLeft);
    tip1->setText("Текущая буква");

    QLabel* tip2 = new QLabel(this);
    tip2->setGeometry(200, 500, 900, 60);
    tip2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    tip2->setFont(terminalFont);
    tip2->setAlignment(Qt::AlignLeft);
    tip2->setText("Предыдущая буква");

    QLabel* tip3 = new QLabel(this);
    tip3->setGeometry(200, 600, 900, 60);
    tip3->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    tip3->setFont(terminalFont);
    tip3->setAlignment(Qt::AlignLeft);
    tip3->setText("Длина нитки");
}

KpkLineyka::~KpkLineyka() {

}

void KpkLineyka::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    inputString->setText(normalize(inputString->text()));
    letter1->setText(normalize(letter1->text()));
    letter2->setText(normalize(letter2->text()));

    if (letter1->text().size() != 0 && letter2->text().size() != 0 && inputString->text().size() == 33) {
        QString letter1text = letter1->text();
        QString letter2text = letter2->text();

        int pos1 = inputString->text().indexOf(letter1text[0]);
        int pos2 = inputString->text().indexOf(letter2text[0]);
        int res = pos1 + pos2 + 2;

        result->setText(QString::fromStdString(std::to_string(res)));
    }
    else
        result->setText(" ");

    QPainter painter(this);
    if (inputString->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(inputString);

    if (letter1->text().size() != 1)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(letter1);

    if (letter2->text().size() != 1)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(letter2);

    if (result->text() == QString(" "))
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(result);
}

//----------------------------------------------------------------------------------

KpkJefferson::KpkJefferson(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(26);

    QLabel *disksLabel = new QLabel(this);
    disksLabel->setText("Диски:");
    disksLabel->setGeometry(120, 10, 990, 50);
    disksLabel->setStyleSheet("border: 0px; color : #228b22");
    disksLabel->setFont(terminalFont);
    disksLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    disk1 = new QLineEdit(this);
    disk1->setGeometry(120, 70, 990, 50);
    disk1->setMaxLength(33);
    disk1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk1->setFont(terminalFont);
    disk1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk1->setText(QString(""));
    connect(disk1, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk2 = new QLineEdit(this);
    disk2->setGeometry(120, 130, 990, 50);
    disk2->setMaxLength(33);
    disk2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk2->setFont(terminalFont);
    disk2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk2->setText(QString(""));
    connect(disk2, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk3 = new QLineEdit(this);
    disk3->setGeometry(120, 190, 990, 50);
    disk3->setMaxLength(33);
    disk3->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk3->setFont(terminalFont);
    disk3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk3->setText(QString(""));
    connect(disk3, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk4 = new QLineEdit(this);
    disk4->setGeometry(120, 250, 990, 50);
    disk4->setMaxLength(33);
    disk4->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk4->setFont(terminalFont);
    disk4->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk4->setText(QString(""));
    connect(disk4, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk5 = new QLineEdit(this);
    disk5->setGeometry(120, 310, 990, 50);
    disk5->setMaxLength(33);
    disk5->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk5->setFont(terminalFont);
    disk5->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk5->setText(QString(""));
    connect(disk5, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk6 = new QLineEdit(this);
    disk6->setGeometry(120, 370, 990, 50);
    disk6->setMaxLength(33);
    disk6->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk6->setFont(terminalFont);
    disk6->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk6->setText(QString(""));
    connect(disk6, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk7 = new QLineEdit(this);
    disk7->setGeometry(120, 430, 990, 50);
    disk7->setMaxLength(33);
    disk7->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk7->setFont(terminalFont);
    disk7->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk7->setText(QString(""));
    connect(disk7, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    disk8 = new QLineEdit(this);
    disk8->setGeometry(120, 490, 990, 50);
    disk8->setMaxLength(33);
    disk8->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    disk8->setFont(terminalFont);
    disk8->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    disk8->setText(QString(""));
    connect(disk8, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    key = new QLineEdit(this);
    key->setGeometry(120, 570, 50, 50);
    key->setMaxLength(2);
    key->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    key->setFont(terminalFont);
    key->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    key->setText(QString(""));
    connect(key, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *keyLabel = new QLabel(this);
    keyLabel->setText("Ключ");
    keyLabel->setGeometry(190, 570, 990, 50);
    keyLabel->setStyleSheet("border: 0px; color : #228b22");
    keyLabel->setFont(terminalFont);
    keyLabel->setAlignment(Qt::AlignLeft);

    number = new QLineEdit(this);
    number->setGeometry(120, 630, 50, 50);
    number->setMaxLength(1);
    number->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    number->setFont(terminalFont);
    number->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    number->setText(QString(""));
    connect(number, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *numberLabel = new QLabel(this);
    numberLabel->setText("Номер диска");
    numberLabel->setGeometry(190, 630, 990, 50);
    numberLabel->setStyleSheet("border: 0px; color : #228b22");
    numberLabel->setFont(terminalFont);
    numberLabel->setAlignment(Qt::AlignLeft);

    letter = new QLineEdit(this);
    letter->setGeometry(120, 690, 50, 50);
    letter->setMaxLength(1);
    letter->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    letter->setFont(terminalFont);
    letter->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    letter->setText(QString(""));
    connect(letter, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *letterLabel = new QLabel(this);
    letterLabel->setText("Буква");
    letterLabel->setGeometry(190, 690, 990, 50);
    letterLabel->setStyleSheet("border: 0px; color : #228b22");
    letterLabel->setFont(terminalFont);
    letterLabel->setAlignment(Qt::AlignLeft);

    result = new QLineEdit(this);
    result->setGeometry(120, 750, 50, 50);
    result->setMaxLength(1);
    result->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    result->setFont(terminalFont);
    result->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    result->setText(QString(""));
    result->setReadOnly(true);

    QLabel *resultLabel = new QLabel(this);
    resultLabel->setText("Результат");
    resultLabel->setGeometry(190, 750, 990, 50);
    resultLabel->setStyleSheet("border: 0px; color : #228b22");
    resultLabel->setFont(terminalFont);
    resultLabel->setAlignment(Qt::AlignLeft);
}

KpkJefferson::~KpkJefferson() {

}

void KpkJefferson::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    disk1->setText(normalize(disk1->text()));
    disk2->setText(normalize(disk2->text()));
    disk3->setText(normalize(disk3->text()));
    disk4->setText(normalize(disk4->text()));
    disk5->setText(normalize(disk5->text()));
    disk6->setText(normalize(disk6->text()));
    disk7->setText(normalize(disk7->text()));
    disk8->setText(normalize(disk8->text()));
    key->setText(normalizeNumber(key->text(), 32));
    number->setText(normalizeNumber(number->text(), 8));
    letter->setText(normalize(letter->text()));

    if (disk1->text().size() == 33 &&
        disk2->text().size() == 33 &&
        disk3->text().size() == 33 &&
        disk4->text().size() == 33 &&
        disk5->text().size() == 33 &&
        disk6->text().size() == 33 &&
        disk7->text().size() == 33 &&
        disk8->text().size() == 33 &&
        key->text().size() != 0 &&
        number->text().size() != 0 &&
        letter->text().size() != 0
       )
    {
        QString alphabet = "";
        QString findingLetter = letter->text();

        if (number->text().toInt() == 1) alphabet = disk1->text();
        if (number->text().toInt() == 2) alphabet = disk2->text();
        if (number->text().toInt() == 3) alphabet = disk3->text();
        if (number->text().toInt() == 4) alphabet = disk4->text();
        if (number->text().toInt() == 5) alphabet = disk5->text();
        if (number->text().toInt() == 6) alphabet = disk6->text();
        if (number->text().toInt() == 7) alphabet = disk7->text();
        if (number->text().toInt() == 8) alphabet = disk8->text();

        int pos = alphabet.indexOf(findingLetter[0]);

        alphabet += alphabet;

        pos += key->text().toInt();

        result->setText(alphabet[pos]);
    }
    else
        result->setText("");

    QPainter painter(this);

    if (disk1->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk1);

    if (disk2->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk2);

    if (disk3->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk3);

    if (disk4->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk4);

    if (disk5->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk5);

    if (disk6->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk6);

    if (disk7->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk7);

    if (disk8->text().size() != 33)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(disk8);

    if (key->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(key);

    if (number->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(number);

    if (letter->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(letter);

    if (result->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(result);
}

//----------------------------------------------------------------------------------

KpkGeometric::KpkGeometric(QWidget* parent) {
    Q_UNUSED(parent);

    image = new QPixmap(":/images/kpkGeometric.png");
}

KpkGeometric::~KpkGeometric() {

}

void KpkGeometric::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

//----------------------------------------------------------------------------------

KpkBacon::KpkBacon(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    alphabet = new QLineEdit(this);
    alphabet->setGeometry(120, 90, 990, 60);
    alphabet->setMaxLength(32);
    alphabet->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    alphabet->setFont(terminalFont);
    alphabet->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    alphabet->setText(QString("абвгдежзийклмнопрстуфхцчшщъыьэюя"));
    alphabet->setReadOnly(true);

    QLabel *labelAlphabet = new QLabel(this);
    labelAlphabet->setText("Алфавит:");
    labelAlphabet->setGeometry(120, 24, 990, 60);
    labelAlphabet->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    labelAlphabet->setFont(terminalFont);
    labelAlphabet->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    inputString = new QLineEdit(this);
    inputString->setGeometry(120, 240, 990, 60);
    inputString->setMaxLength(32);
    inputString->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    inputString->setFont(terminalFont);
    inputString->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(inputString, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *label1 = new QLabel(this);
    label1->setText("Введите символы a и b (латиница)");
    label1->setGeometry(120, 174, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    number = new QLineEdit(this);
    number->setGeometry(120, 420, 60, 60);
    number->setMaxLength(2);
    number->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    number->setFont(terminalFont);
    number->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(number, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel* tip1 = new QLabel(this);
    tip1->setGeometry(200, 420, 900, 60);
    tip1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    tip1->setFont(terminalFont);
    tip1->setAlignment(Qt::AlignLeft);
    tip1->setText("Ключевое число");

    letter = new QLineEdit(this);
    letter->setGeometry(120, 520, 60, 60);
    letter->setMaxLength(1);
    letter->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    letter->setFont(terminalFont);
    letter->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(letter, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel* tip2 = new QLabel(this);
    tip2->setGeometry(200, 520, 900, 60);
    tip2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    tip2->setFont(terminalFont);
    tip2->setAlignment(Qt::AlignLeft);
    tip2->setText("Буква");

    QLabel *labelResult = new QLabel(this);
    labelResult->setText("Результат:");
    labelResult->setGeometry(120, 620, 990, 60);
    labelResult->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    labelResult->setFont(terminalFont);
    labelResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    result = new QLineEdit(this);
    result->setGeometry(120, 720, 990, 60);
    result->setMaxLength(32);
    result->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    result->setFont(terminalFont);
    result->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    result->setText(QString(""));
    result->setReadOnly(true);
}

KpkBacon::~KpkBacon() {

}

void KpkBacon::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    inputString->setText(normalizeAB(inputString->text()));
    number->setText(normalizeNumber(number->text(), 32));
    letter->setText(normalize(letter->text()));

    if (inputString->text().size() == 32 && number->text().size() > 0 && letter->text().size() > 0) {
        QString resString = "";
        int pos = alphabet->text().indexOf(letter->text()[0]);

        for (long long i = 0; i < number->text().toInt(); i++) {
            if (i + pos >= inputString->text().size())
                break;
            resString.push_back(inputString->text()[i + pos]);

        }

        result->setText(resString);
    }
    else
        result->setText(QString(""));

    QPainter painter(this);

    if (inputString->text().size() != 32)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(inputString);

    if (number->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(number);

    if (letter->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(letter);

    if (alphabet->text().size() != 32)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(alphabet);

    if (result->text().size() == 0)
        painter.setPen(QPen(Qt::red, 4));
    else
        painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(result);
}

//----------------------------------------------------------------------------------

KpkAlberti::KpkAlberti(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Внешний диск (алфавит)");
    label1->setGeometry(120, 100, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    alphabet = new QLineEdit(this);
    alphabet->setGeometry(120, 200, 990, 60);
    alphabet->setMaxLength(33);
    alphabet->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    alphabet->setFont(terminalFont);
    alphabet->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    alphabet->setReadOnly(true);
    alphabet->setText("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");

    QLabel *label2 = new QLabel(this);
    label2->setText("Внутренний диск");
    label2->setGeometry(120, 300, 990, 60);
    label2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label2->setFont(terminalFont);
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    result = new QLineEdit(this);
    result->setGeometry(120, 400, 990, 60);
    result->setMaxLength(33);
    result->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    result->setFont(terminalFont);
    result->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(result, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    counterLabel = new QLineEdit(this);
    counterLabel->setGeometry(525, 550, 180, 120);
    counterLabel->setMaxLength(33);
    counterLabel->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    counterLabel->setFont(terminalFont);
    counterLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    counterLabel->setReadOnly(true);
    counterLabel->setText("0");

    buttonLeft = new RoundedButton(this);
    buttonLeft->setImage(new QPixmap(":/images/kpkButtonLeft.png"));
    buttonLeft->setGeometry(350, 550, 175, 120);
    connect(buttonLeft, &RoundedButton::clicked, buttonLeft, [=]{
        QString tmp = result->text();
        tmp.push_back(tmp[0]);
        tmp = tmp.mid(1);
        result->setText(tmp);

        counter = ((counter - 1) + 33) % 33;
        counterLabel->setText(QString::number(counter));

        repaint();
    });

    buttonRight = new RoundedButton(this);
    buttonRight->setImage(new QPixmap(":/images/kpkButtonRight.png"));
    buttonRight->setGeometry(705, 550, 175, 120);
    connect(buttonRight, &RoundedButton::clicked, buttonRight, [=]{
        QString tmp = result->text();
        tmp.push_front(tmp.back());
        tmp.chop(1);
        result->setText(tmp);

        counter = ((counter + 1) + 33) % 33;
        counterLabel->setText(QString::number(counter));

        repaint();
    });
}

KpkAlberti::~KpkAlberti() {

}

void KpkAlberti::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    result->setText(normalize(result->text()));

    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(alphabet);

    if (result->text().size() == 33) {
        painter.setPen(QPen(Qt::green, 4));
        buttonLeft->setEnabled(true);
        buttonRight->setEnabled(true);
    }
    else
    {
        painter.setPen(QPen(Qt::red, 4));
        buttonLeft->setEnabled(false);
        buttonRight->setEnabled(false);
    }

    PAINT_GREEN_RED_BORDERS(result);
}

//----------------------------------------------------------------------------------

KpkRailfence::KpkRailfence(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблица");
    label1->setGeometry(120, 50, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 20; j++) {
            letters.push_back(new QLineEdit(this));
            letters.back()->setMaxLength(1);
            letters.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters.back()->setFont(terminalFont);
            letters.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters.back()->setGeometry(115 + j * 50, 150 + i * 50, 50, 50);
            letters.back()->setText("");
            connect(letters.back(), &QLineEdit::textChanged, letters.back(), [=]{
                repaint();
            });
        }
    }
}

KpkRailfence::~KpkRailfence() {

}

void KpkRailfence::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 6));

    for (size_t i = 0; i < letters.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters[i]);
    }
}

//----------------------------------------------------------------------------------

KpkScitala::KpkScitala(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблица");
    label1->setGeometry(120, 50, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 20; j++) {
            letters.push_back(new QLineEdit(this));
            letters.back()->setMaxLength(1);
            letters.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters.back()->setFont(terminalFont);
            letters.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters.back()->setGeometry(115 + j * 50, 150 + i * 50, 50, 50);
            letters.back()->setText("");
            connect(letters.back(), &QLineEdit::textChanged, letters.back(), [=]{
                repaint();
            });
        }
    }
}

KpkScitala::~KpkScitala() {

}

void KpkScitala::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 6));

    for (size_t i = 0; i < letters.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters[i]);
    }
}

//----------------------------------------------------------------------------------

KpkGronsfeld::KpkGronsfeld(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Алфавит");
    label1->setGeometry(120, 100, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    alphabet = new QLineEdit(this);
    alphabet->setGeometry(120, 200, 990, 60);
    alphabet->setMaxLength(33);
    alphabet->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    alphabet->setFont(terminalFont);
    alphabet->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    alphabet->setReadOnly(true);
    alphabet->setText("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");

    number = new QLineEdit(this);
    number->setGeometry(120, 300, 60, 60);
    number->setMaxLength(2);
    number->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    number->setFont(terminalFont);
    number->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    number->setText("");
    connect(number, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *label2 = new QLabel(this);
    label2->setText("Число");
    label2->setGeometry(200, 300, 990, 60);
    label2->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label2->setFont(terminalFont);
    label2->setAlignment(Qt::AlignLeft);

    letter = new QLineEdit(this);
    letter->setGeometry(120, 400, 60, 60);
    letter->setMaxLength(1);
    letter->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    letter->setFont(terminalFont);
    letter->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    letter->setText("");
    connect(letter, SIGNAL(textChanged(QString)), this, SLOT(repaint()));

    QLabel *label3 = new QLabel(this);
    label3->setText("Буква");
    label3->setGeometry(200, 400, 990, 60);
    label3->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label3->setFont(terminalFont);
    label3->setAlignment(Qt::AlignLeft);

    result = new QLineEdit(this);
    result->setGeometry(120, 500, 60, 60);
    result->setMaxLength(1);
    result->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    result->setFont(terminalFont);
    result->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    result->setText("");
    result->setReadOnly(true);

    QLabel *label4 = new QLabel(this);
    label4->setText("Результат");
    label4->setGeometry(200, 500, 990, 60);
    label4->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label4->setFont(terminalFont);
    label4->setAlignment(Qt::AlignLeft);
}

KpkGronsfeld::~KpkGronsfeld() {

}

void KpkGronsfeld::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    number->setText(normalizeNumber(number->text(), 33));
    letter->setText(normalize(letter->text()));

    if (number->text().size() != 0 && letter->text().size() != 0) {
        int pos = (number->text().toInt() + alphabet->text().indexOf(letter->text()[0])) % alphabet->text().size();
        QString res = QString(alphabet->text()[pos]);

        result->setText(res);
    }

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 4));

    PAINT_GREEN_RED_BORDERS(alphabet);

    if (number->text().size() != 0)
        painter.setPen(QPen(Qt::green, 4));
    else
        painter.setPen(QPen(Qt::red, 4));

    PAINT_GREEN_RED_BORDERS(number);

    if (letter->text().size() != 0)
        painter.setPen(QPen(Qt::green, 4));
    else
        painter.setPen(QPen(Qt::red, 4));

    PAINT_GREEN_RED_BORDERS(letter);

    if (result->text().size() != 0)
        painter.setPen(QPen(Qt::green, 4));
    else
        painter.setPen(QPen(Qt::red, 4));

    PAINT_GREEN_RED_BORDERS(result);
}

//----------------------------------------------------------------------------------

KpkTranspon::KpkTranspon(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблица");
    label1->setGeometry(120, 50, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 20; j++) {
            letters.push_back(new QLineEdit(this));
            letters.back()->setMaxLength(1);
            letters.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters.back()->setFont(terminalFont);
            letters.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters.back()->setGeometry(115 + j * 50, 150 + i * 50, 50, 50);
            letters.back()->setText("");
            connect(letters.back(), &QLineEdit::textChanged, letters.back(), [=]{
                repaint();
            });
        }
    }
}

KpkTranspon::~KpkTranspon() {

}

void KpkTranspon::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 6));

    for (size_t i = 0; i < letters.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters[i]);
    }
}

//----------------------------------------------------------------------------------

KpkLitoreya::KpkLitoreya(QWidget* parent) {
    Q_UNUSED(parent);

    image = new QPixmap(":/images/kpkLitoreya.png");
}

KpkLitoreya::~KpkLitoreya() {

}

void KpkLitoreya::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(this->rect(), *image);
}

//----------------------------------------------------------------------------------

KpkAdfgvx::KpkAdfgvx(QWidget* parent) {
    Q_UNUSED(parent);

    int id = QFontDatabase::addApplicationFont(":/myFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont terminalFont(family);
    terminalFont.setPixelSize(36);

    QLabel *label1 = new QLabel(this);
    label1->setText("Таблица");
    label1->setGeometry(120, 50, 990, 60);
    label1->setStyleSheet("border: 0px; background-color: #282d28; color : #228b22");
    label1->setFont(terminalFont);
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 20; j++) {
            letters.push_back(new QLineEdit(this));
            letters.back()->setMaxLength(1);
            letters.back()->setStyleSheet("border: 1px solid green; background-color: #282d28; color : #228b22");
            letters.back()->setFont(terminalFont);
            letters.back()->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            letters.back()->setGeometry(115 + j * 50, 150 + i * 50, 50, 50);
            letters.back()->setText("");
            connect(letters.back(), &QLineEdit::textChanged, letters.back(), [=]{
                repaint();
            });
        }
    }

    sortButton = new RoundedButton(this);
    sortButton->setImage(new QPixmap(":/images/kpkSortButton.png"));
    sortButton->setGeometry(528, 650, 175, 120);
    connect(sortButton, &RoundedButton::clicked, sortButton, [=] {
        for (int i = 0; i < 19; i++) {
            for (int j = i + 1; j < 20; j++) {
                if (letters[i]->text()[0] > letters[j]->text()[0]) {
                    for (int c = 0; c < 8; c++) {
                        QString tmp = letters[20 * c + i]->text();
                        letters[20 * c + i]->setText(letters[20 * c + j]->text());
                        letters[20 * c + j]->setText(tmp);
                    }
                }
            }
        }
    });
}

KpkAdfgvx::~KpkAdfgvx() {

}

void KpkAdfgvx::sortTable() {

}

void KpkAdfgvx::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::green, 6));

    for (size_t i = 0; i < letters.size(); i++) {
        if (letters[i]->text().size() != 1) {
            painter.setPen(QPen(Qt::red, 6));
            break;
        }
    }

    for (size_t i = 0; i < letters.size(); i++) {
        PAINT_GREEN_RED_BORDERS(letters[i]);
    }
}
