// nivel.cpp
#include "nivel.h"
#include "enemigo.h"
#include <QTimer>
#include <QDebug>

Nivel::Nivel(QGraphicsScene *scene, Enemigo *enemigo)
    : scene(scene), enemigo(enemigo)
{
}

void Nivel::configurar()
{
    // Configurar la escena según el nivel
    // ...
}

void Nivel::iniciar()
{
    // Iniciar la lógica del nivel
    // Por ejemplo, iniciar un temporizador para realizar acciones periódicas
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(realizarAccion()));
    timer->start(4000);  // Realizar una acción cada 4 segundos
}

void Nivel::realizarAccion()
{
    // Realizar una acción específica del nivel
    // Puedes acceder al enemigo y modificar su estado según sea necesario
    qDebug() << "Realizando acción en el nivel actual";

                // Por ejemplo, decrementar la vida del enemigo cada vez que realiza una acción
           enemigo->decrementarVida();

    // Puedes implementar lógica adicional según sea necesario
    // ...
}
