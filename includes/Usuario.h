//
// Created by herberthreyes on 7/12/24.
//

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario {
private:
    std::string username;
    std::string password;
    std::string nombre;
    std::string departamento;
    std::string empresa;
    //arbolAVL activos;

public:
    Usuario();

    ~Usuario();

    Usuario(std::string username, std::string password, std::string nombre, std::string departamento, std::string empresa);

    std::string getUsername();

    std::string getPassword();

    std::string getNombre();

    std::string getDepartamento();

    std::string getEmpresa();

    void setUsersname(std::string username);

    void setPassword(std::string password);

    void setNombre(std::string nombre);

    void setDepartamento(std::string departamento);

    void setEmpresa(std::string empresa);
};

#endif //USUARIO_H
