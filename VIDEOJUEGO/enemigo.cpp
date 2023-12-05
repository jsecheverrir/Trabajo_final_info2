#include "enemigo.h"
#include <QGraphicsScene>
#include <QDebug>

ENEMIGO::ENEMIGO()
{

}

ENEMIGO::Enemigo(QGraphicsScene *scene, const QString &spritePath, int vida, QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(spritePath), parent), scene(scene), vida(vida)
{
    // Ajustar el tamaño del enemigo
    qreal scaleFactor = 1.5;
    setScale(scaleFactor);

    // Posicionar en la parte inferior derecha de la escena a la misma altura que el personaje
    setPos(scene->width() - pixmap().width(), scene->height() - pixmap().height());
}

void ENEMIGO::decrementarVida() {
    vida--;
    qDebug() << "Vida del enemigo: " << vida;

    if (vida <= 0) {
        qDebug() << "Enemigo derrotado!";
    }
}
