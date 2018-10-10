
#ifndef _MATRIX_H
#define _MATRIX_H

#include <string>
#include "direccion.h"

class Matrix{

public:

    float m[4][4];

    Matrix();    //constructor
    std::string print();    //string con la matriz
    Matrix operator*(Matrix const &mat);  //operador producto de matrices
    Direccion operator*(Direccion const &dir);  //operador producto por vector

};






#endif //_MATRIX_H
