#ifndef LEVELS_H
#define LEVELS_H

#include <includes.h>
#include <roundedbutton.h>

class Levels : public QWidget
{
    Q_OBJECT
public:
    Levels(QWidget *parent = nullptr, Game *game = nullptr);
    ~Levels();

    void setPassed(int index);

private:
    QPixmap *image, *imageBlocked, *imageAble, *imagePassed;
    vector <RoundedButton*> buttons;
    vector <QLabel*> buttonLabels;
    RoundedButton *backButton;
    QLabel *backLabel;

public slots:
    void paintEvent(QPaintEvent *event = nullptr);
};

#endif // LEVELS_H
