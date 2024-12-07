//
// Created by herberthreyes on 7/12/24.
//

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"

class Administrador {
    Usuario *usuario;

public:
    Administrador(Usuario *usuario);
    Administrador();
    ~Administrador();

    Usuario *getUsuario();
    void setUsuario(Usuario *usuario);

    void menu();
    void registrarUsuario();
    void reporteMatrizDispersa();
    void reporteActivosDisponiblesDepartamento();
    void reporteActivosDisponiblesEmpresa();
    void reporteTransacciones();
    void reporteActivosUsuario();
    void activosRentadosUsuario();
    void ordenarTransacciones();


};

#endif //ADMINISTRADOR_H
