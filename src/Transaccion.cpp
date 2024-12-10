//
// Created by herberthreyes on 7/12/24.
//
#include "../includes/Transaccion.h"

Transaccion::Transaccion() {
};

Transaccion::~Transaccion() {
};

Transaccion::Transaccion(std::string id, int tiempoRenta, Usuario *usuario, Activo *activo) {
    this->id = id;
    this->tiempoRenta = tiempoRenta;
    this->usuario = usuario;
    this->activo = activo;
}

std::string Transaccion::getId() {
    return this->id;
}

int Transaccion::getTiempoRenta() {
    return this->tiempoRenta;
}

Usuario *Transaccion::getUsuario() {
    return this->usuario;
}

Activo *Transaccion::getActivo() {
    return this->activo;
}

void Transaccion::setId(std::string id) {
    this->id = id;
}

void Transaccion::setTiempoRenta(int tiempoRenta) {
    this->tiempoRenta = tiempoRenta;
}

void Transaccion::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Transaccion::setActivo(Activo *activo) {
    this->activo = activo;
}
