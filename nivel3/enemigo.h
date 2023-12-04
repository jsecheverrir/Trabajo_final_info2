// enemigo.h
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>

class QGraphicsScene;

class Enemigo : public QGraphicsPixmapItem {
public:
    Enemigo(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent = nullptr);

private:
    QGraphicsScene *scene;
};

#endif // ENEMIGO_H
