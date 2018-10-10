
#ifndef _OPERACIONES_H
#define _OPERACIONES_H

#include <cmath>
#include "direccion.h"

float dot(Direccion const &dir1, Direccion const &dir2);    //producto escalar entre dos direcciones
float ang(Direccion const &dir1, Direccion const &dir2);    //angulo entre dos direcciones
Direccion cross(Direccion const &dir1, Direccion const &dir2);    //producto vectorial entre dos direcciones
Direccion normal(Direccion const &dir); //normalizar vector



#endif //_OPERACIONES_H
