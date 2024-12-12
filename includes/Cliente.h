//
// Created by herberthreyes on 7/12/24.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include"matrizDispersa/MatrizDispersa.h"
#include "matrizDispersa/NodoMD.h"

class Cliente {
private:
    MatrizDispersa *matriz;
    NodoMD *usuario;

public:
    Cliente();

    ~Cliente();

    Cliente(NodoMD *usuario, MatrizDispersa *matriz);

    NodoMD *getUsuario();

    void setUsuario(NodoMD *usuario);

    MatrizDispersa *getMatriz();

    void setMatriz(MatrizDispersa *matriz);

    void menu();

    void agregarActivo();

    void eliminarActivo();

    void modificarActivo();

    void rentarActivo();

    void activosRentados();

    void misActivosRentados();

    std::string generarAlfanumerico();
};

#endif //CLIENTE_H
