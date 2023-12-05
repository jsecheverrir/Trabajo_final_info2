#ifndef JUGADOR_H
#define JUGADOR_H
#include <personaje.h>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QList>

class QGraphicsScene; // Necesario para evitar dependencias cíclicas
class Bala;           // Declaración anticipada de la clase Bala

class JUGADOR : public PERSONAJE
{
    int puntuacion;
    int ArmaEquipada;

    public:

        JUGADOR();
        JUGADOR(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent = nullptr);
        bool Disparar();
        bool UsarObjeto();
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        void KeyPressEvent(QKeyEvent *event) override;

    private:

        QGraphicsScene *scene;
        QList<Bala *> balas; // Contenedor de instancias de balas

};

#endif // JUGADOR_H
