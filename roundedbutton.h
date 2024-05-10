#ifndef ROUNDEDBUTTON_H
#define ROUNDEDBUTTON_H

#include <includes.h>

class RoundedButton : public QPushButton
{
    Q_OBJECT
public:
    RoundedButton(QWidget *parent = nullptr);
    ~RoundedButton();

    void setImage(QPixmap *image);
private:
    QPixmap *image;

public slots:
    void paintEvent(QPaintEvent *event = nullptr);

};

#endif // ROUNDEDBUTTON_H
