#include "personaje.h"
#include <QGraphicsScene>

Personaje::Personaje(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(spritePath), parent), scene(scene)

{
    // Ajustar el tamaño del personaje
    qreal scaleFactor = 0.5; //
    setScale(scaleFactor);
    // Ajustar la posición vertical para alinear con el piso
    setPos(0, scene->height()); //

}
