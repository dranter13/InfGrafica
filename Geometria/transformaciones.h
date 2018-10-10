
#ifndef _TRANSFORMACIONES_H
#define _TRANSFORMACIONES_H

#include "matrix.h"
#include "punto.h"
#include "direccion.h"

Matrix traslacion(float tx, float ty, float tz);
Matrix escalado(float sx, float sy, float sz);
Matrix rotacionX(float a);
Matrix rotacionY(float a);
Matrix rotacionZ(float a);
Matrix cambioBase(Punto const &o, Direccion const &x, Direccion const &y, Direccion const &z);
Matrix invertir(Matrix const &mat);
Matrix trasponer(Matrix const &m);



#endif //_TRANSFORMACIONES_H
