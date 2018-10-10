
#include "matrix.h"


Matrix::Matrix() {
    for (int fil = 0; fil < 4; ++fil) {
        for (int col = 0; col < 4; ++col) {
            this->m[fil][col] = 0;
        }
    }
}

std::string Matrix::print(){
    std::string s = "Matriz:\n\t" + std::to_string(this->m[0][0]) + ", " + std::to_string(this->m[0][1]) + ", " + std::to_string(this->m[0][2]) + ", " + std::to_string(this->m[0][3]) + "\n";
    s += "\t" + std::to_string(this->m[1][0]) + ", " + std::to_string(this->m[1][1]) + ", " + std::to_string(this->m[1][2]) + ", " + std::to_string(this->m[1][3]) + "\n";
    s += "\t" + std::to_string(this->m[2][0]) + ", " + std::to_string(this->m[2][1]) + ", " + std::to_string(this->m[2][2]) + ", " + std::to_string(this->m[2][3]) + "\n";
    s += "\t" + std::to_string(this->m[3][0]) + ", " + std::to_string(this->m[3][1]) + ", " + std::to_string(this->m[3][2]) + ", " + std::to_string(this->m[3][3]);
    return s;
}

Matrix Matrix::operator*(Matrix const &mat){
    Matrix m;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            for(int k = 0; k < 4; ++k)
                m.m[i][j] += this->m[i][k] * mat.m[k][j];
    return m;
}

Direccion Matrix::operator*(Direccion const &dir){
    Direccion d;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            d.d[i] += this->m[i][j] * dir.d[j];
    return d;
}

