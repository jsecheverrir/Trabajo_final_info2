#include "muro.h"

Muro::Muro()
{

}
Muro::Muro(int x, int y, int w, int h)
{
    posx=x;
    this->posy=y;
    this->w=w;
    this->h=h;
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}

QRectF Muro::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}
