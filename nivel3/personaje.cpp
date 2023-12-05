#include "personaje.h"
#include "bala.h"
#include "qgraphicsscene.h"
#include <QKeyEvent>
#include <QDebug>

Personaje::Personaje(QGraphicsScene *scene, const QString &spritePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(spritePath), parent), scene(scene)
{
    // Ajustar el tamaño del personaje
    qreal scaleFactor = 0.5;
    setScale(scaleFactor);

    // Ajustar la posición vertical para alinear con el piso
    setPos(0, scene->height());

    // Configurar la conexión del evento de presionar la tecla a la función keyPressEvent
    // de la clase Personaje
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

}
Personaje::Personaje()
{
    posx=0;
    posy=0;
    radio=25;
    velocidad=3;
    setPos(posx, posy);
}
Personaje::Personaje(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    velocidad=3;
    setPos(posx, posy);
}

void Personaje::MoveUp()
{
    posy-=velocidad;
    setPos(posx, posy);
}

void Personaje::MoveDown()
{
    posy+=velocidad;
    setPos(posx, posy);
}

void Personaje::MoveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
}

void Personaje::MoveRight()
{
    posx+=velocidad;
    setPos(posx,posy);
}
void Personaje::keyPressEvent(QKeyEvent *event)
{
    // Crear y disparar una bala cuando se presiona la tecla de espacio
    if (event->key() == Qt::Key_Space)
    {
        qDebug() << "Tecla de espacio presionada. Creando bala...";

        // Crear la bala y establecer su posición con velocidad personalizada (15 en este caso)
        Bala *bala = new Bala(scene, this, QPointF(1, 0), 15); // Ajusta la velocidad según sea necesario
        bala->setPos(x() + pixmap().width() / 2, y() + 45); // Ajusta la posición según sea necesario

    }
}
