#include "muros.h"

Muros::Muros()
{

}

Muros::Muros(int x, int y, int w, int h)
{
    posx=x;
    this->posy=y;
    this->w=w;
    this->h=h;
}

void Muros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}

QRectF Muros::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}
