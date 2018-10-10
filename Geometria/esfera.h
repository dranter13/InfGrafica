
#ifndef _ESFERA_H
#define _ESFERA_H


#include "punto.h"
#include "direccion.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Esfera{
    
    public:

    Punto centro;
    Direccion eje;
    Punto ciudad;
    bool correcto;

    Esfera();    //constructor
    Esfera(Punto centro, Direccion eje, Punto ciudad);   //constructor
    std::string print();   //escribir por pantalla
    bool esCorrecto();   // comprueba que los datos al crear son correctos
    
    Punto get_centro();
    Direccion get_eje();
    Punto get_ciudad();
    Punto obtener_punto(float inclinacion, float azimuth);
};



#endif //_ESFERA_H
