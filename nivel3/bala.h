#ifndef BALA_H
#define BALA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>

class QGraphicsScene;
class Personaje; // Declaración anticipada de la clase Personaje

class Bala : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bala(QGraphicsScene *scene, Personaje *shooter = nullptr, const QPointF &direction = QPointF(1, 0), int speed = 10); // Modificado el constructor

public slots:
    void move(); // Slot para mover la bala

private:
    QGraphicsScene *scene;
    Personaje *shooter; // Puntero al personaje que disparó la bala
    QPointF direction;  // Dirección de la bala
    int speed;         // Velocidad de la bala
};

#endif // BALA_H
