#ifndef OBJETORECOLECTABLE_H
#define OBJETORECOLECTABLE_H

#include "Objeto.h"
#include "Jugador.h"

class ObjetoRecolectable : public Objeto {
private:
         // Atributos de la clase
         // ...

public:
    // Métodos de la clase
    void aplicarEfecto(Jugador jugador);
};

#endif // OBJETORECOLECTABLE_H
