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
    std::string departamento;
    std::string empresa;
    //arbolAVL activos;

    public:
    Usuario(std::string username, std::string password, std::string departamento, std::string empresa);
    Usuario();
    ~Usuario();

    std::string getUsername();
    std::string getPassword();
    std::string getDepartamento();
    std::string getEmpresa();

    void setUsersname(std::string username);
    void setPassword(std::string password);
    void setDepartamento(std::string departamento);
    void setEmpresa(std::string empresa);

};

#endif //USUARIO_H
