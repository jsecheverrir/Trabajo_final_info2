#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include "Objeto.h"

class Enemigo : public Personaje {
private:
    bool movimientoAutomatico;
    int cantidadDanio;

public:
    Enemigo();
    void moverseHaciaJugador();
    void atacar(Jugador jugador);
};

#endif // ENEMIGO_H
