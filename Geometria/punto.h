
#ifndef _PUNTO_H
#define _PUNTO_H

#include "string"
#include "direccion.h"
#include "punto.h"

class Punto{

public:

    float p[4];

    Punto();    //constructor
    Punto(float x, float y, float z);   //constructor
    Punto operator+(Direccion const &dir);  //operador suma con direccion
    Direccion operator-(Punto const &pun);  //operador resta de puntos
    std::string print();   //escribir por pantalla

};


#endif //_PUNTO_H
