
#include "transformaciones.h"
#include <cmath>


Matrix traslacion(float tx, float ty, float tz) {
    Matrix m;
    m.m[0][0] = 1;
    m.m[1][1] = 1;
    m.m[2][2] = 1;
    m.m[3][3] = 1;
    m.m[0][3] = tx;
    m.m[1][3] = ty;
    m.m[2][3] = tz;
    return m;
}

Matrix escalado(float sx, float sy, float sz) {
    Matrix m;
    m.m[0][0] = sx;
    m.m[1][1] = sy;
    m.m[2][2] = sz;
    m.m[3][3] = 1;
    return m;
}

Matrix rotacionX(float a) {
    Matrix m;
    m.m[0][0] = 1;
    m.m[1][1] = cosf(a);
    m.m[2][2] = cosf(a);
    m.m[3][3] = 1;
    m.m[1][2] = -sinf(a);
    m.m[2][1] = sinf(a);
    return m;
}

Matrix rotacionY(float a) {
    Matrix m;
    m.m[1][1] = 1;
    m.m[0][0] = cosf(a);
    m.m[2][2] = cosf(a);
    m.m[3][3] = 1;
    m.m[2][0] = -sinf(a);
    m.m[0][2] = sinf(a);
    return m;
}

Matrix rotacionZ(float a) {
    Matrix m;
    m.m[2][2] = 1;
    m.m[1][1] = cosf(a);
    m.m[0][0] = cosf(a);
    m.m[3][3] = 1;
    m.m[0][1] = -sinf(a);
    m.m[1][0] = sinf(a);
    return m;
}

Matrix cambioBase(Punto const &o, Direccion const &u, Direccion const &v, Direccion const &w) {
    Matrix m;
    m.m[0][0] = u.d[0];
    m.m[0][1] = v.d[0];
    m.m[0][2] = w.d[0];
    m.m[0][3] = o.p[0];
    m.m[1][0] = u.d[1];
    m.m[1][1] = v.d[1];
    m.m[1][2] = w.d[1];
    m.m[1][3] = o.p[1];
    m.m[2][0] = u.d[2];
    m.m[2][1] = v.d[2];
    m.m[2][2] = w.d[2];
    m.m[2][3] = o.p[2];
    m.m[3][0] = 0;
    m.m[3][1] = 0;
    m.m[3][2] = 0;
    m.m[3][3] = 1;
    return m;
}

Matrix invertir(Matrix const &mat) {
    Matrix b;
    Matrix a = mat;
    b.m[0][0] = 1;b.m[1][1] = 1;b.m[2][2] = 1;b.m[3][3] = 1;
    for(int k=0;k<4;k++){
        float cont = 0, cont2 = 0;
        for (int i = k; i < 4; i++) {
            if (a.m[i][k] == 1) {
                for (int j = 0; j < 4; j++) {
                    cont = a.m[i][j];
                    cont2 = b.m[i][j];
                    a.m[i][j] = a.m[k][j];
                    b.m[i][j] = b.m[k][j];
                    a.m[k][j] = cont;
                    b.m[k][j] = cont2;
                }
            } else if (a.m[i][k] == 0) {
                for (int j = 0; j < 4; j++) {
                    cont = a.m[i][j];
                    cont2 = b.m[i][j];
                    a.m[i][j] = a.m[4 - 1][j];
                    b.m[i][j] = b.m[4 - 1][j];
                    a.m[4 - 1][j] = cont;
                    b.m[4 - 1][j] = cont2;
                }
            }
        }
        float particular = a.m[k][k];
        for (int i = 0; i < 4; i++) {
            a.m[k][i] = a.m[k][i] / particular;
            b.m[k][i] = b.m[k][i] / particular;
            if (a.m[k][i] == (-0)) {
                a.m[k][i] = 0;
            }
            if (b.m[k][i] == (-0)) {
                b.m[k][i] = 0;
            }
        }
        for (int j = k + 1; j < 4; j++) {
            particular = a.m[j][k];
            for (int i = 0; i < 4; i++) {
                a.m[j][i] = a.m[j][i] - (particular * a.m[k][i]);
                b.m[j][i] = b.m[j][i] - (particular * b.m[k][i]);
                if (a.m[j][i] == (-0)) {
                    a.m[j][i] = 0;
                }
                if (b.m[j][i] == (-0)) {
                    b.m[j][i] = 0;
                }
            }
        }

    }
    for(int k=4-1;k>=0;k--){
        float particular;
        for (int j = k - 1; j >= 0; j--) {
            particular = a.m[j][k];
            for (int i = 4 - 1; i >= 0; i--) {
                a.m[j][i] = a.m[j][i] - (particular * a.m[k][i]);
                b.m[j][i] = b.m[j][i] - (particular * b.m[k][i]);
                if (a.m[j][i] == (-0)) {
                    a.m[j][i] = 0;
                }
                if (b.m[j][i] == (-0)) {
                    b.m[j][i] = 0;
                }
            }
        }
    }
    return b;
}

Matrix trasponer(Matrix const &mat) {
    Matrix m;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            m.m[i][j] = mat.m[j][i];
        }
    }
    return m;
}
