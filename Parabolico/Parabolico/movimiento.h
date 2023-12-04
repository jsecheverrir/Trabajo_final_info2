#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <math.h>

#define tiempo 0.1

class Movimiento
{

    double posx, posy, velx, vely, velocidad, angulo;

public:
    Movimiento();
    Movimiento(double x, double y, double v,double ang);
    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();
    double getPosx() const;
    void setPosx(double newPosx);
    double getPosy() const;
};

#endif // MOVIMIENTO_H
