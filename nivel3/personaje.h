#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>

class QGraphicsScene; // Necesario para evitar dependencias cíclicas

class Personaje : public QGraphicsPixmapItem {
public:
    Personaje(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent = nullptr);

private:
    QGraphicsScene *scene;
};

#endif // PERSONAJE_H
