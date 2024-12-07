//
// Created by herberthreyes on 7/12/24.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"

class Cliente {
    Usuario *usuario;

    public:
    Cliente(Usuario *usuario);
    Cliente();
    ~Cliente();

    Usuario *getUsuario();
    void setUsuario(Usuario *usuario);

    void menu();
    void agregarActivo();
    void eliminarActivo();
    void modificarActivo();
    void rentarActivo();
    void activosRentados();
    void misActivosRentados();

};

#endif //CLIENTE_H
