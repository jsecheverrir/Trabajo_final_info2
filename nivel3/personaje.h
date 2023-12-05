#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>

class QGraphicsScene; // Necesario para evitar dependencias cíclicas
class Bala;           // Declaración anticipada de la clase Bala

class Personaje : public QGraphicsPixmapItem {
    int radio;
    int posx;
    int posy;
    int velocidad;


public:
    Personaje(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent = nullptr);
    Personaje();
    Personaje(int x, int y, int r );
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    // Evento de presionar tecla
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsScene *scene;
    QList<Bala *> balas; // Contenedor de instancias de balas
};

#endif // PERSONAJE_H
