#include "punto.h"

Punto::Punto() {
    this->p[0] = 0;
    this->p[1] = 0;
    this->p[2] = 0;
    this->p[3] = 1;
}

Punto::Punto(float x, float y, float z) {
    this->p[0] = x;
    this->p[1] = y;
    this->p[2] = z;
    this->p[3] = 1;
}

Punto Punto::operator+(Direccion const &dir){
    Punto p;
    p.p[0] = this->p[0] + dir.d[0];
    p.p[1] = this->p[1] + dir.d[1];
    p.p[2] = this->p[2] + dir.d[2];
    return p;
}

Direccion Punto::operator-(Punto const &pun){
    Direccion d;
    d.d[0] = this->p[0] - pun.p[0];
    d.d[1] = this->p[1] - pun.p[1];
    d.d[2] = this->p[2] - pun.p[2];
    return d;
}

std::string Punto::print(){
    std::string s = "Punto: " + std::to_string(this->p[0]) + "x, " + std::to_string(this->p[1]) + "y, " + std::to_string(this->p[2]) + "z";
    return s;
}