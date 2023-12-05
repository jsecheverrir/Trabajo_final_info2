#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>

class QGraphicsScene;

class Enemigo : public QGraphicsPixmapItem {
public:
    Enemigo(QGraphicsScene *scene, const QString &spritePath, int vida = 10, QGraphicsItem *parent = nullptr);

    void decrementarVida(); // Función para reducir la vida del enemigo

private:
    QGraphicsScene *scene;
    int vida; // Variable para la vida del enemigo
};

#endif // ENEMIGO_H
