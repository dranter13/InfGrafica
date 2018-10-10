

#include "esfera.h"

using namespace std;


Esfera::Esfera(){
    Punto centro,ciudad;
    Direccion eje;
    this->centro = centro;
    this->ciudad = ciudad;
    this->eje = eje;
    this->correcto = false;
}

Esfera::Esfera(Punto centro, Direccion eje, Punto ciudad){
    Direccion radio = centro - ciudad;
    float modr,mode;
    modr = radio.mod();
    mode = eje.mod();
    if(fabsf(mode/2 - modr) <= 0.000001) {
        this->centro = centro;
        this->ciudad = ciudad;
        this->eje = eje;
        this->correcto = true;
    }else{
        Punto c,ce;
        Direccion e;
        this->centro = ce;
        this->ciudad = c;
        this->eje = e;
        this->correcto = false;
    }
}

std::string Esfera::print(){
    std::string s;
    if(this->correcto) {
        s = "Esfera:\n\tCentro: " + this->centro.print() + "\n";
        s += "\tEje: " + this->eje.print() + "\n";
        s += "\tCiudad: " + this->centro.print();
    }else{
        s = "Esfera incorrecta";
    }
    return s;
}

bool Esfera::esCorrecto(){
    return this->correcto;
}

Punto Esfera::get_centro(){
    return this->centro;
}

Direccion Esfera::get_eje(){
    return this->eje;
}

Punto Esfera::get_ciudad(){
    return this->ciudad;
}

Punto Esfera::obtener_punto(float inclinacion, float azimuth){
    Direccion dir = Direccion(sin(inclinacion)*sin(azimuth), sin(inclinacion)*cos(azimuth), cos(inclinacion));
    cout << "Obtener_punto vector: " << dir.print() << endl;
    float radio = (this->eje.mod())/2;
    //Direccion radio = this->get_ciudad() - this->get_centro();
    Punto res = this->centro + (dir*radio);
    return res;
}



