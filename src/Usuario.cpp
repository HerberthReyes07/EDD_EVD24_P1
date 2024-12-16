//
// Created by herberthreyes on 7/12/24.
//

#include "../includes/Usuario.h"

Usuario::Usuario() {
};

Usuario::~Usuario() {
};

Usuario::Usuario(std::string username, std::string password, std::string nombre, std::string departamento,
                 std::string empresa) {
    this->username = username;
    this->password = password;
    this->nombre = nombre;
    this->departamento = departamento;
    this->empresa = empresa;
}

std::string Usuario::getUsername() {
    return this->username;
}

std::string Usuario::getPassword() {
    return this->password;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

std::string Usuario::getDepartamento() {
    return this->departamento;
}

std::string Usuario::getEmpresa() {
    return this->empresa;
}

ArbolAVL *Usuario::getActivos() {
    return this->activos;
}

void Usuario::setUsersname(std::string username) {
    this->username = username;
}

void Usuario::setPassword(std::string password) {
    this->password = password;
}

void Usuario::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Usuario::setDepartamento(std::string departamento) {
    this->departamento = departamento;
}

void Usuario::setEmpresa(std::string empresa) {
    this->empresa = empresa;
}

void Usuario::setActivos(ArbolAVL *activos) {
    this->activos = activos;
}
