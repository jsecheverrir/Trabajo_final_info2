#include "bala.h"
#include "enemigo.h"
#include "personaje.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Bala::Bala(QGraphicsScene *scene, Personaje *shooter, const QPointF &direction, int speed)
    : scene(scene), shooter(shooter), direction(direction), speed(speed)
{
    qDebug() << "Bala creada.";
    qDebug() << "Bala creada. Conectando temporizador...";
    // Configurar la apariencia de la bala (ajusta según tus necesidades)
    setPixmap(QPixmap("C:/Users/juana/OneDrive/Escritorio/nivel3/fotos/sprite/bala.png"));
    setScale(0.5); // Ajusta la escala según sea necesario

    // Conectar el temporizador al slot move
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); // Cambiar cada 50 milisegundos (ajusta según sea necesario)

    // Agregar la bala a la escena
    scene->addItem(this);
}

void Bala::move() {
    // Factor de velocidad (ajusta según sea necesario)
    qreal velocidad = 10.0;

    // Mover la bala en la dirección especificada con velocidad
    setPos(x() + velocidad * direction.x(), y() + velocidad * direction.y());

    // Verificar la colisión con el enemigo
    QList<QGraphicsItem *> items = collidingItems();
    foreach (QGraphicsItem *item, items) {
        // Si la bala colisiona con el enemigo, decrementa la vida del enemigo
        // y elimina la bala
        if (Enemigo *enemigo = dynamic_cast<Enemigo *>(item)) {
            enemigo->decrementarVida();
            scene->removeItem(this);
            delete this;
            return; // Sal de la función para evitar eliminar dos veces
        }
    }

    // Eliminar la bala cuando sale de la escena
    if (x() + pixmap().width() < 0 || x() > scene->width() ||
        y() + pixmap().height() < 0 || y() > scene->height()) {
        scene->removeItem(this);
        delete this;
    }
}
