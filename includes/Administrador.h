//
// Created by herberthreyes on 7/12/24.
//

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "matrizDispersa/MatrizDispersa.h"

class Administrador {
private:
    MatrizDispersa *matriz;

public:
    Administrador();

    ~Administrador();

    Administrador(MatrizDispersa *matriz);

    MatrizDispersa *getMatriz();

    void setMatriz(MatrizDispersa *matriz);

    void menu();

    void registrarUsuario();

    void reporteMatrizDispersa();

    void reporteActivosDisponiblesDepartamento();

    void reporteActivosDisponiblesEmpresa();

    void reporteTransacciones();

    void reporteActivosUsuario();

    void activosRentadosUsuario();

    void ordenarTransacciones();

    bool insertarAtras(std::string username);
};

#endif //ADMINISTRADOR_H
