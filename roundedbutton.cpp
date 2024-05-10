#include "roundedbutton.h"


RoundedButton::RoundedButton(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true);
}

void RoundedButton::setImage(QPixmap *image){
    this->image = image;
}

void RoundedButton::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    if (this->underMouse()) {
        painter.setOpacity(0.5);
    }

    painter.setPen(QPen(Qt::black, 2));
    painter.drawPixmap(this->rect(), *image);
}

RoundedButton::~RoundedButton(){

}
