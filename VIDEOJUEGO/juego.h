#ifndef JUEGO_H
#define JUEGO_H


class JUEGO
{
    int NivelActual;
    int Jugadorprincipal;
    int NumeroNivel;

    public:

    JUEGO();
    iniciarJuego();
    CargarNivel(int numeroNivel);
    PantallaVictoria();
    PantallaDerrota();
    ReiniciarNivel();


};

#endif // JUEGO_H
