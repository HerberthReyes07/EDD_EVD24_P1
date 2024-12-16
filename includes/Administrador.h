//
// Created by herberthreyes on 7/12/24.
//

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "listaCircularDoblementeEnlazada/ListaCircularDoble.h"
#include "matrizDispersa/MatrizDispersa.h"

class Administrador {
private:
    MatrizDispersa *matriz;
    ListaCircularDoble *listaCircularDoble;

    void verUsuarios();

public:
    Administrador();

    ~Administrador();

    Administrador(MatrizDispersa *matriz, ListaCircularDoble *listaCircularDoble);

    MatrizDispersa *getMatriz();

    void setMatriz(MatrizDispersa *matriz);

    void menu();

    void registrarUsuario();

    void reporteMatrizDispersa();

    void reporteActivosDisponiblesDepartamento();

    void reporteActivosDisponiblesEmpresa();

    void reporteTransacciones(ListaCircularDoble *lcde, std::string nombre, int orden);

    void reporteActivosUsuario();

    void activosRentadosUsuario();

    void ordenarTransacciones(std::string nombreOrden, int orden);

    bool insertarAtras(std::string username);

    void graficar(std::string path, std::string grafico);
};

#endif //ADMINISTRADOR_H
