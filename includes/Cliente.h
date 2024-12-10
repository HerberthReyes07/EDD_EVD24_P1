//
// Created by herberthreyes on 7/12/24.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include"matrizDispersa/MatrizDispersa.h"
#include "matrizDispersa/Nodo.h"

class Cliente {
private:
    MatrizDispersa* matriz;
    Nodo *usuario;

public:
    Cliente();

    ~Cliente();

    Cliente(Nodo *usuario, MatrizDispersa* matriz);

    Nodo *getUsuario();

    void setUsuario(Nodo *usuario);

    MatrizDispersa* getMatriz();

    void setMatriz(MatrizDispersa* matriz);

    void menu();

    void agregarActivo();

    void eliminarActivo();

    void modificarActivo();

    void rentarActivo();

    void activosRentados();

    void misActivosRentados();
};

#endif //CLIENTE_H
