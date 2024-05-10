#ifndef SPRAVOCHNIK_H
#define SPRAVOCHNIK_H

#include <includes.h>

class Spravochnik : public QWidget
{
    Q_OBJECT
public:
    Spravochnik(QWidget *parent = nullptr);
    ~Spravochnik();

private:
    vector <QPixmap*> pictures;
    int counter = 0;
    QPixmap* image;
    RoundedButton *buttonLeft, *buttonRight, *backButton;

public slots:
    void paintEvent(QPaintEvent *event);
};

#endif // SPRAVOCHNIK_H
