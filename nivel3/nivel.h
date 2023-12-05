// nivel.h
#ifndef NIVEL_H
#define NIVEL_H

#include <QObject>

class QGraphicsScene;
class Enemigo;

class Nivel : public QObject {
    Q_OBJECT
public:
    Nivel(QGraphicsScene *scene, Enemigo *enemigo);

    void configurar();  // Configura la escena para el nivel
    void iniciar();     // Inicia la lógica del nivel

public slots:
    void realizarAccion();  // Realiza una acción específica del nivel

private:
    QGraphicsScene *scene;
    Enemigo *enemigo;
};

#endif // NIVEL_H
