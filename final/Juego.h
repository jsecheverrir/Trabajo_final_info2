#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
//#include "Jugador.h"
#include "Nivel.h"

class Juego {
private:
    int nivelActual;
//    Jugador jugadorPrincipal;
    std::vector<Nivel> listaNiveles;
    int numeroNiveles;

public:
    Juego();
    void iniciarJuego();
    void cargarNivel(int numeroNivel);
    void pantallaVictoria();
    void pantallaDerrota();
    void reiniciarNivel();
};

#endif // JUEGO_H
