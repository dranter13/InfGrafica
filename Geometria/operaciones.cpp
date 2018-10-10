
#include "operaciones.h"


float dot(Direccion const &dir1, Direccion const &dir2) {
    Direccion d;
    d.d[0] = dir1.d[0] * dir2.d[0];
    d.d[1] = dir1.d[1] * dir2.d[1];
    d.d[2] = dir1.d[2] * dir2.d[2];
    return d.d[0]+d.d[1]+d.d[2];
}

float ang(Direccion const &dir1, Direccion const &dir2){
    return asinf(cross(dir1,dir2).mod() / (dir1.mod() * dir2.mod()));
}

Direccion cross(Direccion const &dir1, Direccion const &dir2){
    Direccion d;
    d.d[0] = dir1.d[1]*dir2.d[2] - dir1.d[2]*dir2.d[1];
    d.d[1] = dir1.d[2]*dir2.d[0] - dir1.d[0]*dir2.d[2];
    d.d[2] = dir1.d[0]*dir2.d[1] - dir1.d[1]*dir2.d[0];
    return d;
}

Direccion normal(Direccion const &dir){
    Direccion d = dir;
    float mod = dir.mod();
    d.d[0] = d.d[0]/mod;
    d.d[1] = d.d[1]/mod;
    d.d[2] = d.d[2]/mod;
    return d;
}