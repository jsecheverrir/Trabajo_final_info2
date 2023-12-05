#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <personaje.h>
#include <QGraphicsPixmapItem>

class QGraphicsScene;

//hay que heredar el timer del juego
class ENEMIGO : public PERSONAJE, public QGraphicsPixmapItem
{
    int posX, posY;
    int Daño;

    public:

        ENEMIGO();
        Enemigo(QGraphicsScene *scene, const QString &spritePath, int vida = 10, QGraphicsItem *parent = nullptr);
        void decrementarVida(); // Función para reducir la vida del enemigo

        //movimiento
        bool Atacar();

    private:
        QGraphicsScene *scene;
        int vida; // Variable para la vida del enemigo

};

#endif // ENEMIGO_H
