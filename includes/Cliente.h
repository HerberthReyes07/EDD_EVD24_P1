//
// Created by herberthreyes on 7/12/24.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "listaCircularDoblementeEnlazada/ListaCircularDoble.h"
#include "matrizDispersa/MatrizDispersa.h"
#include "matrizDispersa/NodoMD.h"

class Cliente {
private:
    NodoMD *usuario;
    MatrizDispersa *matriz;
    ListaCircularDoble *listaCircularDoble;

    void verCatalogo();

    void verCatalogoActivosRentados();

    Activo *buscarActivo(std::string id);

    void recorrerMisActivosRentados(NodoAVL *&raiz);

public:
    Cliente();

    ~Cliente();

    Cliente(NodoMD *usuario, MatrizDispersa *matriz, ListaCircularDoble *listaCircularDoble);

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

    void recorrerMisActivosRentados();

    std::string generarAlfanumerico();

    std::string obtenerFecha();
};

#endif //CLIENTE_H
