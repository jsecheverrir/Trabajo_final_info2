#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"

class Jugador : public Personaje {
private:
    //Arma armaEquipada;

public:
    Jugador();
    void disparar();
    //void usarObjeto(ObjetoUsable obj);
};

#endif // JUGADOR_H
