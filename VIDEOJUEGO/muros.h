#ifndef MUROS_H
#define MUROS_H
#include <QGraphicsItem>
#include <QPainter>


class MUROS : public QGraphicsItem
{
    int posx;
    int posy;
    int w;
    int h;

    public:
        MUROS();
        Muros(int x, int y, int w, int h);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QRectF boundingRect() const;
};

#endif // MUROS_H
