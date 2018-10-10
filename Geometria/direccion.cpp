#include "direccion.h"
#include <cmath>
#include <iostream>

Direccion::Direccion() {
    this->d[0] = 0;
    this->d[1] = 0;
    this->d[2] = 0;
    this->d[3] = 0;
}

Direccion::Direccion(float x, float y, float z) {
    this->d[0] = x;
    this->d[1] = y;
    this->d[2] = z;
    this->d[3] = 0;
}

Direccion Direccion::operator+(Direccion const &dir) {
    Direccion d;
    d.d[0] = this->d[0] + dir.d[0];
    d.d[1] = this->d[1] + dir.d[1];
    d.d[2] = this->d[2] + dir.d[2];
    return d;
}

Direccion Direccion::operator-(Direccion const &dir) {
    Direccion d;
    d.d[0] = this->d[0] - dir.d[0];
    d.d[1] = this->d[1] - dir.d[1];
    d.d[2] = this->d[2] - dir.d[2];
    return d;
}

Direccion Direccion::operator*(float esc){
    Direccion d;
    d.d[0] = this->d[0] * esc;
    d.d[1] = this->d[1] * esc;
    d.d[2] = this->d[2] * esc;
    return d;
}

Direccion Direccion::operator/(float esc){
    Direccion d(0,0,0);
    d.d[0] = this->d[0] / esc;
    d.d[1] = this->d[1] / esc;
    d.d[2] = this->d[2] / esc;
    return d;
}

float Direccion::mod()const {
    return sqrtf(powf(this->d[0],2.0) + powf(this->d[1],2.0) + powf(this->d[2],2.0));
}

void Direccion::inverso() {
    this->d[0] = -(this->d[0]);
    this->d[1] = -(this->d[1]);
    this->d[2] = -(this->d[2]);    
}


std::string Direccion::print(){
    std::string s = "Direccion: " + std::to_string(this->d[0]) + "x, " + std::to_string(this->d[1]) + "y, " + std::to_string(this->d[2]) + "z";
    return s;
}




