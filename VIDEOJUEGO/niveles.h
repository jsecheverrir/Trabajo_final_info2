#ifndef NIVELES_H
#define NIVELES_H


#include <QObject>

class QGraphicsScene;
class Enemigo;

class NIVELES : public QObject
{
    Q_OBJECT

    int ConfiguracionNivel;
    double tiempo;

    public:

        NIVELES();
        NIVELES(QGraphicsScene *scene, Enemigo *enemigo);
        int IniciarNivel();
        void Configurar();
        void IniciarTemporalizador();
        void FinalizarTemporalizador();

    public slots:

        void realizarAccion();  // Realiza una acción específica del nivel

    private:

        QGraphicsScene *scene;
        Enemigo *enemigo;

};

#endif // NIVELES_H
