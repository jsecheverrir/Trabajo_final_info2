// enemigo.cpp
#include "enemigo.h"
#include <QGraphicsScene>

Enemigo::Enemigo(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(spritePath), parent), scene(scene)
{
    // Ajustar el tamaño del enemigo si es necesario
    qreal scaleFactor = 0.5;
    setScale(scaleFactor);

    // Posicionar en la parte inferior derecha de la escena a la misma altura que el personaje
    setPos(scene->width() - pixmap().width(), scene->height() - pixmap().height());
}
