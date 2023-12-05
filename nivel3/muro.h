#ifndef MURO_H
#define MURO_H
#include <QGraphicsItem>
#include <QPainter>

class Muro : public QGraphicsItem, public QObject
{
    Q_OBJECT
    int posx;
    int posy;
    int w;
    int h;
public:
    Muro();
    Muro(int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    QRectF boundingRect() const;
};

#endif // MURO_H
