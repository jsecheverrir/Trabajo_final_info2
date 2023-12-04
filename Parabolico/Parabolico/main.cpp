#include <iostream>
#include "movimiento.h"
#include <fstream>

using namespace std;

int main()
{
    double x, y,vel,ang;
    cout << "Ingrese la posicion en x" << endl;
    cin>>x;
    cout << "Ingrese la posicion en y" << endl;
    cin>>y;
    cout << "Ingrese la velocidad" << endl;
    cin>>vel;
    cout << "Ingrese el angulo" << endl;
    cin>>ang;

    double rad=(ang*3.14159)/180;
    Movimiento movimiento(x,y,vel,rad);
    ofstream fou;
    fou.open("calculos.txt");
    fou<<movimiento.getPosx()<<'\t'<<movimiento.getPosy()<<endl;
    while(movimiento.getPosy()>=0)
    {
        movimiento.CalcularVelocidad();
        movimiento.CalcularPosicion();
        fou<<movimiento.getPosx()<<'\t'<<movimiento.getPosy()<<endl;
        movimiento.ActualizarVelocidad();
    }
    fou.close();
    cout<<"Simulacion terminada"<<endl;


    return 0;
}
