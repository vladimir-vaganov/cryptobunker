#ifndef MENU_H
#define MENU_H

#include <includes.h>
#include <roundedbutton.h>

class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    QPixmap *image;
    RoundedButton *exitButton, *infoButton, *levelsButton;
public slots:
    void paintEvent(QPaintEvent *event);
    void exit();
};

#endif // MENU_H
