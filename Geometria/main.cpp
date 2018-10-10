#include <iostream>
#include <string>
#include "matrix.h"
#include "operaciones.h"
#include "transformaciones.h"
#include "punto.h"
#include "direccion.h"
#include "esfera.h"

const float PI = 3.14159264;

using namespace std;

void programa(Esfera e1, Esfera e2, Punto estacion1, Punto estacion2){

    Direccion res = estacion2 - estacion1;
    
    Direccion k1 = normal(estacion1 - e1.get_centro());
    cout << "Normal estacion 1: " << k1.print() << endl;
    Direccion i1 = normal(cross(k1, e1.get_eje()));
    cout << "Longitud estacion 1: " << i1.print() << endl;
    Direccion aux = cross(k1, i1);
    aux.inverso();
    Direccion j1 = normal(aux);
    cout << "Latitud estacion 1: " << j1.print() << endl;
    
    Direccion k2 = normal(estacion2 - e2.get_centro());;
    cout << "Normal estacion 2: " << k2.print() << endl;
    Direccion i2 = normal(cross(k2, e2.get_eje()));;
    cout << "Longitud estacion 2: " << i2.print() << endl;
    aux = cross(k2, i2);
    aux.inverso();
    Direccion j2 = normal(aux);;
    cout << "Latitud estacion 2: " << j2.print() << endl;
    
    //Matrix base1 = cambioBase(estacion1, i1, j1, k1);
    //Matrix base2 = cambioBase(estacion2, i2, j2, k2);
    Matrix base1 = cambioBase(estacion1, j1, i1, k1);
    Matrix base2 = cambioBase(estacion2, j2, i2, k2);
    //Matrix base1 = cambioBase(estacion1, k1, j1, i1);
    //Matrix base2 = cambioBase(estacion2, k2, j2, i2);
    //Matrix base1 = cambioBase(estacion1, i1, k1, j1);
    //Matrix base2 = cambioBase(estacion2, i2, k2, j2);
    
    
    Direccion res1 = base1 * res;
    res1.inverso();
    Direccion res2 = base2 * res;
    //res2.inverso();
    cout << res1.print() << endl;
    cout << res2.print() << endl;    
}

int main(){
    
    bool correcto = true;
    
    cout << "Escriba los siguientes parametros de la 1ª esfera: \nCentro: " << flush;
    float x, y, z;
    cin >> x >> y >> z;
    Punto centro = Punto(x,y,z);
    cout << "Eje: " << flush;
    cin >> x >> y >> z;
    Direccion eje = Direccion(x, y, z);
    cout << "Ciudad de Referencia: " << flush;
    cin >> x >> y >> z;
    Punto ciudad = Punto(x, y, z);
    Esfera e1 = Esfera(centro, eje, ciudad);
    correcto = correcto && e1.esCorrecto();
    if(!e1.esCorrecto()){
        cout << "Esfera incorrecta" << endl;
    }
    
    cout << "\nEscriba los siguientes parametros de la 2ª esfera: \nCentro: " << flush;
    cin >> x >> y >> z;
    Punto centro2 = Punto(x,y,z);
    cout << "Eje: " << flush;
    cin >> x >> y >> z;
    Direccion eje2 = Direccion(x, y, z);
    cout << "Ciudad de Referencia: " << flush;
    cin >> x >> y >> z;
    Punto ciudad2 = Punto(x, y, z);
    Esfera e2 = Esfera(centro2, eje2, ciudad2);
    correcto = correcto && e2.esCorrecto();
    if(!e2.esCorrecto()){
        cout << "Esfera incorrecta" << endl;
    }
    
    cout << "\nEscriba los siguientes parametros de la estacion de la 1ª esfera: \nInclinacion: " << flush;
    float inc1;
    cin >> inc1;
    cout << "Azimuth: " << flush;
    float azimuth1;
    cin >> azimuth1;
    correcto = correcto && (inc1 > 0 && inc1 < PI && azimuth1 > -PI && azimuth1 <= PI);
    if( !(inc1 > 0 && inc1 < PI && azimuth1 > -PI && azimuth1 <= PI) ){
        cout << "Valores para la estacion fuera de rango" << endl;
    }
    
    cout << "\nEscriba los siguientes parametros de la estacion de la 2ª esfera: \nInclinacion: " << flush;
    float inc2;
    cin >> inc2;
    cout << "Azimuth: " << flush;
    float azimuth2;
    cin >> azimuth2;
    correcto = correcto && (inc2 > 0 && inc2 < PI && azimuth2 > -PI && azimuth2 <= PI);
    if( !(inc2 > 0 && inc2 < PI && azimuth2 > -PI && azimuth2 <= PI) ){
        cout << "Valores para la estacion fuera de rango" << endl;
    }
    
    Punto estacion1 = e1.obtener_punto(inc1, azimuth1);
    cout << "Coordenadas de la primera estacion: " << estacion1.print() << endl;
    Punto estacion2 = e2.obtener_punto(inc2, azimuth2);
    cout << "Coordenadas de la segunda estacion: " << estacion2.print() << endl;
    
    if(correcto){
        programa(e1, e2, estacion1, estacion2);
    }
    else{
        cout << "Los parametros no son correctos" << endl;
    } 
    return 0;
}