#ifndef KPK_H
#define KPK_H

#include <includes.h>
#include <roundedbutton.h>

class KpkCaesar;
class KpkVigener;
class KpkPLeyfer;
class KpkDvakvadrata;
class KpkKardano;
class KpkAtbash;
class KpkKvadratpolibiya;
class KpkTritemiy;
class KpkMagickvadrat;
class KpkLineyka;
class KpkJefferson;
class KpkGeometric;
class KpkBacon;
class KpkAlberti;
class KpkRailfence;
class KpkScitala;
class KpkGronsfeld;
class KpkTranspon;
class KpkLitoreya;
class KpkAdfgvx;

class Kpk : public QWidget
{
    Q_OBJECT
public:
    Kpk(QWidget *parent = nullptr);
    ~Kpk();

private:
    QPixmap *image;
    RoundedButton *backButton;
    vector <RoundedButton*> buttons;
    vector <QLabel*> buttonLabels;
    QStackedWidget *tabs;

    KpkCaesar *kpkCaesar;
    KpkVigener *kpkVigener;
    KpkPLeyfer *kpkPLeyfer;
    KpkDvakvadrata *kpkDvakvadrata;
    KpkKardano *kpkKardano;
    KpkAtbash *kpkAtbash;
    KpkKvadratpolibiya *kpkKvadratpolibiya;
    KpkTritemiy *kpkTritemiy;
    KpkMagickvadrat *kpkMagickvadrat;
    KpkLineyka *kpkLineyka;
    KpkJefferson *kpkJefferson;
    KpkGeometric *kpkGeometric;
    KpkBacon *kpkBacon;
    KpkAlberti *kpkAlberti;
    KpkRailfence *kpkRailfence;
    KpkScitala *kpkScitala;
    KpkGronsfeld *kpkGronsfeld;
    KpkTranspon *kpkTranspon;
    KpkLitoreya *kpkLitoreya;
    KpkAdfgvx *kpkAdfgvx;

public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkCaesar : public QWidget
{
    Q_OBJECT
public:
    KpkCaesar(QWidget *parent = nullptr);
    ~KpkCaesar();
private:
    QLineEdit *alphabet, *result, *counterLabel;
    RoundedButton *buttonLeft, *buttonRight;
    int counter = 0;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkVigener : public QWidget
{
    Q_OBJECT
public:
    KpkVigener(QWidget *parent = nullptr);
    ~KpkVigener();
private:
    QPixmap* image;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkPLeyfer : public QWidget
{
    Q_OBJECT
public:
    KpkPLeyfer(QWidget *parent = nullptr);
    ~KpkPLeyfer();
private:
    vector <QLineEdit*> letters;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkDvakvadrata : public QWidget
{
    Q_OBJECT
public:
    KpkDvakvadrata(QWidget *parent = nullptr);
    ~KpkDvakvadrata();
private:
    vector <QLineEdit*> letters1, letters2;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkKardano : public QWidget
{
    Q_OBJECT
public:
    KpkKardano(QWidget *parent = nullptr);
    ~KpkKardano();
private:
    vector <QLineEdit*> etalon;
    RoundedButton *button4, *button6, *button8;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkAtbash : public QWidget
{
    Q_OBJECT
public:
    KpkAtbash(QWidget *parent = nullptr);
    ~KpkAtbash();
private:
    QPixmap *image;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkKvadratpolibiya : public QWidget
{
    Q_OBJECT
public:
    KpkKvadratpolibiya(QWidget *parent = nullptr);
    ~KpkKvadratpolibiya();
private:
    vector <QLineEdit*> letters;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkTritemiy : public QWidget
{
    Q_OBJECT
public:
    KpkTritemiy(QWidget *parent = nullptr);
    ~KpkTritemiy();
private:
    QPixmap *image;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkMagickvadrat : public QWidget
{
    Q_OBJECT
public:
    KpkMagickvadrat(QWidget *parent = nullptr);
    ~KpkMagickvadrat();
private:
    vector <QLineEdit*> etalon;
    RoundedButton *button4, *button6, *button8;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkLineyka : public QWidget
{
    Q_OBJECT
public:
    KpkLineyka(QWidget *parent = nullptr);
    ~KpkLineyka();
private:
    QLineEdit *inputString, *letter1, *letter2;
    QLabel *result;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkJefferson : public QWidget
{
    Q_OBJECT
public:
    KpkJefferson(QWidget *parent = nullptr);
    ~KpkJefferson();
private:
    QLineEdit *disk1, *disk2, *disk3, *disk4, *disk5, *disk6, *disk7, *disk8, *key, *number, *letter, *result;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkGeometric : public QWidget
{
    Q_OBJECT
public:
    KpkGeometric(QWidget *parent = nullptr);
    ~KpkGeometric();
private:
    QPixmap *image;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkBacon : public QWidget
{
    Q_OBJECT
public:
    KpkBacon(QWidget *parent = nullptr);
    ~KpkBacon();
private:
    QLineEdit *inputString, *number, *letter, *alphabet, *result;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkAlberti : public QWidget
{
    Q_OBJECT
public:
    KpkAlberti(QWidget *parent = nullptr);
    ~KpkAlberti();
private:
    QLineEdit *alphabet, *result, *counterLabel;
    RoundedButton *buttonLeft, *buttonRight;
    int counter = 0;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkRailfence : public QWidget
{
    Q_OBJECT
public:
    KpkRailfence(QWidget *parent = nullptr);
    ~KpkRailfence();
private:
    vector <QLineEdit*> letters;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkScitala : public QWidget
{
    Q_OBJECT
public:
    KpkScitala(QWidget *parent = nullptr);
    ~KpkScitala();
private:
    vector <QLineEdit*> letters;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkGronsfeld : public QWidget
{
    Q_OBJECT
public:
    KpkGronsfeld(QWidget *parent = nullptr);
    ~KpkGronsfeld();
private:
    QLineEdit *alphabet, *number, *letter, *result;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkTranspon : public QWidget
{
    Q_OBJECT
public:
    KpkTranspon(QWidget *parent = nullptr);
    ~KpkTranspon();
private:
    vector <QLineEdit*> letters;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkLitoreya : public QWidget
{
    Q_OBJECT
public:
    KpkLitoreya(QWidget *parent = nullptr);
    ~KpkLitoreya();
private:
    QPixmap *image;
public slots:
    void paintEvent(QPaintEvent *event);
};

class KpkAdfgvx : public QWidget
{
    Q_OBJECT
public:
    KpkAdfgvx(QWidget *parent = nullptr);
    ~KpkAdfgvx();
private:
    vector <QLineEdit*> letters;
    RoundedButton *sortButton;
public slots:
    void paintEvent(QPaintEvent *event);
    void sortTable();
};

#endif // KPK_H
