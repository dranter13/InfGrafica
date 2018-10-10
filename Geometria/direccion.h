

#ifndef _DIRECCION_H
#define _DIRECCION_H

#include <string>

class Direccion{

public:

    float d[4];     //dx, dy, dz en orden, dw vale 0 siempre

    Direccion();    //constructor
    Direccion(float x, float y, float z);   //constructor
    Direccion operator+(Direccion const &dir);  //operador suma de direcciones
    Direccion operator-(Direccion const &dir);  //operador resta de direcciones
    Direccion operator*(float esc);  //operador multiplicacion por escalar
    Direccion operator/(float esc);  //operador division por escalar
    float mod()const; //modulo de direccion
    void inverso();
    std::string print();   //escribir por pantalla
};



#endif //_DIRECCION_H
