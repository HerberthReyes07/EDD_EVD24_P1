//
// Created by herberthreyes on 7/12/24.
//

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

#include "arbolAVL/ArbolAVL.h"

class Usuario {
private:
    std::string username;
    std::string password;
    std::string nombre;
    std::string departamento;
    std::string empresa;
    ArbolAVL *activos;

public:
    Usuario();

    ~Usuario();

    Usuario(std::string username, std::string password, std::string nombre, std::string departamento, std::string empresa);

    std::string getUsername();

    std::string getPassword();

    std::string getNombre();

    std::string getDepartamento();

    std::string getEmpresa();

    ArbolAVL *getActivos();

    void setUsersname(std::string username);

    void setPassword(std::string password);

    void setNombre(std::string nombre);

    void setDepartamento(std::string departamento);

    void setEmpresa(std::string empresa);

    void setActivos(ArbolAVL *activos);
};

#endif //USUARIO_H
