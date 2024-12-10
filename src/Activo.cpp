//
// Created by herberthreyes on 7/12/24.
//
#include "../includes/Activo.h";

Activo::Activo() {
};

Activo::~Activo() {
};

Activo::Activo(std::string id, std::string nombre, std::string descripcion) {
    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
}

std::string Activo::getId() {
    return this->id;
}

std::string Activo::getNombre() {
    return this->nombre;
}

std::string Activo::getDescripcion() {
    return this->descripcion;
}

void Activo::setId(std::string id) {
    this->id = id;
}

void Activo::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Activo::setDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}
