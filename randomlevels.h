#ifndef RANDOMLEVELS_H
#define RANDOMLEVELS_H

#include <includes.h>
#include <roundedbutton.h>

class RandomLevels : public QWidget
{
    Q_OBJECT
public:
    RandomLevels(QWidget *parent = nullptr, Game *game = nullptr);
    ~RandomLevels();

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

#endif // RANDOMLEVELS_H
