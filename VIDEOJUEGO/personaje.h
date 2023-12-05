#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "objeto.h"

class PERSONAJE
{
    int posX, posY, vidas, radio, velocidad;

    public:
        PERSONAJE();
        PERSONAJE(int x, int y, int r);
        bool Colicion();
        int NumeroVidas();
        int RecolectarObjeto(OBJETO Objeto);
};

#endif // PERSONAJE_H
