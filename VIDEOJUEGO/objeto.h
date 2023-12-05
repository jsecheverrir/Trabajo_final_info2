#ifndef OBJETO_H
#define OBJETO_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>

class QGraphicsScene;
class JUGADOR; // Declaración anticipada de la clase Personaje


class OBJETO
{
    Q_OBJECT

    char Tipo;
    int Efecto;

    public:
        OBJETO();
        int DañoEfecto();
        OBJETO(QGraphicsScene *scene, Personaje *shooter = nullptr, const QPointF &direction = QPointF(1, 0), int speed = 10); // Modificado el constructor

    public slots:
        void move();

    private:
        QGraphicsScene *scene;
        JUGADOR *shooter; // Puntero al personaje que disparó la bala
        QPointF direction;  // Dirección de la bala
        int speed;         // Velocidad de la bala
};

#endif // OBJETO_H
