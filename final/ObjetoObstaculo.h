#ifndef OBJETOOBSTACULO_H
#define OBJETOOBSTACULO_H

#include "Objeto.h"

enum TipoObstaculo {
    ESTATICO,
    MOVIL,
    // Otros tipos de obstáculos
};

class ObjetoObstaculo : public Objeto {
private:
    TipoObstaculo tipo;
    int resistencia;

public:
    // Métodos de la clase
    void aplicarDanio(int cantidad);
};

#endif // OBJETOOBSTACULO_H
